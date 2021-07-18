PORTNAME=	mpc-qt
DISTVERSIONPREFIX=	v
DISTVERSION=	20.10
PORTREVISION=	1
CATEGORIES=	multimedia audio

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Qt 5 clone of Media Player Classic based on libmpv

LICENSE=	GPLv2

BUILD_DEPENDS=	mpv>=0.29,1:multimedia/mpv
LIB_DEPENDS=	libmpv.so:multimedia/mpv

USES=		compiler:c++14-lang desktop-file-utils gl pkgconfig qmake qt:5
USE_GITHUB=	yes
USE_GL=		gl
USE_QT=		qmake_build buildtools_build linguisttools_build \
		core dbus gui network svg_run widgets x11extras

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
