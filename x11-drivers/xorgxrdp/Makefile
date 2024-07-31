PORTNAME=	xorgxrdp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.2
# Be sure to bump PORTREVISION after xorg-server update to force rebuild
PORTREVISION=	0
CATEGORIES=	x11-drivers
DIST_SUBDIR=	xrdp

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/

MAINTAINER=	meta@FreeBSD.org
COMMENT=	X.Org driver enabling use through an RDP session with xrdp
WWW=		https://www.xrdp.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	xauth:x11/xauth
BUILD_DEPENDS=	nasm:devel/nasm

USES=		autoreconf libtool:build localbase pkgconfig xorg
USE_XORG=	xorgproto xorg-server
USE_LDCONFIG=	yes
USE_GITHUB=	yes

GH_ACCOUNT=	neutrinolabs
GH_TUPLE=	neutrinolabs:xrdp:v0.10.1:xrdp
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ENV=	XRDP_CFLAGS=-I${WRKSRC_xrdp}/common
CONFLICTS=	xorgxrdp-devel

OPTIONS_DEFINE=	DEBUG DRI3
OPTIONS_DEFAULT=	DRI3

DRI3_DESC=	DRI3/Glamor OpenGL Support
DRI3_CONFIGURE_ENABLE=	glamor
DRI3_LIB_DEPENDS=	libepoxy.so:graphics/libepoxy
DRI3_CFLAGS=		-I${LOCALBASE}/include/libdrm
DRI3_SUB_FILES=		pkg-message

post-patch-DEBUG-on:
	${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e 's|#define LOG_LEVEL [0-9]*|#define LOG_LEVEL 20|'

pre-configure:
	@cd ${WRKSRC} && ./bootstrap

.include <bsd.port.mk>
