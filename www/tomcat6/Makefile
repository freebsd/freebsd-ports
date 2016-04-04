# Created by: Nemo Liu <nemoliu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tomcat
PORTVERSION=	6.0.45
PORTREVISION=	1
CATEGORIES=	www java
MASTER_SITES=	APACHE/tomcat/tomcat-6/v${PORTVERSION}/bin
DISTNAME=	apache-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Open-source Java web server by Apache, 6.x branch

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe
CPE_VENDOR=	apache

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	YES
NO_ARCH=	YES

USE_RC_SUBR=	tomcat6
SUB_FILES=	pkg-install

MAJOR_VER=	${PORTVERSION:R}
APP_HOME?=	${PREFIX}/${DISTNAME:R}
LOG_DIR=	${APP_HOME}/logs
APP_SHORTNAME=	${PORTNAME}${MAJOR_VER:S/.//}
TOMCAT_USER?=	www
TOMCAT_GROUP?=	www
HTTP_PORT?=	8180
SHUTDOWN_PORT?=	8005
AJP_1_3_PORT?=	8009
STDOUT_LOG=	${LOG_DIR}/stdout.log
STDERR_LOG=	${LOG_DIR}/stderr.log
JAR_FILE=	bin/bootstrap.jar
TOMCAT_CONF_FILES=	catalina.policy catalina.properties context.xml \
			logging.properties server.xml tomcat-users.xml web.xml
CONF_EXT=	sample
PLIST_SUB=	T=${APP_HOME:S/^${PREFIX}\///} CONF_EXT=${CONF_EXT} \
		WWWOWN=${TOMCAT_USER} WWWGRP=${TOMCAT_GROUP}

SUB_LIST=	AJP_1_3_PORT=${AJP_1_3_PORT} \
		APP_HOME=${APP_HOME} \
		APP_SHORTNAME=${APP_SHORTNAME} \
		GROUP=${TOMCAT_GROUP} \
		HTTP_PORT=${HTTP_PORT} \
		JAR_FILE=${JAR_FILE} \
		SHUTDOWN_PORT=${SHUTDOWN_PORT} \
		STDERR_LOG=${STDERR_LOG} \
		STDOUT_LOG=${STDOUT_LOG} \
		TOMCAT_HOME=${APP_HOME} \
		TOMCAT_VERSION=${MAJOR_VER:S/.//} \
		USER=${TOMCAT_USER}

.include <bsd.port.pre.mk>

pre-patch:
	@${ECHO_MSG} "Installation settings:"
	@${ECHO_MSG} "   Destination directory:    ${APP_HOME}"
	@${ECHO_MSG} "   Location of JDK:          ${JAVA_HOME}"
	@${ECHO_MSG} "   Location of Java port:    ${JAVA_PORT}"
	@${ECHO_MSG} "   Running as (user/group):  ${TOMCAT_USER}/${TOMCAT_GROUP}"
	@${ECHO_MSG} "   HTTP port:                ${HTTP_PORT}"
	@${ECHO_MSG} "   Shutdown listener port:   ${SHUTDOWN_PORT}"
	@${ECHO_MSG} "   AJP 1.3 connector port:   ${AJP_1_3_PORT}"
	@${ECHO_MSG} "   Logfile stdout:           ${STDOUT_LOG}"
	@${ECHO_MSG} "   Logfile stderr:           ${STDERR_LOG}"

post-patch:
	@${REINPLACE_CMD} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} ${WRKSRC}/conf/server.xml
	@${FIND} ${WRKSRC} -type f \( -name '*.bak' -or -name '*.bat' -or -name '*.dll' -or -name '*.exe' -or -name '*.orig' \) -delete
.for f in ${TOMCAT_CONF_FILES}
	@${MV} ${WRKSRC}/conf/${f} ${WRKSRC}/conf/${f}.${CONF_EXT}
.endfor

pre-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${ECHO_MSG} -n ">> Creating destination directory..."
	@${MKDIR} ${STAGEDIR}${APP_HOME}
	@${MKDIR} ${STAGEDIR}${LOG_DIR}
	@${MKDIR} ${STAGEDIR}${APP_HOME}/endorsed
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Copying files to destination directory..."
	@${CP} -R ${WRKSRC}/* ${STAGEDIR}${APP_HOME}
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Fixing permissions..."
	@${FIND} ${STAGEDIR}${APP_HOME} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.post.mk>
