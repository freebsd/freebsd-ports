PORTNAME=	mpc-qt
DISTVERSIONPREFIX=	v
DISTVERSION=	24.12
CATEGORIES=	multimedia audio

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Media Player Classic Qute Theater
WWW=		https://github.com/mpc-qt/mpc-qt

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	mpv>=0.29,1:multimedia/mpv
LIB_DEPENDS=	libmpv.so:multimedia/mpv

USES=		compiler:c++17-lang desktop-file-utils gl pkgconfig qmake qt:6
USE_GITHUB=	yes
USE_GL=		opengl
USE_QT=		base svg tools:build
QMAKE_ARGS=	MPCQT_VERSION="${DISTVERSION}"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
