PORTNAME=	xf86-video-qxl
DISTVERSION=	0.1.5
PORTREVISION=	5
CATEGORIES=	x11-drivers

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	X.Org X server -- QXL display driver
WWW=		https://www.x.org/

LICENSE=	MIT

BUILD_DEPENDS=	spice-protocol>=0.12.10:devel/spice-protocol \
		${LOCALBASE}/include/linux/input.h:devel/evdev-proto
LIB_DEPENDS=	libspice-server.so:devel/libspice-server \
		libudev.so:devel/libudev-devd

USES=		localbase:ldflags pkgconfig python shebangfix xorg \
		xorg-cat:driver
USE_XORG=	xfont2

CONFIGURE_ARGS+=--enable-xspice

python_OLD_CMD=	/usr/bin/python
SHEBANG_FILES=	scripts/Xspice

OPTIONS_DEFINE=	DOCS

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/X11/xorg.conf.d

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/spiceqxl.xorg.conf.example \
	    ${STAGEDIR}${PREFIX}/etc/X11/xorg.conf.d/spiceqxl.xorg.conf.example

.include <bsd.port.mk>
