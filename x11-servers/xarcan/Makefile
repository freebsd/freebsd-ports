# $FreeBSD$

PORTNAME=	xarcan
DISTVERSION=	0.5.4-1
DISTVERSIONSUFFIX=	-g8f075d78b
CATEGORIES=	x11-servers

PATCH_SITES=	https://github.com/freedesktop/xorg-xserver/commit/
PATCHFILES+=	98dc1228f407.patch:-p1 # https://gitlab.freedesktop.org/xorg/xserver/-/merge_requests/292
PATCHFILES+=	c7486613b0dc.patch:-p1 # https://gitlab.freedesktop.org/xorg/xserver/-/merge_requests/304
PATCHFILES+=	3340ddf37743.patch:-p1 # https://gitlab.freedesktop.org/xorg/xserver/-/merge_requests/305
PATCHFILES+=	622eea366aaf.patch:-p1 # https://gitlab.freedesktop.org/xorg/xserver/-/merge_requests/318
PATCHFILES+=	741bd73429e3.patch:-p1 # https://gitlab.freedesktop.org/xorg/xserver/-/merge_requests/322
PATCHFILES+=	f2cf236da8e8.patch:-p1 # https://gitlab.freedesktop.org/xorg/xserver/-/merge_requests/393
PATCHFILES+=	be731e0bdc7d.patch:-p1 # https://gitlab.freedesktop.org/xorg/xserver/-/merge_requests/393
PATCHFILES+=	b5b529799a20.patch:-p1 # https://gitlab.freedesktop.org/xorg/xserver/-/merge_requests/393
PATCHFILES+=	fb310852f67d.patch:-p1 # https://github.com/letoram/xarcan/pull/7

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	X11 server as Arcan client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/GL/internal/dri_interface.h:graphics/mesa-dri
LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libarcan_shmif_ext.so:multimedia/arcan
RUN_DEPENDS=	xkbcomp:x11/xkbcomp \
		xkeyboard-config>0:x11/xkeyboard-config

USES=		compiler:c11 gl meson pkgconfig xorg
USE_GITHUB=	yes
USE_GL=		gbm gl
USE_XORG=	pixman xau xdmcp xfont2 xkbfile xshmfence xtrans
GH_ACCOUNT=	letoram
MESON_ARGS=	-D${PORTNAME}=true \
		-Dxorg=false \
		-Dxnest=false \
		-Dxvfb=false \
		-Dxwayland=false \
		-Dudev=false \
		-Dudev_kms=false \
		-Ddefault_font_path="${DEFAULT_FONTPATH_LIST:ts,}"
PLIST_FILES=	bin/Xarcan

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

do-install:
# XXX Prevent Meson from installing unrelated files
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/hw/kdrive/arcan/Xarcan \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
