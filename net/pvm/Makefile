# Created by: Dima Sivachenko <dima@chg.ru>
# $FreeBSD$

PORTNAME=	pvm
PORTVERSION=	3.4.6
PORTREVISION=	2
CATEGORIES=	net parallel
MASTER_SITES=	NL ftp://ftp.chg.ru/pub/prog/parallel/pvm3/
MASTER_SITE_SUBDIR=	pvm3
DISTNAME=	pvm${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parallel Virtual Machine libraries and environment

.if defined(WITHOUT_X11)
PKGNAMESUFFIX=	-nox11
MAKE_ENV+=	WITHOUT_X11=yes
PLIST_SUB+=	X11='@comment '
.else
USE_XORG=	x11 xaw xt
PLIST_SUB+=	X11=''
.endif

USE_FORTRAN=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/pvm3
MAKE_ENV+=	PVM_ROOT=${WRKSRC} SHAREDLDFLAGS="-lgfortran -shared"
ALL_TARGET=	all shared install
PVM_ROOT=	${PREFIX}/lib/pvm
REINPLACE_ARGS=	-i ""
MAKE_JOBS_UNSAFE=yes

MAN1=		aimk.1 pvm.1 pvm_intro.1 pvm_shmd.1 pvmd3.1
MAN3=		libpvm.3 pvm_addhosts.3 pvm_addmhf.3 pvm_advise.3 \
		pvm_archcode.3 pvm_barrier.3 pvm_bcast.3 pvm_bufinfo.3 \
		pvm_catchout.3 pvm_config.3 pvm_delete.3 pvm_delhosts.3 \
		pvm_exit.3 pvm_export.3 pvm_freebuf.3 pvm_freezegroup.3 \
		pvm_gather.3 pvm_getfds.3 pvm_getinst.3 pvm_getopt.3 \
		pvm_getrbuf.3 pvm_getsbuf.3 pvm_gettid.3 pvm_gsize.3 \
		pvm_halt.3 pvm_hostsync.3 pvm_initsend.3 pvm_insert.3 \
		pvm_joingroup.3 pvm_kill.3 pvm_lookup.3 pvm_lvgroup.3 \
		pvm_mcast.3 pvm_mkbuf.3 pvm_mstat.3 pvm_mytid.3 \
		pvm_newcontext.3 pvm_notify.3 pvm_nrecv.3 pvm_pack.3 \
		pvm_parent.3 pvm_perror.3 pvm_pkmesg.3 pvm_precv.3 \
		pvm_probe.3 pvm_psend.3 pvm_pstat.3 pvm_putinfo.3 pvm_recv.3 \
		pvm_recvf.3 pvm_reduce.3 pvm_reg_hoster.3 pvm_reg_rm.3 \
		pvm_reg_tasker.3 pvm_scatter.3 pvm_send.3 pvm_sendsig.3 \
		pvm_serror.3 pvm_setmwid.3 pvm_setopt.3 pvm_setrbuf.3 \
		pvm_setsbuf.3 pvm_settmask.3 pvm_siblings.3 pvm_spawn.3 \
		pvm_start_pvmd.3 pvm_tasks.3 pvm_tidtohost.3 pvm_trecv.3 \
		pvm_unpack.3
MLINKS=		pvm_intro.1 PVM.1 pvmd3.1 pvmd.1 \
		libpvm.3 libfpvm.3 pvm_putinfo.3 pvm_delinfo.3 \
		pvm_addmhf.3 pvm_delmhf.3 pvm_newcontext.3 pvm_freecontext.3 \
		pvm_newcontext.3 pvm_getcontext.3 \
		pvm_putinfo.3 pvm_getmboxinfo.3 pvm_setmwid.3 pvm_getmwid.3 \
		pvm_settmask.3 pvm_gettmask.3 pvm_pack.3 pvm_packf.3 \
		pvm_pack.3 pvm_pkbyte.3 pvm_pack.3 pvm_pkcplx.3 \
		pvm_pack.3 pvm_pkdcplx.3 pvm_pack.3 pvm_pkdouble.3 \
		pvm_pack.3 pvm_pkfloat.3 pvm_pack.3 pvm_pkint.3 \
		pvm_pack.3 pvm_pklong.3 pvm_pkmesg.3 pvm_pkmesgbody.3 \
		pvm_pack.3 pvm_pkshort.3 pvm_pack.3 pvm_pkstr.3 \
		pvm_pack.3 pvm_pkuint.3 pvm_pack.3 pvm_pkulong.3 \
		pvm_pack.3 pvm_pkushort.3 pvm_putinfo.3 pvm_recvinfo.3 \
		pvm_newcontext.3 pvm_setcontext.3 pvm_export.3 pvm_unexport.3 \
		pvm_unpack.3 pvm_unpackf.3 pvm_unpack.3 pvm_upkbyte.3 \
		pvm_unpack.3 pvm_upkcplx.3 pvm_unpack.3 pvm_upkdcplx.3 \
		pvm_unpack.3 pvm_upkdouble.3 pvm_unpack.3 pvm_upkfloat.3 \
		pvm_unpack.3 pvm_upkint.3 pvm_unpack.3 pvm_upklong.3 \
		pvm_pkmesg.3 pvm_upkmesg.3 pvm_unpack.3 pvm_upkshort.3 \
		pvm_unpack.3 pvm_upkstr.3 pvm_unpack.3 pvm_upkuint.3 \
		pvm_unpack.3 pvm_upkulong.3 pvm_unpack.3 pvm_upkushort.3 \
		pvm_addhosts.3 pvmfaddhost.3 pvm_addmhf.3 pvmfaddmhf.3 \
		pvm_advise.3 pvmfadvise.3 pvm_archcode.3 pvmfarchcode.3 \
		pvm_barrier.3 pvmfbarrier.3 pvm_bcast.3 pvmfbcast.3 \
		pvm_bufinfo.3 pvmfbufinfo.3 pvm_catchout.3 pvmfcatchout.3 \
		pvm_config.3 pvmfconfig.3 pvm_delhosts.3 pvmfdelhost.3 \
		pvm_putinfo.3 pvmfdelinfo.3 pvm_addmhf.3 pvmfdelmhf.3 \
		pvm_exit.3 pvmfexit.3 pvm_freebuf.3 pvmffreebuf.3 \
		pvm_newcontext.3 pvmffreecontext.3 \
		pvm_freezegroup.3 pvmffrzgrp.3 pvm_gather.3 pvmfgather.3 \
		pvm_newcontext.3 pvmfgetcontext.3 \
		pvm_getinst.3 pvmfgetinst.3 pvm_putinfo.3 pvmfgetmboxinfo.3 \
		pvm_getopt.3 pvmfgetopt.3 pvm_getrbuf.3 pvmfgetrbuf.3 \
		pvm_getsbuf.3 pvmfgetsbuf.3 pvm_gettid.3 pvmfgettid.3 \
		pvm_gsize.3 pvmfgsize.3 pvm_halt.3 pvmfhalt.3 \
		pvm_hostsync.3 pvmfhostsync.3 pvm_initsend.3 pvmfinitsend.3 \
		pvm_joingroup.3 pvmfjoingrp.3 pvm_kill.3 pvmfkill.3 \
		pvm_lvgroup.3 pvmflvgrp.3 pvm_mcast.3 pvmfmcast.3 \
		pvm_mkbuf.3 pvmfmkbuf.3 pvm_mstat.3 pvmfmstat.3 \
		pvm_mytid.3 pvmfmytid.3 pvm_newcontext.3 pvmfnewcontext.3 \
		pvm_notify.3 pvmfnotify.3 pvm_nrecv.3 pvmfnrecv.3 \
		pvm_pack.3 pvmfpack.3 pvm_parent.3 pvmfparent.3 \
		pvm_perror.3 pvmfperror.3 pvm_pkmesg.3 pvmfpkmesg.3 \
		pvm_pkmesg.3 pvmfpkmesgbody.3 pvm_precv.3 pvmfprecv.3 \
		pvm_probe.3 pvmfprobe.3 pvm_psend.3 pvmfpsend.3 \
		pvm_pstat.3 pvmfpstat.3 pvm_putinfo.3 pvmfputinfo.3 \
		pvm_recv.3 pvmfrecv.3 pvm_putinfo.3 pvmfrecvinfo.3 \
		pvm_reduce.3 pvmfreduce.3 pvm_scatter.3 pvmfscatter.3 \
		pvm_send.3 pvmfsend.3 pvm_sendsig.3 pvmfsendsig.3 \
		pvm_serror.3 pvmfserror.3 pvm_newcontext.3 pvmfsetcontext.3 \
		pvm_setopt.3 pvmfsetopt.3 pvm_setrbuf.3 pvmfsetrbuf.3 \
		pvm_setsbuf.3 pvmfsetsbuf.3 pvm_siblings.3 pvmfsiblings.3 \
		pvm_spawn.3 pvmfspawn.3 pvm_start_pvmd.3 pvmfstartpvmd.3 \
		pvm_tasks.3 pvmftasks.3 pvm_tidtohost.3 pvmftidtoh.3 \
		pvm_trecv.3 pvmftrecv.3 pvm_unpack.3 pvmfunpack.3 \
		pvm_pkmesg.3 pvmfupkmesg.3

SUB_FILES=	pkg-message

NO_STAGE=	yes
.include <bsd.port.pre.mk>

NOT_FOR_ARCHS=	powerpc

pre-patch:
	@${REINPLACE_CMD} -e 's|$$(ARCHCFLAGS)|$$(ARCHCFLAGS) -fPIC|g' ${WRKSRC}/src/Makefile.aimk
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/tracer/tracer.h ${WRKSRC}/tracer/trclib.h \
		${WRKSRC}/tracer/trcsort.c
	${FIND} ${WRKSRC} -name Makefile.aimk | ${XARGS} ${REINPLACE_CMD} \
		-e 's,-[gO],,g' \
		-e 's,^\([CF]FL[A-Z]*[ 	]*\)=,\1+=,'

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
	@ ${INSTALL_DATA} ${WRKSRC}/lib/FREEBSD/libpvm3.so ${PREFIX}/lib
	@ ${INSTALL_DATA} ${WRKSRC}/lib/FREEBSD/libpvm3.so ${PREFIX}/lib/libpvm3.so.3
	@ ${INSTALL_DATA} ${WRKSRC}/lib/FREEBSD/libgpvm3.so ${PREFIX}/lib
	@ ${INSTALL_DATA} ${WRKSRC}/lib/FREEBSD/libgpvm3.so ${PREFIX}/lib/libgpvm3.so.3
	@ ${INSTALL_DATA} ${WRKSRC}/conf/FREEBSD.def ${PVM_ROOT}/conf
	@ ${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include
	cd ${WRKSRC}/man/man1 && ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1
	cd ${WRKSRC}/man/man3 && ${INSTALL_MAN} ${MAN3} ${PREFIX}/man/man3

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
