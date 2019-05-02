# $FreeBSD$

PORTNAME=	FFaudioConverter
DISTVERSIONPREFIX=	v
DISTVERSION=	0.26
CATEGORIES=	multimedia audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Graphical audio covert and filter tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

USES=		compiler:c++11-lang desktop-file-utils gl qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	Bleuzen
USE_QT=		concurrent core gui widgets buildtools_build linguisttools_build
USE_GL=		gl

PLIST_FILES=	bin/ffaudioconverter \
		share/applications/com.github.Bleuzen.FFaudioConverter.desktop \
		share/icons/hicolor/512x512/apps/com.github.Bleuzen.FFaudioConverter.png \
		share/metainfo/com.github.Bleuzen.FFaudioConverter.appdata.xml

post-patch:
	@${REINPLACE_CMD} 's|DEFAULT_FFMPEG_BINARY = .*|DEFAULT_FFMPEG_BINARY = ${LOCALBASE}/bin/ffmpeg|' ${WRKSRC}/FFaudioConverter.pro

.include <bsd.port.mk>
