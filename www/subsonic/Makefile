# New ports collection makefile for:	subsonic
# Date created:		2011-02-01
# Whom:			Nicole Reid <root@cooltrainer.org>
#
# $FreeBSD$
#

PORTNAME=	subsonic
PORTVERSION=	4.6
PORTREVISION?=	2
CATEGORIES=	www java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-war

MAINTAINER=	root@cooltrainer.org
COMMENT=	Subsonic streaming media server

BUILD_DEPENDS+=	${LOCALBASE}/apache-tomcat-6.0:${PORTSDIR}/www/tomcat6
RUN_DEPENDS+=	${JAVAJARDIR}/servlet-api.jar:${PORTSDIR}/www/servlet-api

OPTIONS=	TRANSCODING "Enable transcoding with FFmpeg and LAME"	On

.include <bsd.port.options.mk>

.if defined(WITH_TRANSCODING)
RUN_DEPENDS+=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg \
		lame:${PORTSDIR}/audio/lame
.endif

#Subsonic does not currently run on Tomcat 7
SUB_FILES=	pkg-message
.if exists(${LOCALBASE}/apache-tomcat-6.0/webapps)
WEBAPPDIR=	${PREFIX}/apache-tomcat-6.0/webapps
BUILD_DEPENDS+=	${LOCALBASE}/apache-tomcat-6.0/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
RUN_DEPENDS+=	${LOCALBASE}/apache-tomcat-6.0/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
SUB_LIST=	TOMCATOPTS="tomcat60_java_opts"
.elif exists(${LOCALBASE}/tomcat5.5/webapps)
WEBAPPDIR=	${PREFIX}/tomcat5.5/webapps
BUILD_DEPENDS+=	${LOCALBASE}/tomcat5.5/bin/bootstrap.jar:${PORTSDIR}/www/tomcat55
RUN_DEPENDS+=	${LOCALBASE}/tomcat5.5/bin/bootstrap.jar:${PORTSDIR}/www/tomcat55
SUB_LIST=	TOMCATOPTS="tomcat55_java_opts"
.else
WEBAPPDIR=	${PREFIX}/apache-tomcat-6.0/webapps
BUILD_DEPENDS+=	${LOCALBASE}/apache-tomcat-6.0/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
RUN_DEPENDS+=	${LOCALBASE}/apache-tomcat-6.0/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
SUB_LIST=	TOMCATOPTS="tomcat60_java_opts"
.endif

NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
USE_ZIP=	yes
USER=		www
GROUP=		www
SUBSONIC_HOME=	/var/subsonic
PLIST_SUB+=	SUBSONIC_HOME="${SUBSONIC_HOME}"

.if defined(WITH_TRANSCODING)
PLIST_SUB+=	TRANSCODING=""
.else
PLIST_SUB+=	TRANSCODING="@comment "
.endif

PLIST_SUB+=	WEBAPPS=${WEBAPPDIR:S|^${PREFIX}/||}

do-install:
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.war ${WEBAPPDIR}
	@${MKDIR} ${SUBSONIC_HOME}
	@${CHOWN} ${USER}:${GROUP} ${SUBSONIC_HOME}

post-install:
.if defined(WITH_TRANSCODING)
	@${MKDIR} ${SUBSONIC_HOME}/transcode
	@${LN} -sf ${PREFIX}/bin/ffmpeg ${SUBSONIC_HOME}/transcode/ffmpeg
	@${LN} -sf ${PREFIX}/bin/lame ${SUBSONIC_HOME}/transcode/lame
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
