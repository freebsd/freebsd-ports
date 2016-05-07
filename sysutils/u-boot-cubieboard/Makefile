# $FreeBSD$

PORTNAME=	u-boot
PORTVERSION=	2015.04
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.denx.de/pub/u-boot/
PKGNAMESUFFIX?=	-cubieboard

MAINTAINER=	loos@FreeBSD.org
COMMENT?=	Cross-build U-Boot loader for Cubieboard

LICENSE=	GPLv2

BUILD_DEPENDS=	arm-none-eabi-gcc:devel/arm-none-eabi-gcc

MODEL?=		cubieboard
CONF_TARGET?=	Cubieboard_defconfig

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

post-patch:
	@${REINPLACE_CMD} -e "s,%%MODEL%%,${MODEL}," \
		${WRKSRC}/include/configs/sunxi-common.h

do-configure:
	(cd ${WRKSRC}; ${GMAKE} ${CONF_TARGET})

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	${CP} ${WRKSRC}/spl/sunxi-spl.bin ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	${CP} ${WRKSRC}/u-boot-sunxi-with-spl.bin ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	${CP} ${WRKSRC}/u-boot.img ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	${CP} ${.CURDIR}/pkg-descr ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/README

.include <bsd.port.mk>
