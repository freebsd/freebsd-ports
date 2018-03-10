# $FreeBSD$

PORTNAME=	u-boot
PORTVERSION=	2017.01
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.denx.de/pub/u-boot/:uboot \
		LOCAL/db:bootfiles
PKGNAMESUFFIX=	-rpi3
DISTFILES=	u-boot-${PORTVERSION}.tar.bz2:uboot \
		rpi3-boot-files-2016.05.tar.bz2:bootfiles \
		rpi3-psci-monitor-master.tgz:pscimon

MAINTAINER=	db@FreeBSD.org
COMMENT=	Cross-build U-Boot loader for RPi3

LICENSE=	GPLv2

BUILD_DEPENDS=	aarch64-none-elf-gcc:devel/aarch64-none-elf-gcc

USE_GITHUB=	nodefault
GH_ACCOUNT=	gonzoua:pscimon
GH_PROJECT=	rpi3-psci-monitor:pscimon
GIT_TAG=	5782052
GH_TAGNAME=	${GIT_TAG}:pscimon

NO_ARCH=	yes

USES=		gmake tar:bzip2
SSP_UNSAFE=	yes # cross-LD does not support -fstack-protector

WRK_BOOTFILES=	${WRKDIR}/rpi3-boot-files-2016.05
PSCI_MONITOR=	rpi3-psci-monitor-${GIT_TAG}
PSCI_DIR=	${WRKDIR}/${PSCI_MONITOR}

U_BOOT_DIR=	share/u-boot/${PORTNAME}${PKGNAMESUFFIX}
PLIST_FILES=	${U_BOOT_DIR}/u-boot.bin \
		${U_BOOT_DIR}/README \
		${U_BOOT_DIR}/bootcode.bin \
		${U_BOOT_DIR}/fixup.dat \
		${U_BOOT_DIR}/fixup_cd.dat \
		${U_BOOT_DIR}/fixup_db.dat \
		${U_BOOT_DIR}/fixup_x.dat \
		${U_BOOT_DIR}/start.elf \
		${U_BOOT_DIR}/start_cd.elf \
		${U_BOOT_DIR}/start_db.elf \
		${U_BOOT_DIR}/start_x.elf \
		${U_BOOT_DIR}/config.txt \
		${U_BOOT_DIR}/LICENCE.broadcom \
		${U_BOOT_DIR}/armstub8.bin
MAKE_ARGS+=	ARCH=arm \
		CROSS_COMPILE=aarch64-none-elf- \
		CONFIG_EFI=y

do-configure:
	(cd ${WRKSRC}; ${GMAKE} rpi_3_defconfig)

do-build:
	(cd ${WRKSRC}; ${GMAKE} ${MAKE_ARGS})
	(cd ${PSCI_DIR}; ${MAKE})

# The output of the u-boot build process is u-boot.bin.  Older firmware
# versions require a standard header, but the recent versions (our case)
# are capable of booting u-boot.bin directly.  Also copy the entire
# contents of the bootfiles distribution (these are proprietary binary
# files required to boot).
# Also include the armstub8.bin needed to go SMP on RPI3
do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	${INSTALL_DATA} ${WRKSRC}/u-boot.bin ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/
	${INSTALL_DATA} ${DESCR} ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/README
	${INSTALL_DATA} ${WRK_BOOTFILES}/* ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	${INSTALL_DATA} ${PSCI_DIR}/pscimon.bin ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/armstub8.bin

.include <bsd.port.mk>
