MASTERDIR=	${.CURDIR}/../u-boot-master

MODEL=		sifive-fu540
BOARD_CONFIG=	sifive_fu540_defconfig
FAMILY=		sifive
UBOOT_ARCH=	riscv64

# The FIT image will embed an OpenSBI firmware binary
OPENSBI_FIRM=	${LOCALBASE}/share/opensbi/lp64/sifive/fu540/firmware/fw_dynamic.bin
BUILD_DEPENDS+=	${OPENSBI_FIRM}:sysutils/opensbi
MAKE_ENV+=	OPENSBI=${OPENSBI_FIRM}

UBOOT_MOVE=	${WRKSRC}/spl/u-boot-spl.bin
UBOOT_PLIST=	u-boot.itb u-boot-spl.bin

.include "${MASTERDIR}/Makefile"
