# Created by: Pawel Pekala <pawel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	smtube
PORTVERSION=	18.9.0
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	SF/smtube/SMTube/${PORTVERSION}/

MAINTAINER=	kikadf.01@gmail.com
COMMENT=	SMPlayer YouTube browser

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/Copying.txt

USES=		gmake tar:bzip2

ALL_TARGET=	#empty
MAKE_ARGS=	DATA_PATH="${DATADIR}" DOC_PATH="${DOCSDIR}" \
		LRELEASE="${LRELEASE}" MAKE="${MAKE_CMD}" \
		QMAKE="${QMAKE}"

PORTDOCS=	*

OPTIONS_SINGLE=		TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	QT4 QT5
OPTIONS_MULTI=		PLAYER
OPTIONS_MULTI_PLAYER=	MPLAYER MPV SMPLAYER VLC
OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	QT5 SMPLAYER

TOOLKIT_DESC=	Qt toolkit version
PLAYER_DESC=	Video player
MPLAYER_DESC=	MPlayer dependency for video playback
MPV_DESC=	mpv dependency for video playback
SMPLAYER_DESC=	SMPlayer dependency for video playback
VLC_DESC=	VLC dependency for video playback

QT4_USES=	qt:4
QT4_USE=	qt=qmake_build,moc_build,rcc_build,uic_build
QT4_USE+=	qt=corelib,network,script,gui,webkit,linguisttools_build

QT5_USES=	gl qt:5
QT5_USE=	qt=qmake_build,buildtools_build,linguisttools_build
QT5_USE+=	qt=core,network,script,gui,webkit,widgets gl=gl

MPLAYER_RUN_DEPENDS=		mplayer:multimedia/mplayer
MPV_RUN_DEPENDS=		mpv:multimedia/mpv
SMPLAYER_RUN_DEPENDS=		smplayer:multimedia/smplayer
VLC_RUN_DEPENDS=		vlc:multimedia/vlc

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQT4}
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15
.endif

post-patch:
	@${REINPLACE_CMD} 's|$$(QMAKE_OPTS)|${QMAKE_ARGS:S,\$,\$\$,g}|' \
		${WRKSRC}/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
