# $FreeBSD$

PORTNAME=	xf86-video-qxl
DISTVERSION=	0.1.5
PORTREVISION=	4
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org X server -- QXL display driver

LICENSE=	MIT

BROKEN=		does not build with xorg-server 1.20.7
DEPRECATED=	Broken, uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

BUILD_DEPENDS=	spice-protocol>=0.12.10:devel/spice-protocol \
		${LOCALBASE}/include/linux/input.h:devel/evdev-proto
LIB_DEPENDS=	libspice-server.so:devel/libspice-server

USES=		localbase:ldflags pkgconfig python:2.7 shebangfix xorg \
		xorg-cat:driver
USE_XORG=	xfont

CONFIGURE_ARGS+=--enable-xspice

python_OLD_CMD=	"/usr/bin/python"
SHEBANG_FILES=	scripts/Xspice

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/X11/xorg.conf.d
	${INSTALL_DATA} ${WRKSRC}/examples/spiceqxl.xorg.conf.example \
		${STAGEDIR}${PREFIX}/etc/X11/xorg.conf.d/spiceqxl.xorg.conf.example

.include <bsd.port.mk>
