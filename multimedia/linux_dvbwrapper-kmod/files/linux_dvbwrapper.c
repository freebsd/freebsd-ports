/*-
 * Copyright (c) 2011 Juergen Lock
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include <sys/param.h>
#include <sys/systm.h>
#include <sys/conf.h>
#include <sys/kernel.h>
#include <sys/module.h>
#include <sys/file.h>
#include <sys/proc.h>
#include <sys/ioccom.h>
#include <sys/sysproto.h>
#include <sys/mman.h>
#include <sys/resourcevar.h>

#if __FreeBSD_version > 900040
#include <sys/capability.h>
#endif

#include <vm/vm.h>
#include <vm/pmap.h>
#include <vm/vm_extern.h>
#include <vm/vm_map.h>

#ifdef COMPAT_LINUX32
#include <machine/../linux32/linux.h>
#include <machine/../linux32/linux32_proto.h>
#else
#include <machine/../linux/linux.h>
#include <machine/../linux/linux_proto.h>
#endif
#include <compat/linux/linux_ioctl.h>
#include <compat/linux/linux_util.h>

#include "linux_dvb_ioctl.h"
#include "linux_dvb.h"
#include "linux_dvb_compat.h"

static linux_ioctl_function_t linux_ioctl_dvb;
static struct linux_ioctl_handler dvb_handler =
{ linux_ioctl_dvb, LINUX_IOCTL_DVB_MIN, LINUX_IOCTL_DVB_MAX };

SYSINIT  (dvbwrapper_register,   SI_SUB_KLD, SI_ORDER_MIDDLE,
	  linux_ioctl_register_handler, &dvb_handler);
SYSUNINIT(dvbwrapper_unregister, SI_SUB_KLD, SI_ORDER_MIDDLE,
	  linux_ioctl_unregister_handler, &dvb_handler);

static MALLOC_DEFINE(M_LINUX_DVB, "linux_dvbwrapper", "Linux DVB wrapper");

static int
linux_dvbwrapper_modevent(module_t mod, int cmd, void *data)
{
	return (0);
}

DEV_MODULE(linux_dvbwrapper, linux_dvbwrapper_modevent, NULL);
MODULE_DEPEND(linux_dvbwrapper, linux, 1, 1, 1);

#if ((__FreeBSD_version >= 900000) && (__FreeBSD_version < 900035)) || \
    (__FreeBSD_version < 802503)
/*
 * Map some anonymous memory in user space of size sz, rounded up to the page
 * boundary.
 */
int
copyout_map(struct thread *td, vm_offset_t *addr, size_t sz)
{
	struct vmspace *vms;
	int error;
	vm_size_t size;

	vms = td->td_proc->p_vmspace;

	/*
	 * Map somewhere after heap in process memory.
	 */
	PROC_LOCK(td->td_proc);
	*addr = round_page((vm_offset_t)vms->vm_daddr +
	    lim_max(td->td_proc, RLIMIT_DATA));
	PROC_UNLOCK(td->td_proc);

	/* round size up to page boundry */
	size = (vm_size_t)round_page(sz);

	error = vm_mmap(&vms->vm_map, addr, size, PROT_READ | PROT_WRITE,
	    VM_PROT_ALL, MAP_PRIVATE | MAP_ANON, OBJT_DEFAULT, NULL, 0);

	return (error);
}

/*
 * Unmap memory in user space.
 */
int
copyout_unmap(struct thread *td, vm_offset_t addr, size_t sz)
{
	vm_map_t map;
	vm_size_t size;

	if (sz == 0)
		return (0);

	map = &td->td_proc->p_vmspace->vm_map;
	size = (vm_size_t)round_page(sz);

	if (vm_map_remove(map, addr, addr + size) != KERN_SUCCESS)
		return (EINVAL);

	return (0);
}
#endif

static int
linux_to_bsd_dtv_properties(struct l_dtv_properties *lvps, struct dtv_properties *vps)
{

	vps->num = lvps->num;
	vps->props = PTRIN(lvps->props);	/* possible pointer size conversion */
	return (0);
}

static int
linux_to_bsd_dtv_property(struct l_dtv_property *lvp, struct dtv_property *vp)
{

	/*
	 * Everything until u.buffer.reserved2 is fixed size so
	 * just memcpy it.
	 */
	memcpy(vp, lvp, offsetof(struct l_dtv_property, u.buffer.reserved2));
	/*
	 * The pointer may be garbage since it's part of a union,
	 * currently no Linux code uses it so just set it to NULL.
	 */
	vp->u.buffer.reserved2 = NULL;
	vp->result = lvp->result;
	return (0);
}

static int
bsd_to_linux_dtv_property(struct dtv_property *vp, struct l_dtv_property *lvp)
{

	/*
	 * Everything until u.buffer.reserved2 is fixed size so
	 * just memcpy it.
	 */
	memcpy(lvp, vp, offsetof(struct l_dtv_property, u.buffer.reserved2));
	/*
	 * The pointer may be garbage since it's part of a union,
	 * currently no Linux code uses it so just set it to NULL.
	 */
	lvp->u.buffer.reserved2 = PTROUT(NULL);
	lvp->result = vp->result;
	return (0);
}

static int
linux_ioctl_dvb(struct thread *td, struct linux_ioctl_args *args)
{
	struct file *fp;
	int error, i;
	struct l_dtv_properties l_vps;
	struct dtv_properties vps;
	struct l_dtv_property *l_vp, *l_p;
	struct dtv_property *vp, *p;
	size_t l_propsiz, propsiz;
	vm_offset_t uvp;
#if __FreeBSD_version > 1000051
	cap_rights_t rights;
#endif

	l_vp = NULL;
	vp = NULL;

	switch (args->cmd & 0xffff) {
	case LINUX_AUDIO_STOP:
	case LINUX_AUDIO_PLAY:
	case LINUX_AUDIO_PAUSE:
	case LINUX_AUDIO_CONTINUE:
	case LINUX_AUDIO_SELECT_SOURCE:
	case LINUX_AUDIO_SET_MUTE:
	case LINUX_AUDIO_SET_AV_SYNC:
	case LINUX_AUDIO_SET_BYPASS_MODE:
	case LINUX_AUDIO_CHANNEL_SELECT:
	case LINUX_AUDIO_CLEAR_BUFFER:
	case LINUX_AUDIO_SET_ID:
	case LINUX_AUDIO_SET_STREAMTYPE:
	case LINUX_AUDIO_SET_EXT_ID:
	case LINUX_AUDIO_BILINGUAL_CHANNEL_SELECT:
	case LINUX_DMX_START:
	case LINUX_DMX_STOP:
	case LINUX_DMX_SET_BUFFER_SIZE:
	case LINUX_NET_REMOVE_IF:
	case LINUX_FE_DISEQC_RESET_OVERLOAD:
	case LINUX_FE_DISEQC_SEND_BURST:
	case LINUX_FE_SET_TONE:
	case LINUX_FE_SET_VOLTAGE:
	case LINUX_FE_ENABLE_HIGH_LNB_VOLTAGE:
	case LINUX_FE_DISHNETWORK_SEND_LEGACY_CMD:
	case LINUX_FE_SET_FRONTEND_TUNE_MODE:
	case LINUX_CA_RESET:
		if ((args->cmd & IOC_DIRMASK) != LINUX_IOC_VOID)
			return ENOIOCTL;
		args->cmd = (args->cmd & 0xffff) | IOC_VOID;
		break;

	case LINUX_DMX_REMOVE_PID:
		/* overlaps with LINUX_NET_ADD_IF */
		if ((args->cmd & IOC_DIRMASK) == LINUX_IOC_INOUT)
			goto net_add_if;
		/* FALLTHRU */
	case LINUX_AUDIO_SET_MIXER:
	case LINUX_AUDIO_SET_ATTRIBUTES:
	case LINUX_AUDIO_SET_KARAOKE:
	case LINUX_DMX_SET_FILTER:
	case LINUX_DMX_SET_PES_FILTER:
	case LINUX_DMX_SET_SOURCE:
	case LINUX_DMX_ADD_PID:
	case LINUX_FE_DISEQC_SEND_MASTER_CMD:
	case LINUX_FE_SET_FRONTEND:
	case LINUX_CA_SEND_MSG:
	case LINUX_CA_SET_DESCR:
	case LINUX_CA_SET_PID:
		args->cmd = (args->cmd & ~IOC_DIRMASK) | IOC_IN;
		break;

	case LINUX_AUDIO_GET_STATUS:
	case LINUX_AUDIO_GET_CAPABILITIES:
	case LINUX_AUDIO_GET_PTS:
	case LINUX_DMX_GET_PES_PIDS:
	case LINUX_DMX_GET_CAPS:
	case LINUX_FE_GET_INFO:
	case LINUX_FE_DISEQC_RECV_SLAVE_REPLY:
	case LINUX_FE_READ_STATUS:
	case LINUX_FE_READ_BER:
	case LINUX_FE_READ_SIGNAL_STRENGTH:
	case LINUX_FE_READ_SNR:
	case LINUX_FE_READ_UNCORRECTED_BLOCKS:
	case LINUX_FE_GET_FRONTEND:
	case LINUX_FE_GET_EVENT:
	case LINUX_CA_GET_CAP:
	case LINUX_CA_GET_DESCR_INFO:
		args->cmd = (args->cmd & ~IOC_DIRMASK) | IOC_OUT;
		break;

	case LINUX_DMX_GET_STC:
	case LINUX_CA_GET_SLOT_INFO:
	case LINUX_CA_GET_MSG:
	case LINUX_NET_GET_IF:
	net_add_if:
		args->cmd = (args->cmd & ~IOC_DIRMASK) | IOC_INOUT;
		break;

	case LINUX_FE_SET_PROPERTY:
	case LINUX_FE_GET_PROPERTY:
		error = copyin((void *)args->arg, &l_vps, sizeof(l_vps));
		if (error)
			return (error);
		linux_to_bsd_dtv_properties(&l_vps, &vps);
		if ((vps.num == 0) || vps.num > DTV_IOCTL_MAX_MSGS)
			return EINVAL;

		l_propsiz = vps.num * sizeof(*l_vp);
		propsiz = vps.num * sizeof(*vp);
		l_vp = malloc(l_propsiz, M_LINUX_DVB, M_WAITOK);
		vp = malloc(propsiz, M_LINUX_DVB, M_WAITOK);
		error = copyin((void *)vps.props, l_vp, l_propsiz);
		if (error)
			goto out2;
		for (i = vps.num, l_p = l_vp, p = vp; i--; ++l_p, ++p)
			linux_to_bsd_dtv_property(l_p, p);

		error = copyout_map(td, &uvp, propsiz);
		if (error)
			goto out2;
		copyout(vp, (void *)uvp, propsiz);

#if __FreeBSD_version > 1000051
		error = fget(td, args->fd,
				cap_rights_init(&rights, CAP_IOCTL), &fp);
		if (error != 0)
#elif __FreeBSD_version > 900040
		if ((error = fget(td, args->fd, CAP_IOCTL, &fp)) != 0)
#else
		if ((error = fget(td, args->fd, &fp)) != 0)
#endif
		{
			(void)copyout_unmap(td, uvp, propsiz);
			goto out2;
		}
		vps.props = (void *)uvp;
		if ((args->cmd & 0xffff) == LINUX_FE_SET_PROPERTY)
			error = fo_ioctl(fp, FE_SET_PROPERTY, &vps, td->td_ucred, td);
		else
			error = fo_ioctl(fp, FE_GET_PROPERTY, &vps, td->td_ucred, td);
		if (error) {
			(void)copyout_unmap(td, uvp, propsiz);
			goto out;
		}
		error = copyin((void *)uvp, vp, propsiz);
		(void)copyout_unmap(td, uvp, propsiz);
		if (error)
			goto out;
		for (i = vps.num, l_p = l_vp, p = vp; i--; ++l_p, ++p)
			bsd_to_linux_dtv_property(p, l_p);
		linux_to_bsd_dtv_properties(&l_vps, &vps);
		copyout(l_vp, (void *)vps.props, l_propsiz);

	out:
		fdrop(fp, td);
	out2:
		if (l_vp)
			free(l_vp, M_LINUX_DVB);
		if (vp)
			free(vp, M_LINUX_DVB);
		return (error);

	default:			return (ENOIOCTL);
	}

/* actually r225618 but __FreeBSD_version wasn't bumped */
#if __FreeBSD_version > 900043
	error = sys_ioctl(td, (struct ioctl_args *)args);
#else
	error = ioctl(td, (struct ioctl_args *)args);
#endif
	return (error);
}
