# Created by: Pawel Pekala <pawel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	smtube
PORTVERSION=	18.9.0
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	SF/smtube/SMTube/${PORTVERSION}/

MAINTAINER=	kikadf.01@gmail.com
COMMENT=	SMPlayer YouTube browser

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/Copying.txt

USES=		gl gmake qt:5 tar:bzip2
USE_GL=		gl
USE_QT=		qmake_build buildtools_build linguisttools_build \
		core network script gui webkit widgets

ALL_TARGET=	#empty
MAKE_ARGS=	DATA_PATH="${DATADIR}" DOC_PATH="${DOCSDIR}" \
		LRELEASE="${LRELEASE}" MAKE="${MAKE_CMD}" \
		QMAKE="${QMAKE}"

PORTDOCS=	*

OPTIONS_MULTI=		PLAYER
OPTIONS_MULTI_PLAYER=	MPLAYER MPV SMPLAYER VLC
OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	QT5 SMPLAYER

PLAYER_DESC=	Video player
MPLAYER_DESC=	MPlayer dependency for video playback
MPV_DESC=	mpv dependency for video playback
SMPLAYER_DESC=	SMPlayer dependency for video playback
VLC_DESC=	VLC dependency for video playback

MPLAYER_RUN_DEPENDS=		mplayer:multimedia/mplayer
MPV_RUN_DEPENDS=		mpv:multimedia/mpv
SMPLAYER_RUN_DEPENDS=		smplayer:multimedia/smplayer
VLC_RUN_DEPENDS=		vlc:multimedia/vlc

post-patch:
	@${REINPLACE_CMD} 's|$$(QMAKE_OPTS)|${QMAKE_ARGS:S,\$,\$\$,g}|' \
		${WRKSRC}/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
