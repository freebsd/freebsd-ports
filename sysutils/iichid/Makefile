# Created by: jrhett@netconsonance.com
# $FreeBSD$

PORTNAME=	iichid
DISTVERSION=	0.0.3
CATEGORIES=	sysutils

MAINTAINER=	wulf@FreeBSD.org
COMMENT=	Generic FreeBSD HID layer for I2C and USB devices

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

IGNORE_FreeBSD_11=	Requires FreeBSD 12.1 or later
ONLY_FOR_ARCHS=		aarch64 amd64 i386
ONLY_FOR_ARCHS_REASON=	I2C transport requires architecture supporting ACPI

USES=	kmod uidfix

USE_GITHUB=	yes

GH_ACCOUNT=	wulf7

# Strip -Werror from sys/conf/kmod.mk
MAKE_ENV=	WERROR=""

PLIST_FILES=	${KMODDIR}/iichid.ko

# USB backend is disabled by default as it interferes with existing USB drivers
OPTIONS_DEFINE=		DEBUG I2C USB
OPTIONS_DEFAULT=	I2C
I2C_DESC=		HID over I2C support
USB_DESC=		HID over USB support

I2C_MAKE_ARGS_OFF=	-DDISABLE_I2CHID
USB_MAKE_ARGS_OFF=	-DDISABLE_USBHID

post-patch-DEBUG-off:
	${REINPLACE_CMD} -e '/iichid_debug =/s/1/0/' ${WRKSRC}/iichid.c

.include <bsd.port.mk>
