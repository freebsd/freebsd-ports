# New ports collection makefile for:	apache-tomcat
# Date created:		14 Feb 2007
# Whom:			Nemo Liu <nemoliu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tomcat
PORTVERSION=	7.0.22
CATEGORIES=	www java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	tomcat/tomcat-7/v${PORTVERSION}/bin
DISTNAME=	apache-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Open-source Java web server by Apache, 7.x branch

LICENSE=	ASL
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

APP_SHORTNAME=	tomcat7

USE_RC_SUBR=	${APP_SHORTNAME}

TOMCAT_SUBDIR?=	${DISTNAME:R}
TOMCAT_HOME=	${PREFIX}/${TOMCAT_SUBDIR}
TOMCAT_CONF_FILES=	catalina.policy catalina.properties context.xml logging.properties server.xml tomcat-users.xml web.xml
CONF_EXT=	sample
PLIST_SUB=	T=${TOMCAT_SUBDIR} CONF_EXT=${CONF_EXT} \
		WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
LATEST_LINK=	${APP_SHORTNAME}

SUB_LIST=	TOMCAT_HOME=${TOMCAT_HOME} \
		TOMCAT_USER=${WWWOWN}

.include <bsd.port.pre.mk>

pre-patch:
	@${ECHO_MSG} "Installation settings:"
	@${ECHO_MSG} "   Destination directory:    ${TOMCAT_HOME}"
	@${ECHO_MSG} "   Location of JDK:          ${JAVA_HOME}"
	@${ECHO_MSG} "   Location of Java port:    ${JAVA_PORT}"

post-patch:
	@${FIND} ${WRKSRC} -name '*.bat' -delete
.for f in ${TOMCAT_CONF_FILES}
	@${MV} ${WRKSRC}/conf/${f} ${WRKSRC}/conf/${f}.${CONF_EXT}
.endfor

do-install:
	@${ECHO_MSG} -n ">> Creating destination directory..."
	@${MKDIR} ${TOMCAT_HOME}/logs
	@${MKDIR} ${TOMCAT_HOME}/endorsed
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Copying files to destination directory..."
	@${CP} -R ${WRKSRC}/* ${TOMCAT_HOME}
	@${ECHO_MSG} " [ DONE ]"

.for f in ${TOMCAT_CONF_FILES}
.	if !exists(${TOMCAT_HOME}/conf/${f})
		@${CP} ${TOMCAT_HOME}/conf/${f}.${CONF_EXT} ${TOMCAT_HOME}/conf/${f}
.	else
		@${ECHO_MSG} ">> Preserving local configuration file: ${f} [ DONE ]"
.	endif
.endfor

	@${ECHO_MSG} -n ">> Creating symlink to tools.jar..."
	@${LN} -sf ${JAVA_HOME}/lib/tools.jar ${TOMCAT_HOME}/lib/tools.jar
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Fixing ownership settings..."
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${TOMCAT_HOME}/conf ${TOMCAT_HOME}/logs \
		${TOMCAT_HOME}/temp ${TOMCAT_HOME}/webapps ${TOMCAT_HOME}/work
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Fixing permissions..."
	@${FIND} ${TOMCAT_HOME} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.post.mk>
