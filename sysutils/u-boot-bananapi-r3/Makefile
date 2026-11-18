MASTERDIR=	${.CURDIR}/../u-boot-master

EXTRA_PATCHES=	${.CURDIR}/../u-boot-bananapi-r3/files/

MODEL?=		bananapi-r3
BOARD_CONFIG?=	mt7986a_bpir3_sd_defconfig
FAMILY=		mt7986

CONFIG_FRAGMENT=	${.CURDIR}/../u-boot-bananapi-r3/files/bpir3_fragment
FRAGMENT_NAME=		bpir3_fragment

.include "${MASTERDIR}/Makefile"
