# Created by: Jeremie Le Hen <jlh@FreeBSD.org>
# $FreeBSD$
#
# Based on www/subsonic-standalone
#

PORTNAME=	madsonic-standalone
PORTVERSION=	6.0
DISTVERSIONSUFFIX=	.7860
PORTREVISION=	7
DISTDATE=	20160109
CATEGORIES=	www java
MASTER_SITES=	http://madsonic.org/download/${PORTVERSION}/
DISTNAME=	${DISTDATE}_madsonic-${PORTVERSION}${DISTVERSIONSUFFIX}-standalone

MAINTAINER=	jlh@FreeBSD.org
COMMENT=	Subsonic streaming media server, standalone version

BROKEN=		unfetchable

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

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_JAVA=	yes
USE_RC_SUBR=	madsonic
JAVA_RUN=	yes
# Don't waste UID/GID and reuse Subsonic's user.
USERS=		subsonic
GROUPS=		subsonic
# Keep the same variable names as in the Subsonic port to minimize diffs.
SUBSONIC_HOME=	/var/madsonic
PLIST_SUB+=	SUBSONIC_HOME="${SUBSONIC_HOME}" \
		USER="${USERS}" \
		GROUP="${GROUPS}"
SUB_FILES=	pkg-message \
		message-transcoding
SUB_LIST=	SUBSONIC_HOME="${SUBSONIC_HOME}" \
		USER="${USERS}" \
		GROUP="${GROUPS}" \
		JAVA="${JAVA}"

CONFLICTS_INSTALL=	madsonic-jetty madsonic-resin3 madsonic-tomcat[678]

do-install:
	${ECHO_CMD} "[" >> ${PKGMESSAGE}
	${ECHO_CMD} "{ type: install, message: <<EOM" >> ${PKGMESSAGE}
	${CAT} ${WRKDIR}/message-transcoding >> ${PKGMESSAGE}
	${ECHO_CMD} "EOM" >> ${PKGMESSAGE}
	${ECHO_CMD} "}" >> ${PKGMESSAGE}
	${ECHO_CMD} "]" >> ${PKGMESSAGE}
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/madsonic.war ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/madsonic-booter.jar ${STAGEDIR}${DATADIR}/

post-install:
	${MKDIR} ${STAGEDIR}${SUBSONIC_HOME}/transcode

post-install-FFMPEG-on:
	${LN} -sf ${PREFIX}/bin/ffmpeg ${STAGEDIR}${SUBSONIC_HOME}/transcode/ffmpeg

post-install-FLAC-on:
	${LN} -sf ${PREFIX}/bin/flac ${STAGEDIR}${SUBSONIC_HOME}/transcode/flac

post-install-LAME-on:
	${LN} -sf ${PREFIX}/bin/lame ${STAGEDIR}${SUBSONIC_HOME}/transcode/lame

.include <bsd.port.mk>
