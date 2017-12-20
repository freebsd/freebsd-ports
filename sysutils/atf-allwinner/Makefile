# $FreeBSD$

PORTNAME=	atf-allwinner
PORTVERSION=	1.2.20171017
CATEGORIES=	sysutils
MASTER_SITES=	GH

MAINTAINER=	manu@freebsd.org
COMMENT=	Arm Trusted Framework for Allwinner SoCs

LICENSE=	BSD

BUILD_DEPENDS=	aarch64-none-elf-gcc:devel/aarch64-none-elf-gcc

USE_GITHUB=	yes
GH_ACCOUNT=	apritzel
GH_PROJECT=	arm-trusted-firmware
GH_TAGNAME=	91f2402

SSP_UNSAFE=	yes
USES=	gmake
MAKE_ENV+=	CROSS_COMPILE="aarch64-none-elf-"
ALL_TARGET=	PLAT=sun50iw1p1 bl31

PLIST_FILES=	${PREFIX}/share/${PORTNAME}/bl31.bin

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/${PORTNAME}/
	${INSTALL_DATA} ${WRKSRC}/build/sun50iw1p1/release/bl31.bin ${STAGEDIR}/${PREFIX}/share/${PORTNAME}/

.include <bsd.port.mk>
