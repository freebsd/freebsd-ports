# $FreeBSD$

PORTNAME=	xorgxrdp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.11
CATEGORIES=	x11-drivers
DIST_SUBDIR=	xrdp

MAINTAINER=	meta@FreeBSD.org
COMMENT=	X.Org driver enabling use through an RDP session with xrdp

LICENSE=	MIT

RUN_DEPENDS=	xauth:x11/xauth
BUILD_DEPENDS=	nasm:devel/nasm

USES=		autoreconf libtool:build pkgconfig xorg
USE_XORG=	xorgproto xorg-server
USE_LDCONFIG=	yes
USE_GITHUB=	yes

GH_ACCOUNT=	neutrinolabs
GH_PROJECT=	xrdp:xrdp
GH_TAGNAME=	v0.9.11:xrdp
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

CFLAGS+=	-I${LOCALBASE}/include
LIBS=		-I${LOCALBASE}/lib
CONFIGURE_ENV=	XRDP_CFLAGS=-I${WRKSRC_xrdp}/common

OPTIONS_DEFINE=	DEBUG

post-patch-DEBUG-on:
	${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e 's|#define LOG_LEVEL [0-9]*|#define LOG_LEVEL 20|'

pre-configure:
	@cd ${WRKSRC} && ./bootstrap

.include <bsd.port.mk>
