# New ports collection makefile for:    networker-client602
# Date created:         Sat Oct 27 09:48:19 PDT 2001
# Whom:                 Matthew Jacob <mjacob@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	nwclient
PORTVERSION=	6.0.2
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
DISTNAME=	nwclient-${PORTVERSION}-freebsd-${ARCH}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network backup client to NetWorker servers

LATEST_LINK=	nwclient602

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
LIB_DEPENDS=	c.4:${PORTSDIR}/misc/compat4x
.endif

NO_BUILD=	yes
ONLY_FOR_ARCHS=	alpha i386

MAN1=		rapgen.1
MAN3=		nsr_getdate.3
MAN5=		mm_data.5 nsr.5 nsr_archive_request.5 nsr_client.5 nsr_data.5 \
		nsr_device.5 nsr_directive.5 nsr_group.5 nsr_jukebox.5 \
		nsr_label.5 nsr_layout.5 nsr_license.5 nsr_migration.5 \
		nsr_notification.5 nsr_policy.5 nsr_pool.5 nsr_regexp.5 \
		nsr_resource.5 nsr_schedule.5 nsr_service.5 nsr_stage.5 \
		nsr_storage_node.5 resource.5
MAN8=		ansrd.8 changers.8 dasadmin.8 EMASS_silo.8 emcdiscover.8 \
		erase.8 hpflip.8 IBM_silo.8 ielem.8 inquire.8 jbconfig.8 \
		jbexercise.8 jbinfo.8 ldunld.8 lgtolic.8 lgtolmd.8 libscsi.8 \
		libsji.8 libstlemass.8 libstlibm.8 libstlstk.8 lrescan.8 \
		lusbinfo.8 lusdebug.8 lusmode.8 mini_el.8 mminfo.8 mmlocate.8\
		mmpool.8 mmrecov.8 msense.8 networker.8 nmi_config.8 nsr.8 \
		nsr_crash.8 nsr_ize.8 nsr_shutdown.8 nsradmin.8 nsralist.8 \
 		nsrarchive.8 nsrcap.8 nsrcat.8 nsrck.8 nsrclone.8 nsrd.8 \
		nsrdb2.8 nsrdbmi.8 nsrdocrc.8 nsrexec.8 nsrexecd.8 nsrhsmck.8 \
		nsrhsmls.8 nsrib.8 nsriba.8 nsrim.8 nsrindexasm.8 nsrindexd.8 \
		nsrinfo.8 nsrjb.8 nsrlic.8 nsrls.8 nsrmig.8 nsrmm.8 nsrmmd.8 \
		nsrmmdbasm.8 nsrmmdbd.8 nsrmon.8 nsrndmp_recover.8 \
		nsrndmp_save.8 nsrnmo.8 nsrnotesrc.8 nsrnotesv.8 nsrpmig.8 \
		nsrports.8 nsrretrieve.8 nsrssc.8 nsrstage.8 nsrsyb.8 \
		nsrsybcc.8 nsrsybrc.8 nsrsybsv.8 nsrtrap.8 nsrwatch.8  \
		nwadmin.8 nwarchive.8 nwbackup.8 nwrecover.8 nwretrieve.8 \
		oraemcasm.8 oraemcmap.8 pmode.8 preclntsave.8 pstclntsave.8 \
		rap.8 rapcheck.8 rapd.8 rapxfer.8 recover.8 relem.8 \
		sapclone.8 save.8 savefs.8 savegrp.8 savepnpc.8 scanner.8 \
		sjidopen.8 sjiielm.8 sjiinq.8 sjirdp.8 sjirdtag.8 sjirelem.8 \
		sjirjc.8 ssi.8 stk_eject.8 STK_silo.8 stli.8 tapeexercise.8 \
		tur.8 uasm.8 writebuf.8 \
		lreset.8

post-patch:
	@${SED} -e "s,^ROOTDIR.*$$,ROOTDIR=${PREFIX}," ${WRKSRC}/networker.sh >\
		${WRKDIR}/NWCTMP && ${CHMOD} +w ${WRKSRC}/networker.sh && \
		${CP} ${WRKDIR}/NWCTMP ${WRKSRC}/networker.sh && \
		${CHMOD} -w ${WRKSRC}/networker.sh

do-install:
	@${MKDIR} ${PREFIX}/nsr/bin ${PREFIX}/man/man8 ${PREFIX}/etc/rc.d
	@cd ${WRKSRC} && ${TAR} cf - gls | \
		(cd ${PREFIX}/nsr && ${TAR} --unlink -xpf -)
	@cd ${WRKSRC}/${ARCH} && ${TAR} cf - . | \
		(cd ${PREFIX}/nsr/bin && ${TAR} --unlink -xpf -)
	@cd ${WRKSRC} && ${TAR} cf - networker.sh | \
		(cd ${PREFIX}/etc/rc.d  && ${TAR} --unlink -xpf -)
	@cd ${WRKSRC}/catman && ${TAR} cf - *.1 | \
		(cd ${PREFIX}/man/man1  && ${TAR} --unlink -xpf -)
	@cd ${WRKSRC}/catman && ${TAR} cf - *.3 | \
		(cd ${PREFIX}/man/man3  && ${TAR} --unlink -xpf -)
	@cd ${WRKSRC}/catman && ${TAR} cf - *.5 | \
		(cd ${PREFIX}/man/man5  && ${TAR} --unlink -xpf -)
	@cd ${WRKSRC}/catman && ${TAR} cf - *.8 | \
		(cd ${PREFIX}/man/man8  && ${TAR} --unlink -xpf -)

post-install:
	@${SED} -e "s,ROOTDIR,${PREFIX}," < ${PKGMESSAGE}
	@cd / && ${RM} -f nsr && ${LN} -s ${PREFIX}/nsr

pre-deinstall:
	${RM} -f /nsr

.include <bsd.port.post.mk>
