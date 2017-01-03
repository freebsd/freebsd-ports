# $FreeBSD$

PORTNAME=	u-boot
PORTVERSION=	2016.05
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.denx.de/pub/u-boot/
PKGNAMESUFFIX?=	-sinovoip-bpi-m3

MAINTAINER=	jmcneill@FreeBSD.org
COMMENT=	Cross-build U-Boot loader for Sinovoip Banana Pi M3

LICENSE=	GPLv2

BUILD_DEPENDS=	arm-none-eabi-gcc:devel/arm-none-eabi-gcc

USES=		gmake tar:bzip2
WRKSRC=		${WRKDIR}/u-boot-${DISTVERSION}

.include <bsd.port.pre.mk>
NO_ARCH=	yes

MODEL?=		sinovoip-bpi-m3
CONF_TARGET?=	Sinovoip_BPI_M3_defconfig

SSP_UNSAFE=	yes # cross-LD does not support -fstack-protector

U_BOOT_DIR=	share/u-boot/${PORTNAME}${PKGNAMESUFFIX}
PLIST_FILES=	${U_BOOT_DIR}/u-boot.img \
		${U_BOOT_DIR}/u-boot-sunxi-with-spl.bin \
		${U_BOOT_DIR}/sunxi-spl.bin \
		${U_BOOT_DIR}/README

MAKE_ARGS+=	ARCH=arm \
		CROSS_COMPILE=arm-none-eabi-

post-patch:
	@${REINPLACE_CMD} -e "s,%%MODEL%%,${MODEL}," \
		${WRKSRC}/include/configs/sunxi-common.h

do-configure:
	(cd ${WRKSRC}; ${MAKE_CMD} ${CONF_TARGET})

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	${INSTALL_DATA} ${WRKSRC}/spl/sunxi-spl.bin ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	${INSTALL_DATA} ${WRKSRC}/u-boot-sunxi-with-spl.bin \
		${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	${INSTALL_DATA} ${WRKSRC}/u-boot.img ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	${INSTALL_DATA} ${DESCR} ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/README

.include <bsd.port.post.mk>
