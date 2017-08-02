# $FreeBSD$
#
# Common infrastructure for u-boot ports
#

PORTNAME=	u-boot
PORTVERSION=	${UBOOT_VERSION}
DISTVERSIONPREFIX= ports-v
CATEGORIES=	sysutils
PKGNAMESUFFIX?=	-${MODEL}

MAINTAINER=	imp@FreeBSD.org
COMMENT=	Cross-build das u-boot for ${MODEL}

LICENSE=	GPLv2

BUILD_DEPENDS+=	gsed:textproc/gsed \
		swig:devel/swig13 \
		dtc>=1.4.1:sysutils/dtc
BUILD_DEPENDS+=	${COMPILER}:devel/${COMPILER}

USES=		gmake python:build shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_PROJECT=	u-boot

SHEBANG_FILES=	lib/libfdt/pylibfdt/setup.py
SSP_UNSAFE=	yes
UBOOT_DIR=	share/u-boot/${PORTNAME}${PKGNAMESUFFIX}
INST=		${PREFIX}/${UBOOT_DIR}
DESCR?=		${.CURDIR}/pkg-descr

MAKE_ARGS+=	V=1 CROSS_COMPILE=${CROSS_COMPILE} DTC=${LOCALBASE}/bin/dtc ${ARCHFLAGS}

NO_ARCH=	yes

# Sanity checks
.if !defined(MODEL)
IGNORE+=	MODEL is not defined
.endif
.if !defined(BOARD_CONFIG)
IGNORE+=	BOARD_CONFIG is not defined
.endif
.if !defined(FAMILY)
IGNORE+=	FAMILY is not defined
.endif

# Overrides for OMAP family
UBOOT_PLIST_OMAP=u-boot.img MLO

# Overrides for ALLWINNER family
UBOOT_PLIST_ALLWINNER=u-boot.img u-boot-sunxi-with-spl.bin

# Overrides for ALLWINNER family
UBOOT_PLIST_ALLWINNER64=u-boot-sunxi-with-spl.bin
UBOOT_ARCH_ALLWINNER64=aarch64

# Uboot variables
.if !defined(UBOOT_VERSION) && defined(UBOOT_VERSION_${FAMILY:tu})
UBOOT_VERSION=${UBOOT_VERSION_${FAMILY:tu}}
.endif
UBOOT_VERSION?=	2017.07.00.1

.if !defined(UBOOT_PLIST) && defined(UBOOT_PLIST_${FAMILY:tu})
UBOOT_PLIST=${UBOOT_PLIST_${FAMILY:tu}}
.endif
UBOOT_PLIST?=u-boot.img

.if !defined(UBOOT_ARCH) && defined(UBOOT_ARCH_${FAMILY:tu})
UBOOT_ARCH=${UBOOT_ARCH_${FAMILY:tu}}
.endif
UBOOT_ARCH?=	arm

.if ${UBOOT_ARCH} == arm
CROSS_COMPILE=arm-none-eabi-
ARCHFLAGS=ARCH=${UBOOT_ARCH}
.elif ${UBOOT_ARCH} == aarch64
CROSS_COMPILE=aarch64-none-elf-
ARCHFLAGS=ARCH=arm
.else
# Best guess for other architectures
CROSS_COMPILE=${UBOOT_ARCH}-none-elf-
ARCHFLAGS=ARCH=${UBOOT_ARCH}
.endif
COMPILER?=${CROSS_COMPILE}gcc

# Each u-boot family has different files to include, bring them in.
.for i in ${UBOOT_PLIST}
PLIST_FILES+= ${UBOOT_DIR}/${i}
.endfor
PLIST_FILES+= ${UBOOT_DIR}/README

do-configure:
	(cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${MAKE_CMD} ${BOARD_CONFIG})

do-install:
	${MKDIR} ${STAGEDIR}/${INST}
.for i in ${UBOOT_PLIST}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}/${INST}
.endfor
	${INSTALL_DATA} ${DESCR} ${STAGEDIR}/${INST}/README

.include <bsd.port.mk>
