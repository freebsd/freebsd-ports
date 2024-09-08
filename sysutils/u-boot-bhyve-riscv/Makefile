MASTERDIR=	${.CURDIR}/../u-boot-master

MODEL=		bhyve-riscv
BOARD_CONFIG=	bhyve-riscv64_smode_defconfig
FAMILY=		bhyve
UBOOT_ARCH=	riscv64

UBOOT_PLIST=	u-boot.bin

EXTRA_PATCHES=	${.CURDIR}/files/

.include "${MASTERDIR}/Makefile"
