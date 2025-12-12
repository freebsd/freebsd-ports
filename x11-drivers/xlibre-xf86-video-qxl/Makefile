PORTNAME=	xlibre-xf86-video-qxl
DISTVERSION=	0.1.6.3
CATEGORIES=	x11-drivers

MAINTAINER=	b-aazbsd@proton.me
COMMENT=	XLibre X server -- QXL display driver
WWW=		https://github.com/X11Libre/xf86-video-qxl/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS_INSTALL=	xf86-video-qxl

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
		spice-protocol>=0.12.10:devel/spice-protocol
LIB_DEPENDS=	libspice-server.so:devel/libspice-server \
		libudev.so:devel/libudev-devd

USES=		localbase:ldflags pkgconfig python shebangfix tar:xz xorg \
		xlibre-cat:driver
USE_XORG=	xfont2

python_OLD_CMD=	/usr/bin/python
SHEBANG_FILES=	scripts/Xspice

CONFIGURE_ARGS+=	--enable-xspice

OPTIONS_DEFINE=	DOCS

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:C/xlibre-//}

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/X11/xorg.conf.d

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/spiceqxl.xorg.conf.example \
	    ${STAGEDIR}${PREFIX}/etc/X11/xorg.conf.d/spiceqxl.xorg.conf.example

.include <bsd.port.mk>
