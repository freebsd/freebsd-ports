# $FreeBSD$

PORTNAME=	u-boot
PORTVERSION=	2016.05
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.denx.de/pub/u-boot/:uboot \
		http://download.opensuse.org/repositories/devel:/ARM:/Factory:/Contrib:/Pine64/standard/src/:firmware
PKGNAMESUFFIX=	-pine64
DISTFILES=	u-boot-${PORTVERSION}.tar.bz2:uboot \
		firmware-pine64-20160329-6.1.src.rpm:firmware

MAINTAINER=	brd@FreeBSD.org
COMMENT=	Cross-build U-Boot loader for Pine64

LICENSE=	GPLv2

BUILD_DEPENDS=	aarch64-none-elf-gcc:devel/aarch64-none-elf-gcc

WRKSRC=		${WRKDIR}/u-boot-${DISTVERSION}
USES=		gmake tar:bzip2
SSP_UNSAFE=	yes # cross-LD does not support -fstack-protector

U_BOOT_DIR=	share/u-boot/${PORTNAME}${PKGNAMESUFFIX}
PLIST_FILES=	${U_BOOT_DIR}/pine64.img \
		${U_BOOT_DIR}/README

MAKE_ARGS+=	ARCH=arm \
		CROSS_COMPILE=aarch64-none-elf- \
		PLAT=sun50iw1p1 \
		CONFIG_EFI=y

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
IGNORE=		requires FreeBSD 10 or later
.endif

post-extract:
	(cd ${WRKSRC}; ${EXTRACT_CMD} xvf ${DISTDIR}/firmware-pine64-20160329-6.1.src.rpm)
	${RM} -r ${WRKSRC}/arm-trusted-firmware
	(cd ${WRKSRC}; ${EXTRACT_CMD} xvf pine64atf.tar.xz)

do-configure:
	(cd ${WRKSRC}; ${MAKE_CMD} pine64_plus_defconfig)

post-build:
	(cd ${WRKSRC}/arm-trusted-firmware; ${GMAKE} ${MAKE_ARGS} DEBUG=1)
	(cd ${WRKSRC}; ${CC} -o pine64_image pine64_image.c)
	(cd ${WRKSRC}; ${CAT} arm-trusted-firmware/build/sun50iw1p1/debug/bl31.bin u-boot-dtb.bin > bl31uboot.bin)
	(cd ${WRKSRC}; ./pine64_image scp.bin bl31uboot.bin u-boot.img)
	(cd ${WRKSRC}; ${CAT} boot0.bin u-boot.img > pine64.img)

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	${INSTALL_DATA} ${WRKSRC}/pine64.img ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	${INSTALL_DATA} ${DESCR} ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/README

.include <bsd.port.post.mk>
