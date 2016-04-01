# Created by: Jeremie Le Hen <jlh@FreeBSD.org>
# Based on www/subsonic-standalone
#
# $FreeBSD$
#

PORTNAME=	madsonic-standalone
PORTVERSION=	5.1
CATEGORIES=	www java
MASTER_SITES=	http://madsonic.org/download/${PORTVERSION}/
DISTNAME=	20140927_madsonic-5.1.5150-standalone

MAINTAINER=	jlh@FreeBSD.org
COMMENT=	Subsonic streaming media server, standalone version

LICENSE=	GPLv3

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

OPTIONS_DEFAULT=	FFMPEG
OPTIONS_SUB=	yes

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
USE_JAVA=	yes
USE_RC_SUBR=	madsonic
JAVA_VERSION=	1.6+
# Don't waste UID/GID and reuse Subsonic's user.
USERS=		subsonic
GROUPS=		subsonic
# Keep the same variable names as in the Subsonic port to minimize diffs.
SUBSONIC_HOME=	/var/madsonic
SUBSONIC_DIR=	${PREFIX}/${PORTDIRNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_SUB+=	SUBSONIC_HOME="${SUBSONIC_HOME}" \
		USER="${USERS}" \
		GROUP="${GROUPS}"
SUB_FILES= 	pkg-message \
		message-transcoding \
		madsonic
SUB_LIST=	SUBSONIC_HOME="${SUBSONIC_HOME}" \
		SUBSONIC_DIR="${SUBSONIC_DIR}" \
		USER="${USERS}" \
		GROUP="${GROUPS}" \
		JAVA="${JAVA}"

do-extract:
	@${MKDIR} ${WRKSRC}
	@${TAR} -xf ${DISTDIR}/${DISTNAME}.tar.gz -C ${WRKSRC} --no-same-owner --no-same-permission

do-install:
	@${CAT} ${PKGDIR}/pkg-message-spacer >> ${PKGMESSAGE}
	@${CAT} ${WRKDIR}/message-transcoding >> ${PKGMESSAGE}
	@${CAT} ${PKGDIR}/pkg-message-spacer >> ${PKGMESSAGE}
	${INSTALL} -d ${STAGEDIR}${SUBSONIC_DIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTDIRNAME}/LICENSE.TXT ${STAGEDIR}${SUBSONIC_DIR}/
	${INSTALL_DATA} ${WRKDIR}/${PORTDIRNAME}/README.TXT ${STAGEDIR}${SUBSONIC_DIR}/
	${INSTALL_DATA} ${WRKDIR}/${PORTDIRNAME}/madsonic.war ${STAGEDIR}${SUBSONIC_DIR}/
	${INSTALL_DATA} ${WRKDIR}/${PORTDIRNAME}/madsonic-booter.jar ${STAGEDIR}${SUBSONIC_DIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTDIRNAME}/madsonic.sh ${STAGEDIR}${SUBSONIC_DIR}/
	${INSTALL} -d ${STAGEDIR}${SUBSONIC_HOME}
	${INSTALL} -d ${STAGEDIR}${SUBSONIC_HOME}/transcode
.if ${PORT_OPTIONS:MFFMEG}
	${LN} -sf ${PREFIX}/bin/ffmeg ${STAGEDIR}${SUBSONIC_HOME}/transcode/ffmpeg
.endif
.if ${PORT_OPTIONS:MFLAC}
	${LN} -sf ${PREFIX}/bin/flac ${STAGEDIR}${SUBSONIC_HOME}/transcode/flac
.endif
.if ${PORT_OPTIONS:MLAME}
	${LN} -sf ${PREFIX}/bin/lame ${STAGEDIR}${SUBSONIC_HOME}/transcode/lame
.endif

.include <bsd.port.mk>
