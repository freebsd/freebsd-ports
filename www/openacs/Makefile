# New ports collection makefile for:    openACS
# Date created:         July 2005
# Whom:                 Aldert Nooitgedagt <aldert@nooitgedagt.net>
#
# $FreeBSD$
#

PORTNAME?=	openacs
PORTVERSION?=	5.1.5
PORTREVISION?=	2
CATEGORIES=	www
MASTER_SITES?=	http://openacs.org/projects/openacs/download/download/

MAINTAINER?=	aldert@nooitgedagt.net
COMMENT?=	A modular web application platform for high traffic communities

OPENACS_USER?=	service0
OPENACS_GROUP=	web
PG_USER=	pgsql

DATADIR=	${PREFIX}/share/${OPENACS_USER}
EXAMPLESDIR=	${PREFIX}/share/examples/${OPENACS_USER}
OPENACSBASE=	${PREFIX}/share
VIRTUALBASE=	/var/lib
AOLSERVERBASE=	${LOCALBASE}/aolserver
DTSERVICEBASE=	/var/service
RCCONF=		/etc/rc.conf

IP_ADDRESS=	0.0.0.0

USE_RC_SUBR=	YES
PKGINSTALL=	${WRKDIR}/pkg-install
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
.if defined(WITH_POSTCONFIG)
POSTCONFIG=	true
PKGNAMESUFFIX=	-withconfig
.endif

.if defined(WITH_DT)
DT=		true
RUN_DEPENDS+=	${LOCALBASE}/bin/supervise:${PORTSDIR}/sysutils/daemontools
.endif

SUB_FILES=	pkg-install pkg-message pkg-deinstall post-config
SUB_LIST+=	RCCONF=${RCCONF} POSTCONFIG=${POSTCONFIG} \
		OPENACSBASE=${OPENACSBASE} OPENACS_GROUP=${OPENACS_GROUP} \
		OPENACS_USER=${OPENACS_USER} DB=${DB} PGDATA=${PGDATA} \
		PG_USER=${PG_USER} PGBASE=${PGBASE} \
		DTSERVICEBASE=${DTSERVICEBASE} DT=${DT} \
		AOLSERVERBASE=${AOLSERVERBASE} VIRTUALBASE=${VIRTUALBASE}

RUN_DEPENDS+=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash \
		${LOCALBASE}/lib/libtcl84.so.1:${PORTSDIR}/lang/tcl84-thread \
		${LOCALBASE}/lib/libreadline.so:${PORTSDIR}/devel/readline \

.if defined(WITH_ORACLE)
BROKEN=		"Oracle not supported yet"
DB=		ORA
.else
DB=		PG
PGBASE=		${LOCALBASE}
PGDATA=		${LOCALBASE}/pgsql/data
RUN_DEPENDS+=	${LOCALBASE}/lib/libpq.so:${PORTSDIR}/databases/postgresql74-server \
		${LOCALBASE}/aolserver/bin/nsd:${PORTSDIR}/www/aolserver-openacs-pg
.endif

RUN_DEPENDS+=	${LOCALBASE}/lib/tdom0.8.0/libtdom0.8.0.so:${PORTSDIR}/www/tdom \
		${LOCALBASE}/tclwebtest-1.0/tclwebtest:${PORTSDIR}/www/tclwebtest

USE_LINUX=	YES

NO_BUILD=	YES

REINPLACE_ARGS=	-i "" -e

PLIST_FILES=	${EXAMPLESDIR:S,^${PREFIX}/,,}/svscan.sh \
		${EXAMPLESDIR:S,^${PREFIX}/,,}/restart-aolserver \
		${EXAMPLESDIR:S,^${PREFIX}/,,}/svgroup \
		${EXAMPLESDIR:S,^${PREFIX}/,,}/nsd-postgres \
		${EXAMPLESDIR:S,^${PREFIX}/,,}/nsd-oracle \
		${EXAMPLESDIR:S,^${PREFIX}/,,}/post-config.sh

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${OPENACSBASE}
	@${MKDIR} ${VIRTUALBASE}

	@${ECHO_CMD} "Installing files"
	@${CP} -R ${WRKSRC} ${OPENACSBASE}/${OPENACS_USER}

	@${TEST} -e ${VIRTUALBASE}/aolserver || ${LN} -s ${OPENACSBASE} ${VIRTUALBASE}/aolserver
	@${TEST} -L ${VIRTUALBASE}/aolserver || ${ECHO_MSG} "${VIRTUALBASE}/aolserver is no symbolic link"

	@${INSTALL_SCRIPT} ${OPENACSBASE}/${OPENACS_USER}/packages/acs-core-docs/www/files/nsd-postgres.txt ${EXAMPLESDIR}/nsd-postgres
	@${INSTALL_SCRIPT} ${OPENACSBASE}/${OPENACS_USER}/packages/acs-core-docs/www/files/nsd-oracle.txt ${EXAMPLESDIR}/nsd-oracle
	@${INSTALL_SCRIPT} ${OPENACSBASE}/${OPENACS_USER}/packages/acs-core-docs/www/files/restart-aolserver.txt ${EXAMPLESDIR}/restart-aolserver
	@${INSTALL_SCRIPT} ${FILESDIR}/svscan.sh ${EXAMPLESDIR}/svscan.sh
	@${INSTALL_SCRIPT} ${OPENACSBASE}/${OPENACS_USER}/packages/acs-core-docs/www/files/svgroup.txt ${EXAMPLESDIR}/svgroup
	@${INSTALL_SCRIPT} ${WRKDIR}/post-config ${EXAMPLESDIR}/post-config.sh

post-install:
	@${REINPLACE_CMD} "\
		s|/usr/local/aolserver|${AOLSERVERBASE}|g; \
		s|/bin/bash|/bin/sh|g; \
		" ${EXAMPLESDIR}/nsd-postgres ${EXAMPLESDIR}/nsd-oracle
	@${REINPLACE_CMD} "\
		s|service0|${OPENACS_USER}|g; \
		s|\[ns_info address\]|${IP_ADDRESS}|g; \
		s|/var/lib/aolserver|${OPENACSBASE}|g; \
		s|/usr/local/aolserver|${AOLSERVERBASE}|g; \
		" ${OPENACSBASE}/${OPENACS_USER}/etc/config.tcl
	@${REINPLACE_CMD} "\
		s|service0|${OPENACS_USER}|g; \
		s|/usr/local/aolserver/bin|${EXAMPLESDIR}|g; \
		" ${OPENACSBASE}/${OPENACS_USER}/etc/daemontools/run

	@${ECHO_CMD} "@unexec rm -f ${DATADIR}/log/${OPENACS_USER}* 2>&1 > /dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rm -f ${DATADIR}/log/error.log* 2>&1 > /dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rm -Rf ${DATADIR}/apm-workspace 2>&1 > /dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rm -Rf ${DATADIR}/etc/daemontools/supervise 2>&1 > /dev/null || true" >> ${TMPPLIST}
	@${FIND} -s ${WRKSRC} -not -type d \
		| ${SED} -ne 's,^${WRKSRC},${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${WRKSRC} -type d \
		| ${SED} -ne 's,^${WRKSRC},@dirrm ${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm ${EXAMPLESDIR:S,^${PREFIX}/,,}" >> ${TMPPLIST}

	@if [ ${DT} ] ; then \
		${MKDIR} ${DTSERVICEBASE} ; \
		${TEST} -L ${DTSERVICEBASE}/${OPENACS_USER} || ${LN} -s ${OPENACSBASE}/${OPENACS_USER}/etc/daemontools ${DTSERVICEBASE}/${OPENACS_USER} ; \
		${ECHO_CMD} "@cd ${DTSERVICEBASE}" >> ${TMPPLIST} ; \
		${ECHO_CMD} "${OPENACS_USER}" >> ${TMPPLIST} ; \
		${ECHO_CMD} "@unexec rmdir ${DTSERVICEBASE} 2>&1 > /dev/null || true" >> ${TMPPLIST} ; \
	fi

	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
