PORTNAME=	mpc-qt
DISTVERSIONPREFIX=	v
DISTVERSION=	23.02
PORTREVISION=	1
CATEGORIES=	multimedia audio

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Qt 5 clone of Media Player Classic based on libmpv
WWW=		https://github.com/mpc-qt/mpc-qt

LICENSE=	GPLv2

BUILD_DEPENDS=	mpv>=0.29,1:multimedia/mpv
LIB_DEPENDS=	libmpv.so:multimedia/mpv

USES=		compiler:c++14-lang desktop-file-utils gl pkgconfig qmake qt:5
USE_GITHUB=	yes
USE_GL=		gl
USE_QT=		qmake:build buildtools:build linguisttools:build \
		core dbus gui network svg:run widgets x11extras
QMAKE_ARGS=	MPCQT_VERSION="${DISTVERSION}${DISTVERSIONSUFFIX}"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
