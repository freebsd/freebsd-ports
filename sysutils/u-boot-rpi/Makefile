# $FreeBSD$

PORTNAME=	u-boot
PORTVERSION=	2016.01
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.denx.de/pub/u-boot/ \
		LOCAL/ian/:bootfiles
PKGNAMESUFFIX=	-rpi
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		rpi-boot-files-2016.01.tar.bz2:bootfiles

MAINTAINER=	ian@FreeBSD.org
COMMENT=	Cross-build U-Boot loader for Raspberry Pi

LICENSE=	GPLv2

BUILD_DEPENDS=	arm-none-eabi-gcc:devel/arm-none-eabi-gcc

NO_ARCH=	yes

USES=		gmake tar:bzip2
SSP_UNSAFE=	yes # cross-LD does not support -fstack-protector

WRK_BOOTFILES=	${WRKDIR}/rpi-boot-files

U_BOOT_DIR=	share/u-boot/${PORTNAME}${PKGNAMESUFFIX}
PLIST_FILES=	${U_BOOT_DIR}/u-boot.img \
		${U_BOOT_DIR}/LICENCE.broadcom \
		${U_BOOT_DIR}/README-BootDetails \
		${U_BOOT_DIR}/bootcode.bin \
		${U_BOOT_DIR}/config.txt \
		${U_BOOT_DIR}/fixup.dat \
		${U_BOOT_DIR}/fixup_cd.dat \
		${U_BOOT_DIR}/start.elf \
		${U_BOOT_DIR}/start_cd.elf

MAKE_ARGS+=	ARCH=arm \
		CROSS_COMPILE=arm-none-eabi-

do-configure:
	(cd ${WRKSRC}; ${GMAKE} rpi_defconfig)

# The output of the u-boot build process is u-boot.bin.  We have to put a
# standard (for the RPi) image header on the front of it, and the resulting
# file is named u-boot.img.  Also copy the entire contents of the bootfiles
# distribution (these are proprietary binary files required to boot).
IMGFILE=${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/u-boot.img
do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	${GZCAT} ${FILESDIR}/imgprefix.bin.gz >${IMGFILE}
	${CAT} ${WRKSRC}/u-boot.bin >>${IMGFILE}
	${CP} ${WRK_BOOTFILES}/* ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/

.include <bsd.port.mk>
