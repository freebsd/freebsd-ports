# Created by: Dreamcat4 <dreamcat4@gmail.com>
# $FreeBSD$

PORTNAME=	universal-media-server
DISTVERSION=	4.0.0-a1
CATEGORIES=	multimedia
MASTER_SITES=	SF/unimediaserver/Official%20Releases/Linux
DISTFILES=	UMS-${DISTVERSION}.tgz

MAINTAINER=	dreamcat4@gmail.com
COMMENT=	Universal Media Server

LICENSE=	GPLv2

USE_JAVA=	yes
JAVA_VERSION=	1.7+
JAVA_VENDOR=	openjdk
JAVA_RUN=	true

OPTIONS_DEFINE=		MEDIAINFO FLAC DCRAW TSMUXER FFMPEG MPLAYER VLC MENCODER
OPTIONS_DEFAULT=	MEDIAINFO FLAC DCRAW TSMUXER

MEDIAINFO_DESC=		Metadata information about video & audio files
MEDIAINFO_LIB_DEPENDS=	libmediainfo.so:${PORTSDIR}/multimedia/mediainfo

#FFMPEG_DESC=		# Transcoder. Use default description
FFMPEG_RUN_DEPENDS=	${LOCALBASE}/bin/ffmpeg:${PORTSDIR}/multimedia/ffmpeg

MPLAYER_DESC=		Transcoder. Pulls in X11 libs
MPLAYER_RUN_DEPENDS=	${LOCALBASE}/bin/mplayer:${PORTSDIR}/multimedia/mplayer

VLC_DESC=		Videolan.org binary 'vlc'. For live web streaming
VLC_RUN_DEPENDS=	${LOCALBASE}/bin/vlc:${PORTSDIR}/multimedia/vlc

MENCODER_DESC=		Transcoder (license Restricted). Not in pkgng
MENCODER_RUN_DEPENDS=	${LOCALBASE}/bin/mencoder:${PORTSDIR}/multimedia/mencoder

TSMUXER_DESC=		To remux streams as TS/M2TS. Requires linux_base
TSMUXER_RUN_DEPENDS=	${LOCALBASE}/bin/tsMuxeR:${PORTSDIR}/multimedia/linux-tsmuxer

#FLAC_DESC=		# Audio file format. Use default description
FLAC_RUN_DEPENDS=	${LOCALBASE}/bin/flac:${PORTSDIR}/audio/flac

DCRAW_DESC=		Better support when viewing photos / still images
DCRAW_RUN_DEPENDS=	${LOCALBASE}/bin/dcraw:${PORTSDIR}/graphics/dcraw

NO_BUILD=		yes
WRKSRC=			${WRKDIR}/ums-${DISTVERSION}
DATADIR=		${JAVASHAREDIR}/${PORTNAME}
USERS=			ums
GROUPS=			ums
UMS_PROFILE_PATH=	/var/db/${PORTNAME}
UMS_LOG_DIR=		/var/log/${PORTNAME}
UMS_PID_DIR=		/var/run/${PORTNAME}

SUB_LIST=	RCNAME=${USE_RC_SUBR} JAVA_HOME=${JAVA_HOME} JAVA=${JAVA} \
		UMS_PROFILE_PATH=${UMS_PROFILE_PATH} UMS_LOG_DIR=${UMS_LOG_DIR} UMS_PID_DIR=${UMS_PID_DIR}
PLIST_SUB=	${SUB_LIST}
SUB_FILES=	pkg-message
USE_RC_SUBR=	universal_media_server

.include <bsd.port.pre.mk>

do-install:
		@${MKDIR} ${STAGEDIR}${UMS_PROFILE_PATH}
		@${CP} ${WRKSRC}/UMS.conf ${STAGEDIR}${UMS_PROFILE_PATH}/UMS.conf.sample
		@${CP} ${WRKSRC}/WEB.conf ${STAGEDIR}${UMS_PROFILE_PATH}/WEB.conf.sample
		@${MKDIR} ${STAGEDIR}${UMS_PID_DIR}
		@${MKDIR} ${STAGEDIR}${UMS_LOG_DIR}

		@${MKDIR} ${STAGEDIR}${DOCSDIR}
		@(cd ${WRKSRC}/documentation && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})
		@(cd ${WRKSRC} && ${RM} -rf documentation)

		@(cd ${WRKSRC}/linux && ${RM} -rf *)
		@(cd ${WRKSRC}/linux && ${LN} -sf ${PREFIX}/bin/tsMuxeR tsMuxeR-new)

		@${MKDIR} ${STAGEDIR}${DATADIR}
		@(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})

.include <bsd.port.post.mk>
