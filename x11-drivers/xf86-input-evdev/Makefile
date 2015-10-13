# $FreeBSD$

PORTNAME=	xf86-input-evdev
PORTVERSION=	2.9.2
PORTREVISION=	1
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org event device input driver

LICENSE=	MIT # various styles
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	v4l_compat>=1.0.20110603:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	libevdev.so:${PORTSDIR}/devel/libevdev
RUN_DEPENDS=	webcamd>=3.1.0.1:${PORTSDIR}/multimedia/webcamd

XORG_CAT=	driver
USES=		pathfix
CONFIGURE_ENV=	UDEV_CFLAGS=" " UDEV_LIBS=" "
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	MULTITOUCH

MULTITOUCH_DESC=	XInput 2.2 multitouch support
MULTITOUCH_LIB_DEPENDS=	libmtdev.so:${PORTSDIR}/devel/libmtdev

post-patch-MULTITOUCH-off:
# XXX Convert to CONFIGURE_ENV
	@${REINPLACE_CMD} -i '.mtdev.bak' \
		-e '/PKG_CONFIG/s/mtdev/nonexistent/' \
		${WRKSRC}/configure

.include <bsd.port.mk>
