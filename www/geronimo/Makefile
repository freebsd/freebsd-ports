# New ports collection makefile for:	geronimo
# Date created:		26 Apr 2007
# Whom:			Nemo Liu <nemoliu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	geronimo
PORTVERSION=	2.0.2
CATEGORIES=	www devel java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	geronimo/${PORTVERSION}
DISTNAME=	${PORTNAME}-${WEBSERVER}-jee5-${PORTVERSION}-bin

MAINTAINER=	nemoliu@FreeBSD.org
COMMENT=	Open-source Java EE 5 application server

USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	YES

USE_RC_SUBR=	geronimo2.sh
SUB_FILES=	pkg-install pkg-deinstall

OPTIONS=	JETTY6 "Use Jetty6 as web server" on \
		TOMCAT6 "Use Tomcat as web server" off

.include <bsd.port.pre.mk>

.if defined(WITH_JETTY6) && defined(WITH_TOMCAT6)
BROKEN=		Choose only one web server
.endif
.if defined(WITHOUT_JETTY6) && defined(WITHOUT_TOMCAT6)
BROKEN=		Choose one web server
.endif

.if defined(WITH_JETTY6)
WEBSERVER=	jetty6
.elif defined(WITH_TOMCAT6)
WEBSERVER=	tomcat6
.endif

MAJOR_VER=	${PORTVERSION:S/.0.2//}
APP_HOME?=	${PREFIX}/${PKGBASE}${PORTVERSION:S/.0.2//}
LOG_DIR=	${APP_HOME}/var/log
APP_TITLE=	Geronimo
APP_SHORTNAME=	geronimo${MAJOR_VER:S/.0.2//}
GERONIMO_USER?=	www
GERONIMO_GROUP?=www
GERONIMO_OUT=	${LOG_DIR}/geronimo.out
PID_FILE=	/var/run/${APP_SHORTNAME}.pid
WRKDIR?=	${WRKDIRPREFIX}${.CURDIR}/work
WRKSRC=		${WRKDIR}/${PORTNAME}-${WEBSERVER}-jee5-${PORTVERSION}
JAR_FILE=	bin/server.jar
WEBPATHV=	${WEBSERVER}
WEBPATHNV=	jetty
TCOMMENT=	"@comment "
JCOMMENT=	"@comment "
.if ${WEBSERVER} != "jetty6"
WEBPATHV=	tomcat
WEBPATHNV=	tomcat
TCOMMENT=
.else
WEBPATHNV=	jetty
JCOMMENT=
.endif
PLIST_SUB+=	T=${APP_HOME:S/^${PREFIX}\///} \
		WWWOWN=${TOMCAT_USER} \
		WWWGRP=${TOMCAT_GROUP} \
		PVER=${PORTVERSION} \
		WEBPATHV=${WEBPATHV} \
		WEBPATHNV=${WEBPATHNV} \
		WEBPATHV=${WEBPATHV} \
		WEBPATHNV=${WEBPATHNV} \
		TCOMMENT=${TCOMMENT} \
		JCOMMENT=${JCOMMENT} \
		JCOMMENTD=${JCOMMENTD} \
		TCOMMENTD=${TCOMMENTD}
LATEST_LINK=	${APP_SHORTNAME}

SUB_LIST=	GERONIMO_HOME=${APP_HOME} \
		APP_SHORTNAME=${APP_SHORTNAME} \
		APP_TITLE="${APP_TITLE}" \
		GROUP=${GERONIMO_GROUP} \
		HTTP_PORT=${HTTP_PORT} \
		JAR_FILE=${JAR_FILE} \
		PID_FILE=${PID_FILE} \
		GERONIMO_OUT=${GERONIMO_OUT} \
		USER=${GERONIMO_USER} \
		GERONIMO_VERSION=${MAJOR_VER} \
		GERONIMO_OUT=${GERONIMO_OUT} \
		JAVA_HOME=${JAVA_HOME}

pre-patch:
	@${ECHO_MSG} "Installation settings:"
	@${ECHO_MSG} "   Destination directory:    ${APP_HOME}"
	@${ECHO_MSG} "   Location of JDK:          ${JAVA_HOME}"
	@${ECHO_MSG} "   Location of Java port:    ${JAVA_PORT}"
	@${ECHO_MSG} "   Running as (user/group):  ${GERONIMO_USER}/${GERONIMO_GROUP}"
	@${ECHO_MSG} "   Logfile:		   ${GERONIMO_OUT}"

post-patch:
	@${ECHO_MSG} -n ">> Removing unneeded files..."
	@${RM} -f `${FIND} ${WRKSRC} -name '*.bat'` `${FIND} ${WRKSRC} -name '*.orig'` `${FIND} ${WRKSRC} -name '*.exe'`
	@${ECHO_MSG} " [ DONE ]"

pre-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${ECHO_MSG} -n ">> Creating destination directory..."
	@${MKDIR} ${APP_HOME}
	@${MKDIR} ${LOG_DIR}
	@${MKDIR} ${APP_HOME}/deploy
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} ">> Copying files to destination directory..."
	@${CP} -R ${WRKSRC}/* ${APP_HOME}
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Creating log files..."
	@${INSTALL} -m 664 -o ${GERONIMO_USER} -g ${GERONIMO_GROUP} /dev/null ${GERONIMO_OUT}
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Creating symlink to tools.jar..."
	@${LN} -sf ${JAVA_HOME}/lib/tools.jar ${APP_HOME}/lib/tools.jar
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Fixing ownership settings..."
	@${CHOWN} -R ${GERONIMO_USER}:${GERONIMO_GROUP} ${APP_HOME}/lib ${APP_HOME}/var \
		${APP_HOME}/schema ${APP_HOME}/lib ${APP_HOME}/repository
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Fixing permissions..."
	@${CHMOD} 755 `${FIND} ${APP_HOME} -type d`
	@${ECHO_MSG} " [ DONE ]"

post-install:
	@${ECHO_MSG} "${APP_TITLE} ${PORTVERSION} has been installed in ${APP_HOME}."

.include <bsd.port.post.mk>
