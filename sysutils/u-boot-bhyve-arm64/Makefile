MASTERDIR=	${.CURDIR}/../u-boot-master

U_BOOT_SLAVE_PORTREVISION_2023.10=	1

MODEL=		bhyve-arm64
BOARD_CONFIG=	bhyve_arm64_defconfig
FAMILY=		bhyve
UBOOT_ARCH=	aarch64

UBOOT_PLIST=	u-boot.bin

EXTRA_PATCHES=	${.CURDIR}/files/

.include "${MASTERDIR}/Makefile"
