# New ports collection makefile for:	pvm3
# Date created:				11 March 1999
# Whom:					Dima Sivachenko <dima@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	pvm
PORTVERSION=	3.4.3
CATEGORIES=	net
MASTER_SITES=	http://www.netlib.org/pvm3/	\
		ftp://ftp.chg.ru/pub/prog/parallel/pvm/pvm3/
DISTNAME=	pvm3.4.3
EXTRACT_SUFX=	.tgz

MAINTAINER=	demon@FreeBSD.org

USE_XLIB=	yes

WRKSRC=		${WRKDIR}/pvm3
MAKE_ENV+=	PVM_ROOT=${WRKSRC} ARCHCFLAGS="${CFLAGS}"
MAKE_FLAGS+=	F77=/usr/bin/f77
ALL_TARGET=	all install
PVM_ROOT=	${PREFIX}/lib/pvm

MAN1=		PVM.1 aimk.1 pvm.1 pvm_intro.1 pvm_shmd.1 pvmd.1 pvmd3.1
MAN3=		libfpvm.3 libpvm.3 pvm_addhosts.3 pvm_addmhf.3 pvm_advise.3 \
		pvm_archcode.3 pvm_barrier.3 pvm_bcast.3 pvm_bufinfo.3 \
		pvm_catchout.3 pvm_config.3 pvm_delete.3 pvm_delhosts.3 \
		pvm_delinfo.3 pvm_delmhf.3 pvm_exit.3 pvm_export.3 \
		pvm_freebuf.3 pvm_freecontext.3 pvm_freezegroup.3 pvm_gather.3 \
		pvm_getcontext.3 pvm_getfds.3 pvm_getinst.3 pvm_getmboxinfo.3 \
		pvm_getmwid.3 pvm_getopt.3 pvm_getrbuf.3 pvm_getsbuf.3 \
		pvm_gettid.3 pvm_gettmask.3 pvm_gsize.3 pvm_halt.3 \
		pvm_hostsync.3 pvm_initsend.3 pvm_insert.3 pvm_joingroup.3 \
		pvm_kill.3 pvm_lookup.3 pvm_lvgroup.3 pvm_mcast.3 pvm_mkbuf.3 \
		pvm_mstat.3 pvm_mytid.3 pvm_newcontext.3 pvm_notify.3 \
		pvm_nrecv.3 pvm_pack.3 pvm_packf.3 pvm_parent.3 pvm_perror.3 \
		pvm_pkbyte.3 pvm_pkcplx.3 pvm_pkdcplx.3 pvm_pkdouble.3 \
		pvm_pkfloat.3 pvm_pkint.3 pvm_pklong.3 pvm_pkmesg.3 \
		pvm_pkmesgbody.3 pvm_pkshort.3 pvm_pkstr.3 pvm_pkuint.3 \
		pvm_pkulong.3 pvm_pkushort.3 pvm_precv.3 pvm_probe.3 \
		pvm_psend.3 pvm_pstat.3 pvm_putinfo.3 pvm_recv.3 pvm_recvf.3 \
		pvm_recvinfo.3 pvm_reduce.3 pvm_reg_hoster.3 pvm_reg_rm.3 \
		pvm_reg_tasker.3 pvm_scatter.3 pvm_send.3 pvm_sendsig.3 \
		pvm_serror.3 pvm_setcontext.3 pvm_setmwid.3 pvm_setopt.3 \
		pvm_setrbuf.3 pvm_setsbuf.3 pvm_settmask.3 pvm_siblings.3 \
		pvm_spawn.3 pvm_start_pvmd.3 pvm_tasks.3 pvm_tidtohost.3 \
		pvm_trecv.3 pvm_unexport.3 pvm_unpack.3 pvm_unpackf.3 \
		pvm_upkbyte.3 pvm_upkcplx.3 pvm_upkdcplx.3 pvm_upkdouble.3 \
		pvm_upkfloat.3 pvm_upkint.3 pvm_upklong.3 pvm_upkmesg.3 \
		pvm_upkshort.3 pvm_upkstr.3  pvm_upkuint.3 pvm_upkulong.3 \
		pvm_upkushort.3 pvmfaddhost.3 pvmfaddmhf.3 pvmfadvise.3 \
		pvmfarchcode.3 pvmfbarrier.3 pvmfbcast.3 pvmfbufinfo.3 \
		pvmfcatchout.3 pvmfconfig.3 pvmfdelhost.3 pvmfdelinfo.3 \
		pvmfdelmhf.3 pvmfexit.3 pvmffreebuf.3 pvmffreecontext.3 \
		pvmffrzgrp.3 pvmfgather.3 pvmfgetcontext.3 pvmfgetinst.3 \
		pvmfgetmboxinfo.3 pvmfgetopt.3 pvmfgetrbuf.3 pvmfgetsbuf.3 \
		pvmfgettid.3 pvmfgsize.3 pvmfhalt.3 pvmfhostsync.3 \
		pvmfinitsend.3 pvmfjoingrp.3 pvmfkill.3 pvmflvgrp.3 pvmfmcast.3\
		pvmfmkbuf.3 pvmfmstat.3 pvmfmytid.3 pvmfnewcontext.3 \
		pvmfnotify.3 pvmfnrecv.3 pvmfpack.3 pvmfparent.3 pvmfperror.3 \
		pvmfpkmesg.3 pvmfpkmesgbody.3 pvmfprecv.3 pvmfprobe.3 \
		pvmfpsend.3 pvmfpstat.3 pvmfputinfo.3 pvmfrecv.3 pvmfrecvinfo.3\
		pvmfreduce.3 pvmfscatter.3 pvmfsend.3 pvmfsendsig.3 \
		pvmfserror.3 pvmfsetcontext.3 pvmfsetopt.3 pvmfsetrbuf.3 \
		pvmfsetsbuf.3 pvmfsiblings.3 pvmfspawn.3 pvmfstartpvmd.3 \
		pvmftasks.3 pvmftidtoh.3 pvmftrecv.3 pvmfunpack.3 pvmfupkmesg.3

do-install:
	@ ${MKDIR} ${PVM_ROOT}/lib/FREEBSD ${PVM_ROOT}/bin/FREEBSD ${PVM_ROOT}/conf
	@ ${INSTALL_PROGRAM} ${WRKSRC}/bin/FREEBSD/* ${PVM_ROOT}/bin/FREEBSD
	@ ${INSTALL_PROGRAM} ${WRKSRC}/lib/FREEBSD/pvmd3 ${PVM_ROOT}/lib/FREEBSD
	@ ${INSTALL_PROGRAM} ${WRKSRC}/lib/FREEBSD/pvm ${PVM_ROOT}/lib/FREEBSD
	@ ${INSTALL_SCRIPT} ${WRKSRC}/lib/pvm ${PVM_ROOT}/lib
	@ ${INSTALL_SCRIPT} ${WRKSRC}/lib/pvmd ${PVM_ROOT}/lib
	@ ${INSTALL_SCRIPT} ${WRKSRC}/lib/pvmgetarch ${PVM_ROOT}/lib
	@ ${INSTALL_SCRIPT} ${WRKSRC}/lib/aimk ${PVM_ROOT}/lib
	@ ${LN} -sf ${PVM_ROOT}/lib/pvm ${PREFIX}/bin/pvm
	@ ${LN} -sf ${PVM_ROOT}/lib/pvmd ${PREFIX}/bin/pvmd
	@ ${LN} -sf ${PVM_ROOT}/lib/aimk ${PREFIX}/bin/aimk
	@ ${INSTALL_DATA} ${WRKSRC}/lib/FREEBSD/libpvm3.a ${PREFIX}/lib
	@ ${INSTALL_DATA} ${WRKSRC}/lib/FREEBSD/libfpvm3.a ${PREFIX}/lib
	@ ${INSTALL_DATA} ${WRKSRC}/lib/FREEBSD/libgpvm3.a ${PREFIX}/lib
	@ ${INSTALL_DATA} ${WRKSRC}/lib/FREEBSD/libpvmtrc.a ${PREFIX}/lib
	@ ${INSTALL_DATA} ${WRKSRC}/conf/FREEBSD.def ${PVM_ROOT}/conf
	@ ${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include
	@ ${INSTALL_MAN} ${WRKSRC}/man/man1/* ${PREFIX}/man/man1
	@ ${INSTALL_MAN} ${WRKSRC}/man/man3/* ${PREFIX}/man/man3

post-install:
	@ ${ECHO_MSG}
	@ ${ECHO_MSG} "You have to set PVM_ROOT=${PVM_ROOT} enviropment variable on all machines"
	@ ${ECHO_MSG} "which you are planning to use for distributed computing. The best way to set"
	@ ${ECHO_MSG} "this variable on system-wide basis is to add \"PVM_ROOT=${PVM_ROOT}\" into"
	@ ${ECHO_MSG} "appropriate section of your /etc/login.conf file. You also have to enable"
	@ ${ECHO_MSG} "rshd on those machines."
	@ ${ECHO_MSG}

.include <bsd.port.mk>
