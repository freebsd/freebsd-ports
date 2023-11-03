PORTNAME=	iichid
DISTVERSION=	0.0.6
CATEGORIES=	sysutils

MAINTAINER=	wulf@FreeBSD.org
COMMENT=	Generic FreeBSD HID layer for I2C and USB devices
WWW=		https://github.com/wulf7/iichid

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Merged into base from 13
EXPIRATION_DATE=	2023-12-31
IGNORE_FreeBSD_13=	Is a part of base system
IGNORE_FreeBSD_14=	Is a part of base system
IGNORE_FreeBSD_15=	Is a part of base system

USES=	kmod uidfix

USE_GITHUB=	yes

GH_ACCOUNT=	wulf7

PLIST_FILES=	${KMODDIR}/iichid.ko

# USB backend is disabled by default as it interferes with existing USB drivers
# I2C transport requires architecture supporting ACPI
OPTIONS_DEFINE=		DEBUG I2C USB
OPTIONS_DEFAULT_amd64=	I2C
OPTIONS_DEFAULT_i386=	I2C
OPTIONS_DEFAULT_aarch64=I2C

I2C_DESC=		HID over I2C support
USB_DESC=		HID over USB support

I2C_MAKE_ARGS_OFF=	-DDISABLE_IICHID
USB_MAKE_ARGS_OFF=	-DDISABLE_USBHID

post-patch-DEBUG-off:
	${REINPLACE_CMD} -e '/iichid_debug =/s/1/0/' ${WRKSRC}/iichid.c

.include <bsd.port.mk>
