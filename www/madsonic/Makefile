# Created by: Nicole Reid <root@cooltrainer.org>
# $FreeBSD$

PORTNAME=	madsonic
PORTVERSION=	6.1.8700
PORTREVISION=	1
CATEGORIES=	www java
MASTER_SITES=	http://madsonic.org/download/6.1/
DISTFILES=	${DISTDATE}_${DISTNAME}-war-tomcat.zip \
	${DISTDATE}_${DISTNAME}-war-jspc.zip

MAINTAINER=	root@cooltrainer.org
COMMENT=	Madsonic streaming media server

LICENSE=	GPLv3

OPTIONS_SINGLE=	APPSERVER
APPSERVER_DESC=	Java Application Server
OPTIONS_SINGLE_APPSERVER=	JETTY TOMCAT8 TOMCAT7 TOMCAT6 RESIN3
TOMCAT8_DESC=	Use Tomcat 8.x
TOMCAT7_DESC=	Use Tomcat 7.x
TOMCAT6_DESC=	Use Tomcat 6.x
JETTY_DESC=	Use Jetty
RESIN3_DESC=	Use Resin 3

OPTIONS_GROUP=	TRANSCODING
TRANSCODING_DESC=	Transcoding support
OPTIONS_GROUP_TRANSCODING=	FFMPEG FLAC LAME VORBIS FAAC FAAD XMP MPC APE
FFMPEG_DESC=	Depend on FFmpeg for audio and video transcoding
FLAC_DESC=	Depend on FLAC for transcoding
LAME_DESC=	Depend on LAME for MP3 transcoding
VORBIS_DESC=	Depend on oggenc/oggdec for Vorbis transcoding
FAAC_DESC=	Depend on FAAD for AAC/M4A transcoding
FAAD_DESC=	Depend on FAAC for AAC/M4A transcoding
XMP_DESC=	Depend on XMP for module file transcoding
MPC_DESC=	Depend on mpcdec for MPC transcoding
APE_DESC=	Depend on mac for Monkey's Audio transcoding #'

OPTIONS_DEFAULT=	FFMPEG JETTY
OPTIONS_SUB=	yes

RUN_DEPENDS+=	${JAVAJARDIR}/servlet-api.jar:www/servlet-api \
	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins
TOMCAT8_BUILD_DEPENDS=	${LOCALBASE}/${SERVERDIR}/bin/bootstrap.jar:www/tomcat8
TOMCAT8_RUN_DEPENDS=	${LOCALBASE}/${SERVERDIR}/bin/bootstrap.jar:www/tomcat8
TOMCAT7_BUILD_DEPENDS=	${LOCALBASE}/${SERVERDIR}/bin/bootstrap.jar:www/tomcat7
TOMCAT7_RUN_DEPENDS=	${LOCALBASE}/${SERVERDIR}/bin/bootstrap.jar:www/tomcat7
TOMCAT6_BUILD_DEPENDS=	${LOCALBASE}/${SERVERDIR}/bin/bootstrap.jar:www/tomcat6
TOMCAT6_RUN_DEPENDS=	${LOCALBASE}/${SERVERDIR}/bin/bootstrap.jar:www/tomcat6
JETTY_BUILD_DEPENDS=	${LOCALBASE}/${SERVERDIR}/start.jar:www/jetty8
JETTY_RUN_DEPENDS=	${LOCALBASE}/${SERVERDIR}/start.jar:www/jetty8
RESIN3_BUILD_DEPENDS=	${LOCALBASE}/${SERVERDIR}/lib/resin.jar:www/resin3
RESIN3_RUN_DEPENDS=	${LOCALBASE}/${SERVERDIR}/lib/resin.jar:www/resin3
FFMPEG_RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg
FLAC_RUN_DEPENDS=	flac:audio/flac
LAME_RUN_DEPENDS=	lame:audio/lame
VORBIS_RUN_DEPENDS=	oggenc:audio/vorbis-tools
FAAC_RUN_DEPENDS=	faac:audio/faac
FAAD_RUN_DEPENDS=	faad:audio/faad
XMP_RUN_DEPENDS=	xmp:audio/xmp
MPC_RUN_DEPENDS=	mpcdec:audio/musepack
APE_RUN_DEPENDS=	mac:audio/mac

.include <bsd.port.options.mk>

NO_BUILD=	yes
DISTDATE=	20160915
USE_JAVA=	yes
JAVA_VERSION=	1.7+
USES=	zip
USER=	www
GROUP=	www
MADSONIC_HOME=	/var/madsonic
WRKSRC=	${WRKDIR}/${PORTNAME}
WEBAPPDIR=	${PREFIX}/${SERVERDIR}/webapps
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST=	${WRKDIR}/plist
PLIST_SUB+=	MADSONIC_HOME="${MADSONIC_HOME}" \
	WEBAPPS=${WEBAPPDIR:S|^${PREFIX}/||}
SUB_FILES=	message-common\
	message-transcoding
SUB_LIST=	MADSONIC_HOME="${MADSONIC_HOME}"

.if ${PORT_OPTIONS:MTOMCAT8}
APPPKGMESSAGE=	pkg-message-tomcat
DISTVER=	tomcat
PKGNAMESUFFIX=	-tomcat8
SERVERDIR=	apache-tomcat-8.0
SUB_LIST+=	CONTAINERFLAGS="tomcat8_java_opts"
.endif

.if ${PORT_OPTIONS:MTOMCAT7}
APPPKGMESSAGE=	pkg-message-tomcat
DISTVER=	tomcat
PKGNAMESUFFIX=	-tomcat7
SERVERDIR=	apache-tomcat-7.0
SUB_LIST+=	CONTAINERFLAGS="tomcat7_java_opts"
.endif

.if ${PORT_OPTIONS:MTOMCAT6}
APPPKGMESSAGE=	pkg-message-tomcat
DISTVER=	tomcat
PKGNAMESUFFIX=	-tomcat6
SERVERDIR=	apache-tomcat-6.0
SUB_LIST+=	CONTAINERFLAGS="tomcat60_java_opts"
.endif

.if ${PORT_OPTIONS:MJETTY}
APPPKGMESSAGE=	pkg-message-jetty
DISTVER=	jspc
PKGNAMESUFFIX=	-jetty
SERVERDIR=	jetty
SUB_LIST+=	CONTAINERFLAGS="jetty_flags"
.endif

.if ${PORT_OPTIONS:MRESIN3}
APPPKGMESSAGE=	pkg-message-resin3
DISTVER=	tomcat
PKGNAMESUFFIX=	-resin3
SERVERDIR=	resin3
SUB_LIST+=	CONTAINERFLAGS="resin3_flags"
.endif

do-extract:
	${EXTRACT_CMD} -qo ${DISTDIR}/${DISTDATE}_${PORTNAME}-${PORTVERSION}-war-${DISTVER}.zip -d ${WRKDIR}

post-extract:
	@${MKDIR} ${WRKSRC}
	@${TAR} -xf ${WRKDIR}/${PORTNAME}.war -C ${WRKSRC}

pre-install:
	@${RM} ${PLIST}
	@${ECHO} "@owner ${USER}" >> ${PLIST}
	@${ECHO} "@group ${GROUP}" >> ${PLIST}
	@cd ${WRKSRC}; ${FIND} . -type f | cut -c2- \
		| ${SED} 's|^|${WEBAPPDIR:S,${PREFIX}/,,}/${PORTDIRNAME}|' \
		| ${SORT} >> ${PLIST}
	@${CAT} ${PKGDIR}/pkg-plist-chunk >> ${PLIST}
	@cd ${WRKSRC}; ${FIND} . -type d | cut -c2- \
		| ${SED} 's|^|@dir ${WEBAPPDIR:S,${PREFIX}/,,}/${PORTDIRNAME}|' \
		| ${SORT} -r >> ${PLIST}
	@${RM} ${PKGMESSAGE}
	@${CAT} ${PKGDIR}/pkg-message-spacer >> ${PKGMESSAGE}
	@${CAT} ${PKGDIR}/${APPPKGMESSAGE} >> ${PKGMESSAGE}
	@${CAT} ${WRKDIR}/message-common >> ${PKGMESSAGE}
	@${CAT} ${PKGDIR}/pkg-message-spacer >> ${PKGMESSAGE}
	@${CAT} ${WRKDIR}/message-transcoding >> ${PKGMESSAGE}
	@${CAT} ${PKGDIR}/pkg-message-spacer >> ${PKGMESSAGE}

do-install:
	cd ${WRKDIR} && ${COPYTREE_SHARE} ${PORTDIRNAME} ${STAGEDIR}${WEBAPPDIR}

	${MKDIR} ${STAGEDIR}${MADSONIC_HOME}
	${MKDIR} ${STAGEDIR}${MADSONIC_HOME}/transcode

.include <bsd.port.mk>
