# $FreeBSD$

PORTNAME=	xwayland
DISTVERSIONPREFIX=	xorg-server-
DISTVERSION=	1.20.0-592
DISTVERSIONSUFFIX=	-g${GL_COMMIT:C/(.{12}).*/\1/}
PORTREVISION=	1
CATEGORIES=	x11-servers
PKGNAMESUFFIX=	-devel

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/commit/
PATCHFILES+=	71749de24509.patch:-p1 # https://gitlab.freedesktop.org/xorg/xserver/merge_requests/393
PATCHFILES+=	1e897704c822.patch:-p1 # https://gitlab.freedesktop.org/xorg/xserver/merge_requests/393
PATCHFILES+=	83cda3ce3195.patch:-p1 # https://gitlab.freedesktop.org/xorg/xserver/merge_requests/393

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	X11 server as Wayland client (development snapshot)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		${LOCALBASE}/include/GL/internal/dri_interface.h:graphics/mesa-dri \
		wayland-protocols>=1.18:graphics/wayland-protocols
LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libepoxy.so:graphics/libepoxy \
		libwayland-client.so:graphics/wayland
RUN_DEPENDS=	xkbcomp:x11/xkbcomp \
		xkeyboard-config>0:x11/xkeyboard-config

CONFLICTS_INSTALL=	${PORTNAME}

USES=		compiler:c11 gl meson pkgconfig xorg
USE_GITLAB=	yes
USE_GL=		gbm gl
USE_XORG=	pixman xau xdmcp xfont2 xkbfile xshmfence xtrans
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	xorg
GL_PROJECT=	xserver
GL_COMMIT=	1cfdd1a96580733df3625bcea3384ffee3dc92df
MESON_ARGS=	-Dxwayland=true \
		-Dxorg=false \
		-Dxnest=false \
		-Dxvfb=false \
		-Dudev=false \
		-Dudev_kms=false \
		-Ddefault_font_path=${NONEXISTENT}
PLIST_FILES=	bin/Xwayland

do-install:
# Wayland compositors only use the binary
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/hw/xwayland/Xwayland \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
