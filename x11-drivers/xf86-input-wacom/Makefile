# $FreeBSD$

PORTNAME=	xf86-input-wacom
PORTVERSION=	0.38.0
CATEGORIES=	x11-drivers
MASTER_SITES=	https://github.com/linuxwacom/${PORTNAME}/releases/download/${DISTNAME}/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	X.Org Wacom tablet driver

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
RUN_DEPENDS=	webcamd>=3.1.0.1:multimedia/webcamd

USES=		gmake pathfix xorg xorg-cat:driver
USE_XORG=	x11 xext xinerama xrandr
LDFLAGS+=	-Wl,--as-needed # Xext
USE_RC_SUBR=	wacom
SUB_FILES=	pkg-message
CONFIGURE_ENV=	UDEV_CFLAGS=" " UDEV_LIBS=" "
CONFIGURE_ARGS=	--without-systemd-unit-dir \
		--without-udev-rules-dir \
		--without-doxygen

OPTIONS_DEFINE=	DEBUG TEST

DEBUG_CONFIGURE_ENABLE=debug

TEST_CONFIGURE_ENABLE=unit-tests
TEST_ALL_TARGET=check

post-patch:
	@${REINPLACE_CMD} \
		-e 's/dir=.*xorg-server/& \
			--define-variable prefix="$$prefix"/' \
		${WRKSRC}/configure

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/X11/xorg.conf.d
	${INSTALL_DATA} ${FILESDIR}/wacom.conf.sample \
		${STAGEDIR}${PREFIX}/etc/X11/xorg.conf.d

.include <bsd.port.mk>
