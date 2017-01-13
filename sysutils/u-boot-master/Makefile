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

BUILD_DEPENDS=	arm-none-eabi-gcc:devel/arm-none-eabi-gcc \
		gsed:textproc/gsed \
		swig3.0:devel/swig30 \
		python:lang/python2 \
		${PREFIX}/bin/dtc:sysutils/dtc

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	bsdimp
GH_PROJECT=	u-boot

SSP_UNSAFE=	yes
UBOOT_DIR=	share/u-boot/${PORTNAME}${PKGNAMESUFFIX}
INST=		${PREFIX}/${UBOOT_DIR}
DESCR?=		${.CURDIR}/pkg-descr

MAKE_ARGS+=	V=1 ARCH=${UBOOT_ARCH} CROSS_COMPILE=${UBOOT_ARCH}-none-eabi-

NO_ARCH=	yes

# Sanity checks
.if !defined(MODEL)
IGNORE+=	"MODEL is not defined"
.endif
.if !defined(BOARD_CONFIG)
IGNORE+=	"BOARD_CONFIG is not defined"
.endif
.if !defined(FAMILY)
IGNORE+=	"FAMILY is not defined"
.endif

# Defines for OMAP family
UBOOT_PLIST_OMAP=u-boot.img MLO
UBOOT_VERSION_OMAP=2017.01

# Defines for ALLWINNER family
UBOOT_PLIST_ALLWINNER=u-boot.img u-boot-sunxi-with-spl.bin
UBOOT_VERSION_ALLWINNER=2017.01

# Uboot variables
.if !defined(UBOOT_VERSION) && defined(UBOOT_VERSION_${FAMILY:tu})
UBOOT_VERSION=${UBOOT_VERSION_${FAMILY:tu}}
.endif
UBOOT_VERSION?=	2017.01

.if !defined(UBOOT_PLIST) && defined(UBOOT_PLIST_${FAMILY:tu})
UBOOT_PLIST=${UBOOT_PLIST_${FAMILY:tu}}
.endif
UBOOT_PLIST?=u-boot.img

.if !defined(UBOOT_ARCH) && defined(UBOOT_ARCH_${FAMILY:tu})
UBOOT_ARCH=${UBOOT_ARCH_${FAMILY:tu}}
.endif
UBOOT_ARCH?=	arm

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
