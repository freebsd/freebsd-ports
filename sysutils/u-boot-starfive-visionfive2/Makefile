MASTERDIR=	${.CURDIR}/../u-boot-master

U_BOOT_SLAVE_PORTREVISION_2025.04=1

MODEL=		starfive-visionfive2
BOARD_CONFIG=	starfive_visionfive2_defconfig
FAMILY=		starfive
UBOOT_ARCH=	riscv64

# The FIT image will embed an OpenSBI firmware binary
OPENSBI_FIRM=	${LOCALBASE}/share/opensbi/lp64/generic/firmware/fw_dynamic.bin
BUILD_DEPENDS+=	${OPENSBI_FIRM}:sysutils/opensbi
MAKE_ENV+=	OPENSBI=${OPENSBI_FIRM}

UBOOT_MOVE=	${WRKSRC}/spl/u-boot-spl.bin.normal.out
UBOOT_PLIST=	u-boot.itb u-boot-spl.bin.normal.out

.include "${MASTERDIR}/Makefile"
