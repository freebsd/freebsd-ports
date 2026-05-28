PORTNAME=	rpi-usbboot
DISTVERSION=	20260603
CATEGORIES=	sysutils

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Raspberry Pi USB device provisioning tool
WWW=		https://github.com/raspberrypi/usbboot

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	raspberrypi
GH_PROJECT=	usbboot
GH_TAGNAME=	58c1051777998637083b9d7d8b8700dabf97d468

ALL_TARGET=	rpiboot
MAKE_ARGS=	INSTALL_PREFIX=${PREFIX} PKG_VER=${DISTVERSION}

.include <bsd.port.mk>
