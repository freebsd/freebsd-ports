# New ports collection makefile for:	Jetty
# Date created:				28 August 2000
# Whom:				Stephane Legrand <stephane@freebsd-fr.org>
#
# $FreeBSD$
#

PORTNAME=	jetty
DISTVERSION=	6.1.26
CATEGORIES=	www java
MASTER_SITES=	http://dist.codehaus.org/jetty/${PORTNAME}-${DISTVERSION}/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Full-featured web server implemented entirely in Java

USE_RC_SUBR=	${PORTNAME}
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
USE_PYTHON=	1.6+
PLIST=		${WRKDIR}/pkg-plist
PKGMESSAGE=	${WRKDIR}/pkg-message

APP_NAME=	${PORTNAME}
APP_HOME=	${PREFIX}/${PORTNAME}
PID_FILE?=	${APP_HOME}/${APP_NAME}.pid
RUNASUSER?=	www
RUNASUID?=	80
GROUP?=		www
GID?=		80
LOG_FILE?=	${APP_HOME}/${APP_NAME}.log

SUB_LIST=	\
		APP_HOME=${APP_HOME} \
		APP_NAME=${APP_NAME} \
		JAVA_HOME=${JAVA_HOME} \
		JAVA=${JAVA} \
		PID_FILE=${PID_FILE} \
		RUNASUSER=${RUNASUSER} \
		RUNASUID=${RUNASUID} \
		GROUP=${GROUP} \
		GID=${GID} \
		LOG_FILE=${LOG_FILE} \
		PYTHON_CMD=${PYTHON_CMD}

SUB_FILES=	\
		pkg-install \
		pkg-deinstall \
		${APP_NAME}ctl \
		${APP_NAME} \
		message \
		message-advanced

do-build:

post-build:
	@${ECHO_MSG} "===>    Building packing list"
	@> ${PLIST}

	@cd ${WRKSRC} && ${FIND} -H * -type f \
	| ${EGREP} -v "^(bin/|bin$$)" | ${SED} -e "s|^|${PORTNAME}/|" >> ${PLIST}

	@cd ${WRKSRC} && ${FIND} -H -d * -type d \
	| ${EGREP} -v "^(bin/|bin$$)" | ${SED} -e "s|^|@dirrm ${PORTNAME}/|" >> ${PLIST}

	@${ECHO} @dirrm ${PORTNAME} >> ${PLIST}
	@${CAT} ${MASTERDIR}/pkg-plist >> ${PLIST}

pre-install:
	@${FMT} -w80 ${WRKDIR}/message > ${PKGMESSAGE}
	@${CAT} ${WRKDIR}/message-advanced >> ${PKGMESSAGE}

do-install:
	@${ECHO_MSG} "===>    Installing into ${APP_HOME}"

# Create user/group
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

	@${MKDIR} ${APP_HOME}
	@cd ${WRKSRC} && ${FIND} -H * | ${EGREP} -v "^(bin/|bin$$)" | ${CPIO} -pdmuL -R ${RUNASUSER}:${GROUP} ${APP_HOME}
	@${CHOWN} ${RUNASUSER}:${GROUP} ${PREFIX}/${PORTNAME}

	@${ECHO_MSG} "===>    Installing into ${PREFIX}/sbin"
	@${INSTALL_SCRIPT} ${WRKDIR}/${APP_NAME}ctl ${PREFIX}/sbin

post-install:
	@${ECHO_CMD}
	@${ECHO_CMD} "********************************************************************************"
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} "********************************************************************************"
	@${ECHO_CMD}

.include <bsd.port.mk>
