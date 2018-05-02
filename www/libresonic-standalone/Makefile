# Created by: Jeremie Le Hen <jlh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libresonic
DISTVERSIONPREFIX=	v
DISTVERSION=	6.2
PORTREVISION=	1
CATEGORIES=	www java
MASTER_SITES=	https://github.com/Libresonic/libresonic/releases/download/v${DISTVERSION}/
PKGNAMESUFFIX=	-standalone
EXTRACT_SUFX=	.war

MAINTAINER=	jlh@FreeBSD.org
COMMENT=	Subsonic streaming media server, standalone version

USE_JAVA=	yes
USE_RC_SUBR=	libresonic

LICENSE=	GPLv3

OPTIONS_GROUP=	TRANSCODING
TRANSCODING_DESC=	Transcoding support
OPTIONS_GROUP_TRANSCODING=	FFMPEG FLAC LAME VORBIS FAAC FAAD XMP MPC APE
APE_DESC=	Depend on mac for Monkey's Audio transcoding #'
FAAC_DESC=	Depend on FAAD for AAC/M4A transcoding
FAAD_DESC=	Depend on FAAC for AAC/M4A transcoding
FFMPEG_DESC=	Depend on FFmpeg for audio and video transcoding
FLAC_DESC=	Depend on FLAC for transcoding
LAME_DESC=	Depend on LAME for MP3 transcoding
MPC_DESC=	Depend on mpcdec for MPC transcoding
VORBIS_DESC=	Depend on oggenc/oggdec for Vorbis transcoding
XMP_DESC=	Depend on XMP for module file transcoding

OPTIONS_DEFAULT=	FFMPEG
OPTIONS_SUB=	yes

APE_RUN_DEPENDS=	mac:audio/mac
FAAC_RUN_DEPENDS=	faac:audio/faac
FAAD_RUN_DEPENDS=	faad:audio/faad
FFMPEG_RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg
FLAC_RUN_DEPENDS=	flac:audio/flac
LAME_RUN_DEPENDS=	lame:audio/lame
MPC_RUN_DEPENDS=	mpcdec:audio/musepack
VORBIS_RUN_DEPENDS=	oggenc:audio/vorbis-tools
XMP_RUN_DEPENDS=	xmp:audio/xmp

# We don't want to extract the .war file, just copy it.
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	libresonic.war

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
JAVA_VERSION=	1.8+
JAVA_RUN=	yes
# Don't waste UID/GID and reuse Subsonic's user.
USERS=		subsonic
GROUPS=		subsonic
LIBRESONIC_HOME=	/var/libresonic
PLIST_SUB=	LIBRESONIC_HOME="${LIBRESONIC_HOME}" \
		USER="${USERS}" \
		GROUP="${GROUPS}"
SUB_FILES=	pkg-message
SUB_LIST=	LIBRESONIC_HOME="${LIBRESONIC_HOME}" \
		USER="${USERS}" \
		GROUP="${GROUPS}" \
		JAVA="${JAVA}"

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/libresonic.war ${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${LIBRESONIC_HOME}/transcode

do-install-FFMPEG-on:
	${RLN} ${PREFIX}/bin/ffmpeg ${STAGEDIR}${LIBRESONIC_HOME}/transcode/ffmpeg

do-install-FLAC-on:
	${RLN} ${PREFIX}/bin/flac ${STAGEDIR}${LIBRESONIC_HOME}/transcode/flac

do-install-LAME-on:
	${RLN} ${PREFIX}/bin/lame ${STAGEDIR}${LIBRESONIC_HOME}/transcode/lame

.include <bsd.port.mk>
