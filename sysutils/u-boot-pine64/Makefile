# $FreeBSD$

MAINTAINER=	manu@FreeBSD.org
MASTERDIR=	${.CURDIR}/../u-boot-master

MODEL=		pine64
BOARD_CONFIG=	pine64_plus_defconfig
FAMILY=		allwinner64

BUILD_DEPENDS=	${LOCALBASE}/share/atf-allwinner/bl31.bin:sysutils/atf-allwinner
MAKE_ENV+=	BL31=${LOCALBASE}/share/atf-allwinner/bl31.bin

post-build:
	${CAT} ${WRKSRC}/spl/sunxi-spl.bin ${WRKSRC}/u-boot.itb > ${WRKSRC}/u-boot-sunxi-with-spl.bin

.include "${MASTERDIR}/Makefile"
