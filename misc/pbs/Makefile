# New ports collection makefile for:	PBS (Portable Batch Scheduler)
# Date created:				13 Jun 1999
# Whom:					David A. Bader <dbader@eece.unm.edu>
#
# $FreeBSD$
#

PORTNAME=	pbs
PORTVERSION=	2.2p11
CATEGORIES=	misc parallel
MASTER_SITES=	http://vaccine.sourceforge.net/
DISTNAME=	pbs_v2.2p11

MAINTAINER=	dbader@eece.unm.edu
COMMENT=	Batch job queueing system

LIB_DEPENDS=	tcl80.1:${PORTSDIR}/lang/tcl80 \
		tk80.1:${PORTSDIR}/x11-toolkits/tk80

WRKSRC=		${WRKDIR}/${DISTNAME}
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--set-server-home=/var/spool/pbs --enable-docs

MAN1=	xpbsmon.1B xpbs.1B basl2c.1B qsig.1B pbsdsh.1B qstat.1B nqs2pbs.1B \
	qsub.1B pbs.1B qselect.1B qorder.1B qalter.1B qdel.1B qhold.1B \
	qmove.1B qrerun.1B qmsg.1B qrls.1B

MAN3=	pbs_submit.3B pbs_sigjob.3B pbs_runjob.3B rpp.3B tm.3B \
	pbs_selectjob.3B pbs_stagein.3B pbs_statjob.3B pbs_statque.3B \
	pbs_statserver.3B pbs_terminate.3B pbs_orderjob.3B pbs_rerunjob.3B \
	pbs_rescquery.3B pbs_movejob.3B pbs_rlsjob.3B pbs_manager.3B \
	pbs_holdjob.3B pbs_geterrmsg.3B pbs_msgjob.3B pbs_rescreserve.3B \
	pbs_alterjob.3B pbs_disconnect.3B pbs_default.3B pbs_deljob.3B \
	pbs_connect.3B

MAN7=	pbs_resources_unicosmk2.7B pbs_resources_irix6array.7B \
	pbs_resources_irix6.7B pbs_resources_linux.7B pbs_resources_netbsd.7B \
	pbs_resources_solaris5.7B pbs_resources_sp2.7B pbs_resources_sunos4.7B \
	pbs_resources_unicos8.7B pbs_resources.7B pbs_job_attributes.7B \
	pbs_queue_attributes.7B pbs_server_attributes.7B pbs_resources_all.soB \
	pbs_resources_aix4.7B pbs_resources_digitalunix.7B \
	pbs_resources_freebsd.7B pbs_resources_fujitsu.7B pbs_resources_irix5.7B

MAN8=	qstart.8B qterm.8B pbs_sched_tcl.8B pbs_sched_basl.8B pbs_sched_cc.8B \
	pbsnodes.8B qstop.8B pbs_server.8B qmgr.8B qrun.8B qdisable.8B \
	qenable.8B pbs_mom.8B

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not build"
.endif

.include <bsd.port.post.mk>
