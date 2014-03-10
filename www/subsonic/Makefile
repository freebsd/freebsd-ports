# Created by: Nicole Reid <root@cooltrainer.org>
# $FreeBSD$

PORTNAME=	subsonic
PORTVERSION=	4.9
CATEGORIES=	www java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-war

MAINTAINER=	root@cooltrainer.org
COMMENT=	Subsonic streaming media server

BUILD_DEPENDS+=	${LOCALBASE}/apache-tomcat-6.0:${PORTSDIR}/www/tomcat6
RUN_DEPENDS+=	${JAVAJARDIR}/servlet-api.jar:${PORTSDIR}/www/servlet-api

OPTIONS_DEFINE=	TRANSCODING
TRANSCODING_DESC=	Transcoding with FFmpeg and LAME
OPTIONS_DEFAULT=	TRANSCODING
OPTIONS_SUB=		yes

TRANSCODING_RUN_DEPENDS=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg \
				lame:${PORTSDIR}/audio/lame

USES=		zip

.include <bsd.port.options.mk>

#Subsonic does not currently run on Tomcat 7
SUB_FILES=	pkg-message
WEBAPPDIR=	${PREFIX}/apache-tomcat-6.0/webapps
BUILD_DEPENDS+=	${LOCALBASE}/apache-tomcat-6.0/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
RUN_DEPENDS+=	${LOCALBASE}/apache-tomcat-6.0/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
SUB_LIST=	TOMCATOPTS="tomcat60_java_opts"

NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
USER=		www
GROUP=		www
SUBSONIC_HOME=	/var/subsonic
PLIST_SUB+=	SUBSONIC_HOME="${SUBSONIC_HOME}" \
		WEBAPPS=${WEBAPPDIR:S|^${PREFIX}/||} \
		USER=${USER} GROUP=${GROUP} \
		WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

post-extract:
	@${MKDIR} ${WRKDIR}/${PORTDIRNAME}
	@${TAR} xf ${WRKDIR}/${PORTNAME}.war -C ${WRKDIR}/${PORTDIRNAME}

do-install:
	@cd ${WRKDIR} && ${COPYTREE_SHARE} ${PORTDIRNAME} ${STAGEDIR}${WEBAPPDIR}

.include <bsd.port.mk>
