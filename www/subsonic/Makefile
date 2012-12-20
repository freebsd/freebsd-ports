# Created by: Nicole Reid <root@cooltrainer.org>
# $FreeBSD$

PORTNAME=	subsonic
PORTVERSION=	4.7
PORTREVISION=	1
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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTRANSCODING}
RUN_DEPENDS+=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg \
		lame:${PORTSDIR}/audio/lame
.endif

#Subsonic does not currently run on Tomcat 7
SUB_FILES=	pkg-message
WEBAPPDIR=	${PREFIX}/apache-tomcat-6.0/webapps
BUILD_DEPENDS+=	${LOCALBASE}/apache-tomcat-6.0/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
RUN_DEPENDS+=	${LOCALBASE}/apache-tomcat-6.0/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
SUB_LIST=	TOMCATOPTS="tomcat60_java_opts"

NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ZIP=	yes
USER=		www
GROUP=		www
SUBSONIC_HOME=	/var/subsonic
PLIST_SUB+=	SUBSONIC_HOME="${SUBSONIC_HOME}"

.if ${PORT_OPTIONS:MTRANSCODING}
PLIST_SUB+=	TRANSCODING=""
.else
PLIST_SUB+=	TRANSCODING="@comment "
.endif

PLIST_SUB+=	WEBAPPS=${WEBAPPDIR:S|^${PREFIX}/||}

post-extract:
	@${MKDIR} ${WRKDIR}/${PORTDIRNAME}
	@${TAR} xf ${WRKDIR}/${PORTNAME}.war -C ${WRKDIR}/${PORTDIRNAME}

do-install:
	${INSTALL} -d -o ${WWWOWN} -g ${WWWGRP} ${WEBAPPDIR}/${PORTDIRNAME}
	@cd ${WRKDIR}/${PORTDIRNAME} && ${COPYTREE_SHARE} \* ${WEBAPPDIR}/${PORTDIRNAME}
	@${MKDIR} ${SUBSONIC_HOME}
	@${CHOWN} ${USER}:${GROUP} ${SUBSONIC_HOME}

post-install:
.if ${PORT_OPTIONS:MTRANSCODING}
	@${MKDIR} ${SUBSONIC_HOME}/transcode
	@${LN} -sf ${PREFIX}/bin/ffmpeg ${SUBSONIC_HOME}/transcode/ffmpeg
	@${LN} -sf ${PREFIX}/bin/lame ${SUBSONIC_HOME}/transcode/lame
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
