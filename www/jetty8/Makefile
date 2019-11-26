# Created by: Stephane Legrand <stephane@freebsd-fr.org>
# $FreeBSD$

PORTNAME=	jetty
PORTVERSION=	8.1.15
PORTREVISION=	1
CATEGORIES=	www java
MASTER_SITES=	ECLIPSE/jetty/${PORTVERSION}.${JDVDATE}/dist
PKGNAMESUFFIX=	8
DISTNAME=	jetty-distribution-${PORTVERSION}.${JDVDATE}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Full-featured web server implemented entirely in Java

LICENSE=	APACHE20 EPL
LICENSE_COMB=	dual

RUN_DEPENDS=	bash:shells/bash

CONFLICTS=	jetty-9.*

JDVDATE=	v20140411
USE_RC_SUBR=	${PORTNAME}
USE_JAVA=	yes
USES=		python
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_SUB+=	RUNASUSER=${RUNASUSER} GROUP=${GROUP}

APP_NAME=	${PORTNAME}
APP_HOME=	${PREFIX}/${PORTNAME}
PID_FILE?=	${APP_HOME}/${APP_NAME}.pid
RUNASUSER?=	www
RUNASUID?=	80
GROUP?=		www
GID?=		80
LOG_FILE?=	${APP_HOME}/${APP_NAME}.log

NO_BUILD=	yes
NO_ARCH=	yes

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

pre-install:
	@${FMT} -w80 ${WRKDIR}/message > ${PKGMESSAGE}
	@${CAT} ${WRKDIR}/message-advanced >> ${PKGMESSAGE}

do-install:
	@${MKDIR} ${STAGEDIR}${APP_HOME}
	cd ${WRKSRC} && ${FIND} -H * | ${EGREP} -v "^(bin/|bin$$)" | ${CPIO} -pdmuL ${STAGEDIR}${APP_HOME}
	${INSTALL_SCRIPT} ${WRKDIR}/${APP_NAME}ctl ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
