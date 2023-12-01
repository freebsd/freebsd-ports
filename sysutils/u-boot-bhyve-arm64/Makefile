MASTERDIR=	${.CURDIR}/../u-boot-master

MODEL=		bhyve-arm64
BOARD_CONFIG=	bhyve_arm64_defconfig
FAMILY=		bhyve
UBOOT_ARCH=	aarch64

UBOOT_PLIST=	u-boot.bin

EXTRA_PATCHES=	${.CURDIR}/files/

# Config doesn't enable TOOLS_MKEFICAPSULE
NO_MKEFICAPSULE=

.include "${MASTERDIR}/Makefile"
