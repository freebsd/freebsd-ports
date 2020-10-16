# $FreeBSD$

PORTNAME=	mpc-qt
DISTVERSIONPREFIX=	v
DISTVERSION=	20.10
CATEGORIES=	multimedia audio

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Qt 5 clone of Media Player Classic based on libmpv

LICENSE=	GPLv2

BUILD_DEPENDS=	mpv>=0.29,1:multimedia/mpv
LIB_DEPENDS=	libmpv.so:multimedia/mpv

USE_GITHUB=	yes
GH_ACCOUNT=	cmdrkotori
GH_PROJECT=	${PORTNAME}-origin

USES=		compiler:c++14-lang desktop-file-utils gl pkgconfig qmake qt:5
USE_QT=		qmake_build buildtools_build linguisttools_build \
		core dbus gui network svg_run widgets x11extras
USE_GL=		gl

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
