MASTERDIR=	${.CURDIR}/../u-boot-master

U_BOOT_SLAVE_PORTREVISION_2025.04=1

MODEL=		sifive-fu540
BOARD_CONFIG=	sifive_unleashed_defconfig
FAMILY=		sifive
UBOOT_ARCH=	riscv64

# The FIT image will embed an OpenSBI firmware binary
OPENSBI_FIRM=	${LOCALBASE}/share/opensbi/lp64/generic/firmware/fw_dynamic.bin
BUILD_DEPENDS+=	${OPENSBI_FIRM}:sysutils/opensbi
MAKE_ENV+=	OPENSBI=${OPENSBI_FIRM}

UBOOT_MOVE=	${WRKSRC}/spl/u-boot-spl.bin
UBOOT_PLIST=	u-boot.itb u-boot-spl.bin

.include "${MASTERDIR}/Makefile"
