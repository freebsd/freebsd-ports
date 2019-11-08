# $FreeBSD$
#
# Common infrastructure for u-boot ports
#

PORTNAME=	u-boot
PORTVERSION=	${UBOOT_VERSION}
CATEGORIES=	sysutils
PKGNAMESUFFIX?=	-${MODEL}
MASTER_SITES=	ftp://ftp.denx.de/pub/u-boot/
DIST_SUBDIR=	u-boot

MAINTAINER?=	uboot@FreeBSD.org
COMMENT=	Cross-build das u-boot for model ${MODEL}

LICENSE=	GPLv2

BUILD_DEPENDS+=	gsed:textproc/gsed \
		swig3.0:devel/swig30 \
		dtc>=1.4.1:sysutils/dtc \
		mkimage:sysutils/u-boot-tools
BUILD_DEPENDS+=	${COMPILER}:devel/${COMPILER}

USES=		bison gmake python:2.7,build shebangfix tar:bz2
BINARY_ALIAS=	bison=${LOCALBASE}/bin/bison dtc=${LOCALBASE}/bin/dtc sed=gsed swig=swig3.0 python2=python2.7

SHEBANG_FILES=	tools/binman/binman.py arch/arm/mach-rockchip/make_fit_atf.py
SSP_UNSAFE=	yes
UBOOT_DIR=	share/u-boot/${PORTNAME}${PKGNAMESUFFIX}
INST=		${PREFIX}/${UBOOT_DIR}
DESCR?=		${.CURDIR}/pkg-descr

MAKE_ARGS+=	V=1 CROSS_COMPILE=${CROSS_COMPILE} PYTHON=${PYTHON_CMD} ${ARCHFLAGS}

NO_ARCH=	yes

# Use upstreamed patches not yet mainlined
PATCH_DIST_STRIP=	-p1
PATCH_SITES+=	https://patchwork.ozlabs.org/patch/

# Sanity checks
.if !defined(MODEL) && !defined(BOARD_CONFIG) && !defined(FAMILY)
MODEL=		NONE
IGNORE=		is a metaport; there is nothing to build
.else
.if !defined(MODEL)
IGNORE+=	MODEL is not defined
.endif
.if !defined(BOARD_CONFIG)
IGNORE+=	BOARD_CONFIG is not defined
.endif
.if !defined(FAMILY)
IGNORE+=	FAMILY is not defined
.endif
.endif

# Overrides for OMAP family
UBOOT_PLIST_OMAP=u-boot.img MLO
UBOOT_METADATA_OMAP_FILES=	${UBOOT_PLIST_OMAP}
UBOOT_METADATA_OMAP_METHOD=	file

# Overrides for ALLWINNER family
UBOOT_PLIST_ALLWINNER=u-boot-sunxi-with-spl.bin
UBOOT_METADATA_ALLWINNER_FILES=		${UBOOT_PLIST_ALLWINNER}
UBOOT_METADATA_ALLWINNER_METHOD=	raw
UBOOT_METADATA_ALLWINNER_RAW_OFFSET=	8
UBOOT_METADATA_ALLWINNER_RAW_BS=	1k

# Overrides for ALLWINNER64 family
UBOOT_PLIST_ALLWINNER64=${UBOOT_PLIST_ALLWINNER}
UBOOT_ARCH_ALLWINNER64=aarch64
UBOOT_METADATA_ALLWINNER64_FILES=	${UBOOT_PLIST_ALLWINNER64}
UBOOT_METADATA_ALLWINNER64_METHOD=	raw
UBOOT_METADATA_ALLWINNER64_RAW_OFFSET=	8
UBOOT_METADATA_ALLWINNER64_RAW_BS=	1k

# Overrides for Zynq 7000 family
UBOOT_PLIST_ZYNQ_7000=u-boot.img boot.bin uEnv.txt
UBOOT_MOVE_ZYNQ_7000=${WRKSRC}/spl/boot.bin ${.CURDIR}/files/uEnv.txt

# Overrides for RPI family
UBOOT_PLIST_RPI=	u-boot.bin
UBOOT_METADATA_RPI_FILES=	${UBOOT_PLIST_RPI}
UBOOT_METADATA_RPI_METHOD=	file

# Overrides for IMX6 family
UBOOT_METADATA_IMX6_FILES=	u-boot.imx
UBOOT_METADATA_IMX6_METHOD=	raw
UBOOT_METADATA_IMX6_RAW_OFFSET=	2
UBOOT_METADATA_IMX6_RAW_BS=	512

# Override for RK3328 family
UBOOT_PLIST_RK3328=	idbloader.img u-boot.itb
UBOOT_ARCH_RK3328=	aarch64

# Override for RK3399 family
UBOOT_PLIST_RK3399=	idbloader.img u-boot.itb
UBOOT_ARCH_RK3399=	aarch64

# Override for ARMADA38X family
UBOOT_PLIST_ARMADA38X=	u-boot-spl.kwb
UBOOT_METADATA_ARMADA38X_FILES=		${UBOOT_PLIST_ARMADA38X}
UBOOT_METADATA_ARMADA38X_METHOD=	raw
UBOOT_METADATA_ARMADA38X_RAW_OFFSET=	1
UBOOT_METADATA_ARMADA38X_RAW_BS=	512

# Uboot variables
.if !defined(UBOOT_VERSION) && defined(UBOOT_VERSION_${FAMILY:tu})
UBOOT_VERSION=${UBOOT_VERSION_${FAMILY:tu}}
.endif
UBOOT_VERSION?=	2019.10

# If a slave port defines a PORTREVISION use it
.if defined(U_BOOT_SLAVE_PORTREVISION_${UBOOT_VERSION})
PORTREVISION=	${U_BOOT_SLAVE_PORTREVISION_${UBOOT_VERSION}}
.endif

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
UBOOT_PLIST+=	boot.scr
.elif ${UBOOT_ARCH} == aarch64
CROSS_COMPILE=aarch64-none-elf-
ARCHFLAGS=ARCH=arm
.else
# Best guess for other architectures
CROSS_COMPILE=${UBOOT_ARCH}-none-elf-
ARCHFLAGS=ARCH=${UBOOT_ARCH}
.endif
COMPILER?=${CROSS_COMPILE}gcc

.if !defined(UBOOT_MOVE) && defined(UBOOT_MOVE_${FAMILY:tu})
UBOOT_MOVE=${UBOOT_MOVE_${FAMILY:tu}}
.endif

# Per family dependancies
.if defined(FAMILY) && ${FAMILY} == allwinner64
BUILD_DEPENDS+=	${LOCALBASE}/share/atf-sun50i_a64/bl31.bin:sysutils/atf-sun50i_a64
MAKE_ENV+=	BL31=${LOCALBASE}/share/atf-sun50i_a64/bl31.bin
.endif

.if defined(FAMILY) && ${FAMILY} == rk3328
BUILD_DEPENDS+=	${LOCALBASE}/share/atf-rk3328/bl31.elf:sysutils/atf-rk3328 \
		${PYTHON_PKGNAMEPREFIX}pyelftools>0:devel/py-pyelftools@${PY_FLAVOR}
MAKE_ENV+=	BL31=${LOCALBASE}/share/atf-rk3328/bl31.elf
.endif

.if defined(FAMILY) && ${FAMILY} == rk3399
BUILD_DEPENDS+=	${LOCALBASE}/share/atf-rk3399/bl31.elf:sysutils/atf-rk3399 \
		${PYTHON_PKGNAMEPREFIX}pyelftools>0:devel/py-pyelftools@${PY_FLAVOR}
MAKE_ENV+=	BL31=${LOCALBASE}/share/atf-rk3399/bl31.elf
.endif

# Each u-boot family has different files to include, bring them in.
.for i in ${UBOOT_PLIST}
PLIST_FILES+=	${UBOOT_DIR}/${i}
.endfor
PLIST_FILES+=	${UBOOT_DIR}/README

.if defined(UBOOT_METADATA_${FAMILY:tu}_METHOD)
METADATA_METHOD=${UBOOT_METADATA_${FAMILY:tu}_METHOD}
METADATA_FILES=${UBOOT_METADATA_${FAMILY:tu}_FILES}
PLIST_FILES+=	${UBOOT_DIR}/metadata
UBOOT_PLIST+=	metadata
.if ${METADATA_METHOD} == "raw"
METADATA_OFFSET=${UBOOT_METADATA_${FAMILY:tu}_RAW_OFFSET}
METADATA_BS=${UBOOT_METADATA_${FAMILY:tu}_RAW_BS}
.elif ${METADATA_METHOD} == "file"
.else
.error "Unsupported METADATA_METHOD"
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|make|${MAKE_CMD}|" ${WRKSRC}/scripts/kconfig/merge_config.sh
	${CP} ${FILESDIR}/boot.cmd ${WRKSRC}/
.if defined(METADATA_METHOD)
	@echo "METHOD=uboot-${METADATA_METHOD}" > ${WRKSRC}/metadata
	@echo "FILES=\"${METADATA_FILES}\"" >> ${WRKSRC}/metadata
.if ${METADATA_METHOD} == "raw"
	@echo "OFFSET=${METADATA_OFFSET}" >> ${WRKSRC}/metadata
	@echo "BS=${METADATA_BS}" >> ${WRKSRC}/metadata
.elif ${METADATA_METHOD} == "file"
.endif
.endif

.if ${UBOOT_ARCH} == arm && !defined(CONFIG_FRAGMENT)
# For armv6/v7 we want CONFIG_API
# Use a KConfig fragment for that
FRAGMENT_NAME=		FreeBSD_Fragment
CONFIG_FRAGMENT=	${FILESDIR}/${FRAGMENT_NAME}
.endif

.if defined(CONFIG_FRAGMENT)
do-configure:
	${CP} ${CONFIG_FRAGMENT} ${WRKSRC}/configs/
	(cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} scripts/kconfig/merge_config.sh configs/${BOARD_CONFIG} configs/${FRAGMENT_NAME})
.else
do-configure:
	(cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${MAKE_CMD} ${BOARD_CONFIG})
.endif

post-build:
.if ${UBOOT_ARCH} == arm
	mkimage -C none -A arm -T script -d ${FILESDIR}/boot.cmd ${WRKSRC}/boot.scr
.endif
.if defined(UBOOT_EXTRA_TARGETS)
.for i in ${UBOOT_EXTRA_TARGETS}
	(cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${i})
.endfor
.endif
# If we need to put anything into WRKSRC, do so now so we can build the PLIST
# in do-install
.if defined(UBOOT_MOVE)
pre-install:
	${CP} ${UBOOT_MOVE} ${WRKSRC}
.endif

do-install:
	${MKDIR} ${STAGEDIR}/${INST}
.for i in ${UBOOT_PLIST}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}/${INST}
.endfor
	${INSTALL_DATA} ${DESCR} ${STAGEDIR}/${INST}/README

.include <bsd.port.mk>
