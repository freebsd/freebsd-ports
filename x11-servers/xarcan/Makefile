PORTNAME=	xarcan
DISTVERSION=	0.6.3
CATEGORIES=	x11-servers

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 server as Arcan client
WWW=		https://arcan-fe.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/GL/internal/dri_interface.h:graphics/mesa-dri
LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libarcan_shmif_ext.so:multimedia/arcan \
		libxcb-util.so:x11/xcb-util \
		libxcb-icccm.so:x11/xcb-util-wm
RUN_DEPENDS=	xkbcomp:x11/xkbcomp \
		xkeyboard-config>0:x11/xkeyboard-config

USES=		compiler:c11 gl meson pkgconfig xorg
USE_GITHUB=	yes
USE_GL=		gbm gl
USE_XORG=	pixman xau xcb xdmcp xfont2 xkbfile xshmfence xtrans
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
