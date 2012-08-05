# New ports collection makefile for:	torque
# Date created:			20 Jul 2006
# Whom:				trasz
#
# $FreeBSD$
#

PORTNAME=	torque
PORTVERSION=	3.0.2
CATEGORIES=	sysutils parallel
MASTER_SITES=	http://www.clusterresources.com/downloads/torque/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Open source distributed computing resource manager based on PBS

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-rcp=scp
USE_GMAKE=	yes
USE_RC_SUBR=	pbs_server pbs_sched pbs_mom
SUB_FILES=	pkg-message
USE_PERL5=	yes
USE_LDCONFIG=	yes

MAN1=		qalter.1 qdel.1 qhold.1 qmove.1 qmsg.1 qorder.1 qrerun.1 \
		qrls.1 qselect.1 qsig.1 qstat.1 qsub.1 pbs.1 pbsdsh.1 \
		nqs2pbs.1 basl2c.1 xpbs.1 xpbsmon.1 qmgr.1 qchkpt.1 \
		qgpumode.1 qgpureset.1

MAN3=		rpp.3 tm.3 pbs_alterjob.3 pbs_connect.3 pbs_default.3 \
		pbs_deljob.3 pbs_disconnect.3 pbs_geterrmsg.3 pbs_holdjob.3 \
		pbs_locate.3 pbs_manager.3 pbs_movejob.3 pbs_msgjob.3 \
		pbs_orderjob.3 pbs_rerunjob.3 pbs_rescquery.3 \
		pbs_rescreserve.3 pbs_rlsjob.3 pbs_runjob.3 pbs_selectjob.3 \
		pbs_selstat.3 pbs_sigjob.3 pbs_stagein.3 pbs_statjob.3 \
		pbs_statnode.3 pbs_statque.3 pbs_statserver.3 pbs_submit.3 \
		pbs_terminate.3 pbs_checkpointjob.3 pbs_fbserver.3 \
		pbs_get_server_list.3 pbs_gpumode.3 pbs_gpureset.3

MAN7=		pbs_job_attributes.7 pbs_queue_attributes.7 \
		pbs_server_attributes.7 pbs_resources_aix4.7 \
		pbs_resources_digitalunix.7 pbs_resources_aix5.7 \
		pbs_resources_darwin.7 pbs_resources_freebsd.7 \
		pbs_resources_fujitsu.7 pbs_resources_hpux10.7 \
		pbs_resources_hpux11.7 pbs_resources_irix5.7 \
		pbs_resources_irix6.7 pbs_resources_irix6array.7 \
		pbs_resources_linux.7 pbs_resources_netbsd.7 \
		pbs_resources_solaris5.7 pbs_resources_solaris7.7 \
		pbs_resources_sp2.7 pbs_resources_sunos4.7 \
		pbs_resources_unicos8.7 pbs_resources_unicosmk2.7

MAN8=		pbs_mom.8 pbsnodes.8 pbs_sched_basl.8 pbs_sched_cc.8 \
		pbs_sched_tcl.8 pbs_server.8 qdisable.8 qenable.8 \
		qrun.8 qstart.8 qstop.8 qterm.8

MLINKS=		pbs_sched_cc.8 pbs_sched.8 \
		pbs_resources_freebsd.7 pbs_resources.7

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/torque.setup ${EXAMPLESDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
