# New ports collection makefile for:	condor
# Date created:			01 May 2007
# Whom:				Andy Pavlo
#
# $FreeBSD$
#

PORTNAME=	condor
PORTVERSION=	6.8.4
CATEGORIES=	sysutils parallel
MASTER_SITES=	http://www.cs.wisc.edu/condor/cgi-bin/downloads/sendfile.pl/${OSREL}/v6.8/
DISTNAME=	condor-${PORTVERSION}-freebsd6-x86-dynamic

MAINTAINER=	pavlo@cs.wisc.edu
COMMENT=	Condor High-Throughput Distributed Batch System

ONLY_FOR_ARCHS=	amd64 i386
WRKSRC=		${WRKDIR}/condor-${PORTVERSION}
OPTIONS=	SUBMIT_NODE "Configure system to be able to submit jobs" On \
		EXECUTE_NODE "Configure system to execute jobs in pool" On \
		MANAGER_NODE "Configure system as central manager node" On
USE_LDCONFIG=	yes
NO_BUILD=	yes
#NO_PACKAGE=	yes
USE_PERL5_BUILD=	yes

# We conflict with the developer series version of Condor
CONFLICTS=	condor-devel-[0-9]*

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING)
IGNORE=		requires fully qualified hostname
.endif

.if defined(WITHOUT_SUBMIT_NODE)
INSTALL_SUBMIT_NODE=
.else
INSTALL_SUBMIT_NODE=	submit,
.endif

.if defined(WITHOUT_EXECUTE_NODE)
INSTALL_EXECUTE_NODE=
.else
INSTALL_EXECUTE_NODE=	execute,
.endif

.if defined(WITHOUT_MANAGER_NODE)
INSTALL_MANAGER_NODE=
.else
INSTALL_MANAGER_NODE=	manager,
.endif

# Where Condor will store files it needs
LOCAL_DIR=	${DEST_DIR}/var/${PORTNAME}

pre-install:
	${MKDIR} ${LOCAL_DIR}/execute
	${MKDIR} ${LOCAL_DIR}/spool
	${MKDIR} ${LOCAL_DIR}/log

do-install:
	${WRKSRC}/condor_configure --type=${INSTALL_SUBMIT_NODE}${INSTALL_EXECUTE_NODE}${INSTALL_MANAGER_NODE} --install=${WRKSRC}/release.tar --install-dir=${PREFIX} --local-dir=${LOCAL_DIR} --maybe-daemon-owner --overwrite
	${MV} ${PREFIX}/etc/examples/ ${PREFIX}/etc/condor_config.examples
	${PERL} -pi -e "s|^HOSTALLOW_WRITE = .*|HOSTALLOW_WRITE = *|" ${PREFIX}/etc/condor_config
	${PERL} -pi -e "s|^MASTER=.*|MASTER=${PREFIX}/sbin/condor_master|" ${PREFIX}/etc/condor_config.examples/condor.boot
	${PERL} -pi -e "s|^PS=.*|PS=${PS}|" ${PREFIX}/etc/condor_config.examples/condor.boot
	${CP} ${PREFIX}/etc/condor_config.examples/condor.boot ${PREFIX}/etc/rc.d/condor

post-install:
	${CAT} ${PKGMESSAGE}
	@( ${ECHO_MSG} ""; \
	   ${ECHO_MSG} "Set the following parameter in your environment:"; \
	   ${ECHO_MSG} "CONDOR_CONFIG = ${PREFIX}/etc/condor_config"; \
	   ${ECHO_MSG} ""; \
	   ${ECHO_MSG} "Sample configuration files may be found in ${PREFIX}/condor_config.examples/"; \
	   ${ECHO_MSG} ""; \
	   ${ECHO_MSG} "Condor can be started with the following command:"; \
	   ${ECHO_MSG} "${PREFIX}/etc/rc.d/condor start"; \
	   ${ECHO_MSG} "" )

MAN1=		condor_advertise.1 \
		condor_checkpoint.1 \
		condor_compile.1 \
		condor_configure.1 \
		condor_config_val.1 \
		condor_findhost.1 \
		condor_glidein.1 \
		condor_history.1 \
		condor_hold.1 \
		condor_master.1 \
		condor_master_off.1 \
		condor_off.1 \
		condor_on.1 \
		condor_preen.1 \
		condor_prio.1 \
		condor_q.1 \
		condor_qedit.1 \
		condor_reconfig.1 \
		condor_rm.1 \
		condor_reconfig_schedd.1 \
		condor_release.1 \
		condor_reschedule.1 \
		condor_restart.1 \
		condor_run.1 \
		condor_stats.1 \
		condor_status.1 \
		condor_store_cred.1 \
		condor_submit.1 \
		condor_submit_dag.1 \
		condor_updates_stats.1 \
		condor_userlog.1 \
		condor_userprio.1 \
		condor_vacate.1 \
		condor_vacate_job.1

.include <bsd.port.post.mk>
