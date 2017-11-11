# $FreeBSD$

MAINTAINER=	manu@FreeBSD.org
MASTERDIR=	${.CURDIR}/../u-boot-master

MODEL=		sopine
BOARD_CONFIG=	sopine_baseboard_defconfig
FAMILY=		allwinner64

BUILD_DEPENDS=	${LOCALBASE}/share/atf-allwinner/bl31.bin:sysutils/atf-allwinner
MAKE_ENV+=	BL31=${LOCALBASE}/share/atf-allwinner/bl31.bin

post-build:
	${CAT} ${WRKSRC}/spl/sunxi-spl.bin ${WRKSRC}/u-boot.itb > ${WRKSRC}/u-boot-sunxi-with-spl.bin

.include "${MASTERDIR}/Makefile"
