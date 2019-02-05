# $FreeBSD$

PORTNAME=	atf
PORTVERSION?=	${ATF_VERSION}
CATEGORIES=	sysutils
PKGNAMESUFFIX?=	-${PLAT}

MAINTAINER=	uboot@FreeBSD.org
COMMENT=	ARM TF-A for platform ${PLAT}

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS+=	aarch64-none-elf-gcc:devel/aarch64-none-elf-gcc

USES=	gmake

USE_GITHUB=	yes
GH_ACCOUNT=	ARM-software
GH_PROJECT=	arm-trusted-firmware
GH_TAGNAME=	${ATF_VERSION}

SSP_UNSAFE=	yes
MAKE_ENV+=	CROSS_COMPILE="aarch64-none-elf-"
ALL_TARGET=	ARCH="aarch64" PLAT=${PLAT} V=1 bl31

# Default to the latest release
ATF_VERSION?=	v2.0

PLIST_FILES?=	${PREFIX}/share/${PORTNAME}-${PLAT}/${BL31:T}

DESCR?=		${.CURDIR}/pkg-descr

NO_ARCH=	yes

.if !defined(PLAT)
PLAT=		NONE
IGNORE=		is a metaport; there is nothing to build
.endif

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/${PORTNAME}-${PLAT}/
	${INSTALL_DATA} ${WRKSRC}/build/${PLAT}/release/${BL31} ${STAGEDIR}/${PREFIX}/share/${PORTNAME}-${PLAT}/
	${INSTALL_DATA} ${DESCR} ${STAGEDIR}/${INST}/README

.include <bsd.port.mk>
