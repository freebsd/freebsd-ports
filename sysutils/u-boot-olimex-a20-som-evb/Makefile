# $FreeBSD$

PORTNAME=	u-boot
PORTVERSION=	${UBOOT_VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.denx.de/pub/u-boot/
PKGNAMESUFFIX?=	-${MODEL}

MAINTAINER=	manu@FreeBSD.org
COMMENT=	Cross-build U-Boot loader for olimex-a20-som-evb

LICENSE=	GPLv2

BUILD_DEPENDS=	arm-none-eabi-gcc:devel/arm-none-eabi-gcc

UBOOT_VERSION?=	2016.07
BOARD_CONFIG?=	A20-Olimex-SOM-EVB_defconfig
MODEL?=		olimex-a20-som-evb

NO_ARCH=	yes

WRKSRC=		${WRKDIR}/u-boot-${DISTVERSION}
USES=		gmake tar:bzip2
SSP_UNSAFE=	yes # cross-LD does not support -fstack-protector

U_BOOT_DIR=	share/u-boot/${PORTNAME}${PKGNAMESUFFIX}
PLIST_FILES=	${U_BOOT_DIR}/u-boot.img \
		${U_BOOT_DIR}/u-boot-sunxi-with-spl.bin \
		${U_BOOT_DIR}/sunxi-spl.bin \
		${U_BOOT_DIR}/README

MAKE_ARGS+=	ARCH=arm \
		CROSS_COMPILE=arm-none-eabi-

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
IGNORE=		requires FreeBSD 10 or later
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,%%MODEL%%,${MODEL}," \
		${WRKSRC}/include/configs/sunxi-common.h

do-configure:
	(cd ${WRKSRC}; ${MAKE_CMD} ${BOARD_CONFIG})

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	${INSTALL_DATA} ${WRKSRC}/u-boot.img ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	${INSTALL_DATA} ${WRKSRC}/u-boot-sunxi-with-spl.bin \
		${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	${INSTALL_DATA} ${WRKSRC}/spl/sunxi-spl.bin \
		${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	${INSTALL_DATA} ${DESCR} ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/README

.include <bsd.port.post.mk>
