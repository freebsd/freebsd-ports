PORTNAME=	xwayland
PORTVERSION=	23.2.6
PORTEPOCH=	1
CATEGORIES=	x11-servers
MASTER_SITES=	XORG/individual/xserver

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	cd6c9c1246af.patch:-p1 # https://gitlab.freedesktop.org/xorg/xserver/-/merge_requests/432
PATCHFILES+=	707c37b7ab9e.patch:-p1 # https://gitlab.freedesktop.org/xorg/xserver/-/merge_requests/432
PATCHFILES+=	3b0d1a3a2296.patch:-p1 # https://gitlab.freedesktop.org/xorg/xserver/-/merge_requests/432

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X11 server as Wayland client
WWW=		https://wayland.freedesktop.org/xserver.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		${LOCALBASE}/include/GL/internal/dri_interface.h:graphics/mesa-dri \
		wayland-protocols>=1.30:graphics/wayland-protocols
LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libepoxy.so:graphics/libepoxy \
		libwayland-client.so:graphics/wayland \
		libxcvt.so:x11/libxcvt
RUN_DEPENDS=	xkbcomp:x11/xkbcomp \
		xkeyboard-config>0:x11/xkeyboard-config

CONFLICTS_INSTALL=	${PORTNAME}-devel

USES=		compiler:c11 gl meson pkgconfig xorg tar:xz
USE_GL=		gbm gl
USE_XORG=	pixman xau xdmcp xfont2 xkbfile xshmfence xtrans

MESON_ARGS=	-Dxvfb=false \
		-Dxcsecurity=true \
		-Dxkb_output_dir=/var/lib/xkb \
		-Ddefault_font_path="${DEFAULT_FONTPATH_LIST:ts,}"

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

OPTIONS_DEFINE=		CSD EI NVIDIA
OPTIONS_DEFAULT=	CSD EI

CSD_DESC=		Client-side decorations via libdecor
CSD_LIB_DEPENDS=	libdecor-0.so:x11-toolkits/libdecor
CSD_MESON_TRUE=		libdecor

EI_DESC=		Emulated input via libei
EI_LIB_DEPENDS=		libei.so:x11/libei
EI_MESON_OFF=		-Dxwayland_ei=false

NVIDIA_DESC=		EGLStream support for glamor on Xwayland
NVIDIA_BUILD_DEPENDS=	egl-wayland>0:graphics/egl-wayland
NVIDIA_MESON_TRUE=	xwayland_eglstream

.include <bsd.port.mk>
