PORTNAME=	xorgxrdp
DISTVERSION=	0.10.4
# Be sure to bump PORTREVISION after xorg-server update to force rebuild
PORTREVISION=	2
CATEGORIES=	x11-drivers
MASTER_SITES=	https://github.com/neutrinolabs/${PORTNAME}/releases/download/v${DISTVERSION}/ \
		https://github.com/neutrinolabs/xrdp/releases/download/v${XRDPVER}/:xrdp
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		xrdp-${XRDPVER}${EXTRACT_SUFX}:xrdp
DIST_SUBDIR=	xrdp

PATCH_SITES=	https://github.com/neutrinolabs/${GH_PROJECT}/commit/

MAINTAINER=	meta@FreeBSD.org
COMMENT=	X.Org driver enabling use through an RDP session with xrdp
WWW=		https://www.xrdp.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	nasm:devel/nasm
RUN_DEPENDS=	xauth:x11/xauth

USES=		autoreconf libtool:build localbase pkgconfig xorg
USE_LDCONFIG=	yes
USE_XORG=	xorg-server xorgproto

XRDPVER=		0.10.4.1

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	XRDP_CFLAGS=-I${WRKDIR}/xrdp-${XRDPVER}/common
INSTALL_TARGET=	install-strip

CONFLICTS=	xorgxrdp-devel

OPTIONS_DEFINE=		DEBUG DRI3
OPTIONS_DEFAULT=	DRI3

DRI3_DESC=		DRI3/Glamor OpenGL Support
DRI3_BUILD_DEPENDS=	${LOCALBASE}/include/libdrm/drm.h:graphics/libdrm
DRI3_LIB_DEPENDS=	libepoxy.so:graphics/libepoxy
DRI3_CONFIGURE_ENABLE=	glamor
DRI3_CFLAGS=		-I${LOCALBASE}/include/libdrm
DRI3_SUB_FILES=		pkg-message

# Bug 285815
NO_SHLIB_REQUIRES_GLOB=	libglamoregl.so

post-patch-DEBUG-on:
	${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e 's|#define LOG_LEVEL [0-9]*|#define LOG_LEVEL 20|'

pre-configure:
	@cd ${WRKSRC} && ./bootstrap

.include <bsd.port.mk>
