PORTNAME=	mpc-qt
DISTVERSIONPREFIX=	v
DISTVERSION=	25.07
CATEGORIES=	multimedia audio

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Media Player Classic Qute Theater
WWW=		https://github.com/mpc-qt/mpc-qt

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		mpv>=0.37,1:multimedia/mpv
LIB_DEPENDS=	libmpv.so:multimedia/mpv

USES=		cmake compiler:c++17-lang desktop-file-utils gl pkgconfig qt:6
USE_GITHUB=	yes
USE_GL=		opengl
USE_QT=		base svg tools:build
CMAKE_ARGS=	-DMPCQT_VERSION="${DISTVERSION}"

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/io.github.mpc_qt.mpc-qt.desktop \
		share/icons/hicolor/scalable/apps/mpc-qt.svg \
		share/metainfo/io.github.mpc_qt.mpc-qt.appdata.xml
PORTDOCS=	ipc.md

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
