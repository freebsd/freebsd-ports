PORTNAME=	xlibre-xf86-input-wacom
PORTVERSION=	1.2.3.2
CATEGORIES=	x11-drivers

MAINTAINER=	b-aazbsd@proton.me
COMMENT=	XLibre legacy Wacom tablet driver
WWW=		https://github.com/X11Libre/xf86-input-wacom/ \
		https://linuxwacom.github.io/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GPL

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
RUN_DEPENDS=	webcamd>=3.1.0.1:multimedia/webcamd

CONFLICTS_INSTALL=	xf86-input-wacom

USES=		gmake pathfix xorg xlibre-cat:driver
USE_XORG=	x11 xext xinerama xrandr
LDFLAGS+=	-Wl,--as-needed # Xext
USE_RC_SUBR=	wacom
SUB_FILES=	pkg-message
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ENV=	UDEV_CFLAGS=" " UDEV_LIBS=" "
CONFIGURE_ARGS=	--without-systemd-unit-dir \
		--without-udev-rules-dir \
		--without-doxygen

OPTIONS_DEFINE=	DEBUG TEST

DEBUG_CONFIGURE_ENABLE=debug

TEST_CONFIGURE_ENABLE=unit-tests
TEST_ALL_TARGET=check

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/X11/xorg.conf.d
	${INSTALL_DATA} ${FILESDIR}/wacom.conf.sample \
		${STAGEDIR}${PREFIX}/etc/X11/xorg.conf.d

.include <bsd.port.mk>
