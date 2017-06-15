# $FreeBSD$

PORTNAME=	u-boot
PORTVERSION=	2015.04
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.denx.de/pub/u-boot/ \
		LOCAL/loos/rpi2-boot-files:bootfiles
PKGNAMESUFFIX=	-rpi2
DISTFILES=	u-boot-${PORTVERSION}.tar.bz2 \
		rpi2-boot-files-2015.04.tar.bz2:bootfiles

MAINTAINER=	loos@FreeBSD.org
COMMENT=	Cross-build U-Boot loader for Raspberry Pi 2

LICENSE=	GPLv2

BUILD_DEPENDS=	arm-none-eabi-gcc:devel/arm-none-eabi-gcc

NO_ARCH=	yes

WRKSRC=		${WRKDIR}/u-boot-${DISTVERSION}
USES=		gmake tar:bzip2
SSP_UNSAFE=	yes # cross-LD does not support -fstack-protector

WRK_BOOTFILES=	${WRKDIR}/rpi2-boot-files

U_BOOT_DIR=	share/u-boot/${PORTNAME}${PKGNAMESUFFIX}
PLIST_FILES=	${U_BOOT_DIR}/u-boot.bin \
		${U_BOOT_DIR}/README \
		${U_BOOT_DIR}/bootcode.bin \
		${U_BOOT_DIR}/fixup.dat \
		${U_BOOT_DIR}/fixup_cd.dat \
		${U_BOOT_DIR}/fixup_x.dat \
		${U_BOOT_DIR}/start.elf \
		${U_BOOT_DIR}/start_cd.elf \
		${U_BOOT_DIR}/start_x.elf \
		${U_BOOT_DIR}/config.txt \
		${U_BOOT_DIR}/LICENCE.broadcom

MAKE_ARGS+=	ARCH=arm \
		CROSS_COMPILE=arm-none-eabi-

post-patch:
	@${LN} -sf compiler-gcc5.h ${WRKSRC}/include/linux/compiler-gcc6.h

do-configure:
	(cd ${WRKSRC}; ${MAKE_CMD} rpi_2_defconfig)

# The output of the u-boot build process is u-boot.bin.  Older firmware
# versions require a standard header, but the recent versions (our case)
# are capable of booting u-boot.bin directly.  Also copy the entire
# contents of the bootfiles distribution (these are proprietary binary
# files required to boot).
IMGFILE=${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/u-boot.img
do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	${INSTALL_DATA} ${WRKSRC}/u-boot.bin ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	${INSTALL_DATA} ${DESCR} ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/README
	${INSTALL_DATA} ${WRK_BOOTFILES}/* ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}

.include <bsd.port.mk>
