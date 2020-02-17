# Created by: jrhett@netconsonance.com
# $FreeBSD$

PORTNAME=	iichid
DISTVERSION=	0.0.1
CATEGORIES=	sysutils

MAINTAINER=	imp@FreeBSD.org
COMMENT=	Generic FreeBSD HID layer for I2C and USB devices

LICENSE=	BSD2CLAUSE
#LICENSE_FILE=	Not yet packaged

ONLY_FOR_ARCHS=		aarch64 amd64 i386
ONLY_FOR_ARCHS_REASON=	Requires architecture supporting ACPI

USES=	kmod uidfix

USE_GITHUB=	yes

GH_ACCOUNT=	wulf7

# Strip -Werror from sys/conf/kmod.mk
MAKE_ENV=	WERROR=""

PLIST_FILES=	${KMODDIR}/iichid.ko

# USB backend is not yet complete and
# interferes with existing USB drivers
post-patch:
	${REINPLACE_CMD} -e '/usbhid.c/s/^/#/' ${WRKSRC}/Makefile

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1201000
IGNORE=	requires FreeBSD versions 12.1+, this system is running ${OSREL}
.endif

.include <bsd.port.post.mk>
