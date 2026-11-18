PORTNAME=	atf
DISTVERSION=	2.14.0.20260520
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-mt7986

MAINTAINER=	hayzam@alchemilla.io
COMMENT=	Arm TF-A BL2 and BL31 for MediaTek MT7986
WWW=		https://github.com/mtk-openwrt/arm-trusted-firmware

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/docs/license.rst

# TF-A's make helpers use GNU sed syntax; with base sed the toolchain
# detection fails and the build stops.
BUILD_DEPENDS=	aarch64-none-elf-gcc:devel/aarch64-none-elf-gcc \
		gsed:textproc/gsed \
		mkimage:sysutils/u-boot-tools

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	mtk-openwrt
GH_PROJECT=	arm-trusted-firmware
GH_TAGNAME=	476cf6629f76

SSP_UNSAFE=	yes

BINARY_ALIAS=	sed=${LOCALBASE}/bin/gsed
NO_ARCH=	yes

# BL2 is built per boot device, for DDR4 in the BGA package (as on the
# Banana Pi BPI-R3). The DRAM initialization is a library MediaTek ships
# prebuilt with these sources (HAVE_DRAM_OBJ_FILE).
MT7986_BOOT_DEVICES=	emmc sdmmc
# MediaTek builds this tree with GCC only; CFLAGS must not change its sizes.
MT7986_MAKE_ARGS=	ARCH=aarch64 \
			BOARD_BGA=1 \
			BUILD_STRING=${GH_TAGNAME} \
			CC=aarch64-none-elf-gcc \
			CFLAGS= \
			CPP=aarch64-none-elf-cpp \
			CPPFLAGS= \
			CROSS_COMPILE=aarch64-none-elf- \
			DRAM_USE_DDR4=1 \
			HAVE_DRAM_OBJ_FILE=yes \
			HOSTCC="${CC}" \
			MKIMAGE=${LOCALBASE}/bin/mkimage \
			PLAT=mt7986 \
			USE_MKIMAGE=1 \
			V=1

.for d in ${MT7986_BOOT_DEVICES}
PLIST_FILES+=	share/${PORTNAME}-mt7986/${d}-ddr4/bl2.img \
		share/${PORTNAME}-mt7986/${d}-ddr4/bl31.bin
.endfor

do-build:
.for d in ${MT7986_BOOT_DEVICES}
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MT7986_MAKE_ARGS} \
		BOOT_DEVICE=${d} BUILD_BASE=${WRKDIR}/build-${d} all)
.endfor

do-install:
.for d in ${MT7986_BOOT_DEVICES}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}-mt7986/${d}-ddr4
	${INSTALL_DATA} ${WRKDIR}/build-${d}/mt7986/release/bl2.img \
		${WRKDIR}/build-${d}/mt7986/release/bl31.bin \
		${STAGEDIR}${PREFIX}/share/${PORTNAME}-mt7986/${d}-ddr4
.endfor

.include <bsd.port.mk>
