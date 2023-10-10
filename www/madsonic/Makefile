PORTNAME=	madsonic
PORTVERSION=	6.2.9092
CATEGORIES=	www java
MASTER_SITES=	https://madsonic.org/download/6.2/
DISTFILES=	${DISTDATE}_${DISTNAME}-war-tomcat.zip \
		${DISTDATE}_${DISTNAME}-war-jspc.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Madsonic streaming media server
WWW=		https://www.madsonic.org

DEPRECATED=	Depends on www/jetty8 which has been listed as end of life since 2015
EXPIRATION_DATE=2023-11-30

LICENSE=	GPLv3

RUN_DEPENDS+=	${JAVALIBDIR}/servlet-api.jar:www/servlet-api \
		${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	8

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_ARCH=	yes
NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_SUB+=	MADSONIC_HOME="${MADSONIC_HOME}" \
		WEBAPPS=${WEBAPPDIR:S|^${PREFIX}/||}
SUB_FILES=	message-common message-transcoding
SUB_LIST=	MADSONIC_HOME="${MADSONIC_HOME}"

OPTIONS_SINGLE=			APPSERVER
OPTIONS_SINGLE_APPSERVER=	JETTY8 TOMCAT85
OPTIONS_GROUP=			TRANSCODING
OPTIONS_GROUP_TRANSCODING=	APE FAAC FAAD FFMPEG FLAC LAME MPC VORBIS XMP
OPTIONS_DEFAULT=		FFMPEG JETTY8
OPTIONS_SUB=			yes

APE_DESC=			Depend on mac for Monkey's Audio transcoding #'
APPSERVER_DESC=			Java Application Server
FAAC_DESC=			Depend on FAAD for AAC/M4A transcoding
FAAD_DESC=			Depend on FAAC for AAC/M4A transcoding
FFMPEG_DESC=			Depend on FFmpeg for audio and video transcoding
FLAC_DESC=			Depend on FLAC for transcoding
JETTY8_DESC=			Use Jetty 8.x
LAME_DESC=			Depend on LAME for MP3 transcoding
MPC_DESC=			Depend on mpcdec for MPC transcoding
TRANSCODING_DESC=		Transcoding support
VORBIS_DESC=			Depend on oggenc/oggdec for Vorbis transcoding
XMP_DESC=			Depend on XMP for module file transcoding

APE_RUN_DEPENDS=		mac:audio/mac
FAAC_RUN_DEPENDS=		faac:audio/faac
FAAD_RUN_DEPENDS=		faad:audio/faad
FFMPEG_RUN_DEPENDS=		ffmpeg:multimedia/ffmpeg
FLAC_RUN_DEPENDS=		flac:audio/flac
JETTY8_BUILD_DEPENDS=		${LOCALBASE}/${SERVERDIR}/start.jar:www/jetty8
JETTY8_RUN_DEPENDS=		${LOCALBASE}/${SERVERDIR}/start.jar:www/jetty8
LAME_RUN_DEPENDS=		lame:audio/lame
MPC_RUN_DEPENDS=		mpcdec:audio/musepack
TOMCAT85_BUILD_DEPENDS=		${LOCALBASE}/${SERVERDIR}/bin/bootstrap.jar:www/tomcat85
TOMCAT85_RUN_DEPENDS=		${LOCALBASE}/${SERVERDIR}/bin/bootstrap.jar:www/tomcat85
VORBIS_RUN_DEPENDS=		oggenc:audio/vorbis-tools
XMP_RUN_DEPENDS=		xmp:audio/xmp

DISTDATE=	20220126
USER=		www
GROUP=		www
MADSONIC_HOME=	/var/madsonic

.include <bsd.port.options.mk>

WEBAPPDIR=	${PREFIX}/${SERVERDIR}/webapps

.if ${PORT_OPTIONS:MTOMCAT85}
APPPKGMESSAGE=	pkg-message-tomcat
DISTVER=	tomcat
PKGNAMESUFFIX=	-tomcat85
SERVERDIR=	apache-tomcat-8.5
SUB_LIST+=	CONTAINERFLAGS="tomcat85_java_opts"
.endif

.if ${PORT_OPTIONS:MJETTY8}
APPPKGMESSAGE=	pkg-message-jetty
DISTVER=	jspc
PKGNAMESUFFIX=	-jetty
SERVERDIR=	jetty
SUB_LIST+=	CONTAINERFLAGS="jetty_flags"
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
		| ${SED} 's|^|${WEBAPPDIR:S,${PREFIX}/,,}/${PORTNAME}|' \
		| ${SORT} >> ${PLIST}
	@${CAT} ${PKGDIR}/pkg-plist-chunk >> ${PLIST}
	@cd ${WRKSRC}; ${FIND} . -type d | cut -c2- \
		| ${SED} 's|^|@dir ${WEBAPPDIR:S,${PREFIX}/,,}/${PORTNAME}|' \
		| ${SORT} -r >> ${PLIST}
	@${ECHO_CMD} "[" > ${PKGMESSAGE}
	@${ECHO_CMD} "{ type: install, message: <<EOM" >> ${PKGMESSAGE}
	@${CAT} ${PKGDIR}/${APPPKGMESSAGE} >> ${PKGMESSAGE}
	@${CAT} ${WRKDIR}/message-common >> ${PKGMESSAGE}
	@${CAT} ${PKGDIR}/pkg-message-spacer >> ${PKGMESSAGE}
	@${CAT} ${WRKDIR}/message-transcoding >> ${PKGMESSAGE}
	@${ECHO_CMD} "EOM" >> ${PKGMESSAGE}
	@${ECHO_CMD} "}" >> ${PKGMESSAGE}
	@${ECHO_CMD} "]" >> ${PKGMESSAGE}

do-install:
	cd ${WRKDIR} && ${COPYTREE_SHARE} ${PORTNAME} ${STAGEDIR}${WEBAPPDIR}

	${MKDIR} ${STAGEDIR}${MADSONIC_HOME}
	${MKDIR} ${STAGEDIR}${MADSONIC_HOME}/transcode

.include <bsd.port.mk>
