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
ATF_TARGET?=	bl31
ALL_TARGET=	ARCH="aarch64" PLAT=${PLAT} V=1 CFLAGS= HOSTCC=${CC} ${ATF_TARGET}

# Default to the latest release
ATF_VERSION?=	v2.10.0

PLIST_FILES?=	${PREFIX}/share/${PORTNAME}-${PLAT}/${BL31:T}
.if defined(FIP)
PLIST_FILES+=	${PREFIX}/share/${PORTNAME}-${PLAT}/${FIP:T}
.endif

DESCR?=		${.CURDIR}/pkg-descr

NO_ARCH=	yes

LDFLAGS+=	--no-warn-rwx-segments

.if !defined(PLAT)
PLAT=		NONE
IGNORE=		is a metaport; there is nothing to build
.endif

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/${PORTNAME}-${PLAT}/
	${INSTALL_DATA} ${WRKSRC}/build/${PLAT}/release/${BL31} ${STAGEDIR}/${PREFIX}/share/${PORTNAME}-${PLAT}/
.if defined(FIP)
	${INSTALL_DATA} ${WRKSRC}/build/${PLAT}/release/${FIP} ${STAGEDIR}/${PREFIX}/share/${PORTNAME}-${PLAT}/
.endif

.include <bsd.port.mk>
