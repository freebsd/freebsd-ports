MASTERDIR=	${.CURDIR}/../u-boot-master

MODEL=		beaglebone
BOARD_CONFIG=	am335x_evm_defconfig
FAMILY=		omap

# am335x kconfig does not resolve SYS_LOAD_ADDR and TEXT_BASE through the
# merge_config.sh path in 2026.10, the build hangs prompting for them.
BROKEN=		Does not build with u-boot 2026.10

CONFIG_FRAGMENT=	${.CURDIR}/files/bbb_fragment
FRAGMENT_NAME=		bbb_fragment

.include "${MASTERDIR}/Makefile"
