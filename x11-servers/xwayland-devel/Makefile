# $FreeBSD$

PORTNAME=	xwayland
DISTVERSIONPREFIX=	xorg-server-
DISTVERSION=	1.20.0-641
DISTVERSIONSUFFIX=	-g${GL_COMMIT:C/(.{12}).*/\1/}
PORTREVISION=	1
CATEGORIES=	x11-servers
PKGNAMESUFFIX=	-devel

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/commit/
PATCHFILES+=	71749de24509.diff:-p1 # https://gitlab.freedesktop.org/xorg/xserver/merge_requests/393
PATCHFILES+=	1e897704c822.diff:-p1 # https://gitlab.freedesktop.org/xorg/xserver/merge_requests/393
PATCHFILES+=	83cda3ce3195.diff:-p1 # https://gitlab.freedesktop.org/xorg/xserver/merge_requests/393

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
GL_COMMIT=	785e59060c00129e47da6c0877604a56d7e0e32f
MESON_ARGS=	-Dxwayland=true \
		-Dxorg=false \
		-Dxnest=false \
		-Dxvfb=false \
		-Dudev=false \
		-Dudev_kms=false \
		-Ddefault_font_path="${DEFAULT_FONTPATH_LIST:ts,}"
PLIST_FILES=	bin/Xwayland

# Keep in sync with xorg-server
FONTPATH_ROOT?=	${LOCALBASE}/share/fonts
FONTPATHD?=	${PREFIX}/etc/X11/fontpath.d
DEFAULT_FONTPATH_LIST= \
	${FONTPATH_ROOT}/misc/	\
	${FONTPATH_ROOT}/TTF/ \
	${FONTPATH_ROOT}/OTF/ \
	${FONTPATH_ROOT}/Type1/ \
	${FONTPATH_ROOT}/100dpi/ \
	${FONTPATH_ROOT}/75dpi/ \
	catalogue:${FONTPATHD}

OPTIONS_DEFINE=	NVIDIA

NVIDIA_DESC=		EGLStream support for glamor on Xwayland
NVIDIA_BUILD_DEPENDS=	egl-wayland>0:graphics/egl-wayland
NVIDIA_MESON_TRUE=	xwayland_eglstream

do-install:
# Wayland compositors only use the binary
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/hw/xwayland/Xwayland \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
