# $FreeBSD$

PORTNAME=	libva-utils
PORTVERSION=	2.6.0
PORTREVISION=	1
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	4aeb5254a191.patch:-p1 # https://github.com/intel/libva-utils/pull/183
PATCHFILES+=	520ea5582c9a.patch:-p1 # https://github.com/intel/libva-utils/pull/184
PATCHFILES+=	24a87768547a.patch:-p1 # https://github.com/intel/libva-utils/pull/184
PATCHFILES+=	fde08663af79.patch:-p1 # https://github.com/intel/libva-utils/pull/184

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Collection of tests and utilities for VAAPI

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libva-drm.so:multimedia/libva

USES=		compiler:c++11-lang meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	intel

OPTIONS_DEFINE=	WAYLAND X11
OPTIONS_DEFAULT=WAYLAND X11
OPTIONS_SUB=	yes

WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_MESON_TRUE=	wayland

X11_USES=		xorg
X11_USE=		XORG=x11,xext,xfixes
X11_MESON_TRUE=		x11

.include <bsd.port.mk>
