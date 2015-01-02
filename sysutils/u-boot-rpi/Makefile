# $FreeBSD$

PORTNAME=	u-boot
PORTVERSION=	2013.01
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	GH:uboot \
		http://distcache.FreeBSD.org/local-distfiles/ian/:bootfiles \
		http://distcache.us-east.FreeBSD.org/local-distfiles/ian/:bootfiles \
		http://distcache.eu.FreeBSD.org/local-distfiles/ian/:bootfiles \
		http://distcache.us-west.FreeBSD.org/local-distfiles/ian/:bootfiles
PKGNAMESUFFIX=	-rpi
DISTFILES=	u-boot-${PORTVERSION}-${GH_ACCOUNT}-${GH_PROJECT}.tar.gz:uboot \
		rpi-boot-files-2014.10_1.tar.bz2:bootfiles

MAINTAINER=	ian@FreeBSD.org
COMMENT=	Cross-build U-Boot loader for Raspberry Pi

LICENSE=	GPLv2

BUILD_DEPENDS=  arm-none-eabi-gcc:${PORTSDIR}/devel/arm-none-eabi-gcc \
		gsed:${PORTSDIR}/textproc/gsed

USE_GITHUB=	yes
GH_ACCOUNT=	gonzoua
GH_PROJECT=	u-boot-pi
GH_COMMIT=	6709570
GH_TAGNAME=	${GH_COMMIT}

NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-${GH_PROJECT}-${GH_TAGNAME}
USES=		gmake
SSP_UNSAFE=	yes # cross-build static linking dies with -fstack-protector

WRK_BOOTFILES=	${WRKDIR}/rpi-boot-files

U_BOOT_DIR=	share/u-boot/${PORTNAME}${PKGNAMESUFFIX}
PLIST_FILES=	${U_BOOT_DIR}/u-boot.img \
		${U_BOOT_DIR}/LICENCE.broadcom \
		${U_BOOT_DIR}/README \
		${U_BOOT_DIR}/bootcode.bin \
		${U_BOOT_DIR}/config.txt \
		${U_BOOT_DIR}/fixup.dat \
		${U_BOOT_DIR}/fixup_cd.dat \
		${U_BOOT_DIR}/start.elf \
		${U_BOOT_DIR}/start_cd.elf

MAKE_ARGS+=	ARCH=arm \
		CROSS_COMPILE=arm-none-eabi- \
		HOSTCC=cc \
		SED=gsed

do-configure:
	(cd ${WRKSRC}; ${GMAKE} ${MAKE_ARGS} rpi_b_config)

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
