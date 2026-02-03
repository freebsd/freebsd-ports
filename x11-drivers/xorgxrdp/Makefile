PORTNAME=	xorgxrdp
DISTVERSION=	0.10.5
# Be sure to bump PORTREVISION after xorg-server update to force rebuild
PORTREVISION=	0
CATEGORIES=	x11-drivers
MASTER_SITES=	https://github.com/neutrinolabs/${PORTNAME}/releases/download/v${DISTVERSION}/ \
		https://github.com/neutrinolabs/xrdp/releases/download/v${XRDPVER}/:xrdp
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		xrdp-${XRDPVER}${EXTRACT_SUFX}:xrdp
DIST_SUBDIR=	xrdp

PATCH_SITES=	https://github.com/neutrinolabs/${PORTNAME}/commit/:commit \
		https://github.com/neutrinolabs/${PORTNAME}/pull/:pull
PATCHFILES+=	f5a07e9.patch:-p1:commit
PATCHFILES+=	e1c82b4.patch:-p1:commit
PATCHFILES+=	1c93081.patch:-p1:commit
PATCHFILES+=	58e6a64.patch:-p1:commit

MAINTAINER=	meta@FreeBSD.org
COMMENT=	X.Org driver enabling use through an RDP session with xrdp
WWW=		https://www.xrdp.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	nasm:devel/nasm
RUN_DEPENDS=	xauth:x11/xauth

FLAVORS=	xorg xlibre
FLAVOR?=	${FLAVORS:[1]}

USES=		autoreconf libtool:build localbase pkgconfig
USE_LDCONFIG=	yes
USE_XORG=	xorgproto

.if ${FLAVOR} == xlibre
PKGNAMEPREFIX=	xlibre-
USES+=		xlibre
USE_XLIBRE+=	xlibre-server
_XLIBRE_MAJOR_VER=	25
_XMODDIR=	lib/xorg/modules/xlibre-${_XLIBRE_MAJOR_VER}
.else
USE_XORG=	xorg-server
USES+=		xorg
_XMODDIR=	lib/xorg/modules
.endif

XRDPVER=		0.10.5
# xorg:   /usr/local/lib/xorg/modules
# xlibre: /usr/local/lib/xorg/modules/xlibre-25
# This works but != should be avoided
#_XMODDIR!=	pkgconf --variable moduledir xorg-server | sed -e "s|^${LOCALBASE}/||"

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	XRDP_CFLAGS=-I${WRKDIR}/xrdp-${XRDPVER}/common
INSTALL_TARGET=	install-strip

CONFLICTS=	xorgxrdp-devel

PLIST_SUB+=	XMODDIR=${_XMODDIR}

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
