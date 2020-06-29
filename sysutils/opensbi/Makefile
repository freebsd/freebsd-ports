# $FreeBSD$

PORTNAME=	opensbi
DISTVERSIONPREFIX=v
DISTVERSION=	0.8
CATEGORIES=	sysutils

MAINTAINER=	mhorne@FreeBSD.org
COMMENT=	RISC-V SBI bootloader and firmware

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${RISCV_PREFIX}gcc:devel/riscv64-none-elf-gcc \
		${RISCV_PREFIX}ld:devel/binutils@riscv64_none_elf

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	riscv

RISCV_PREFIX=	riscv64-none-elf-

MAKE_ARGS=	CROSS_COMPILE=${RISCV_PREFIX} I=${STAGEDIR}${PREFIX} FW_PAYLOAD=n

OPTIONS_GROUP=		PLATFORMS
OPTIONS_GROUP_PLATFORMS=GENERIC SIFIVE_FU540
OPTIONS_SUB=		yes
OPTIONS_DEFAULT=	GENERIC SIFIVE_FU540

GENERIC_DESC=		Support for generic platform
GENERIC_PLATFORM=	generic
GENERIC_STRIP_ARGS=	-K tohost -K fromhost

SIFIVE_FU540_DESC=	Support for SiFive U540 platform
SIFIVE_FU540_PLATFORM=	sifive/fu540

INSTALL_TARGET=		install

PLIST_SUB+=		RISCV_ABI=${PLATFORM_RISCV_ABI}

PLATFORM_RISCV_ABI=	lp64

.for platform in ${OPTIONS_GROUP_PLATFORMS}

post-build-${platform}-on:
	${MAKE_CMD} -C ${WRKSRC} ${MAKE_ARGS} PLATFORM=${${platform}_PLATFORM}

do-install-${platform}-on:
	${MKDIR} ${STAGEDIR}${PREFIX}
	${MAKE_CMD} -C ${WRKSRC} PLATFORM=${${platform}_PLATFORM} ${MAKE_ARGS} \
		I=${STAGEDIR}${PREFIX} install_firmwares
	${MAKE_CMD} -C ${WRKSRC} PLATFORM=${${platform}_PLATFORM} ${MAKE_ARGS} \
		I=${STAGEDIR}${PREFIX} install_libplatsbi

post-install-${platform}-on:
	${STRIP_CMD} ${${platform}_STRIP_ARGS} \
	    ${STAGEDIR}${DATADIR}/${PLATFORM_RISCV_ABI}/${${platform}_PLATFORM}/firmware/fw_*.elf

.endfor # OPTIONS_GROUP_PLATFORMS

.include <bsd.port.mk>
