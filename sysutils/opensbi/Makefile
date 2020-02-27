# $FreeBSD$

PORTNAME=	opensbi
DISTVERSIONPREFIX=v
DISTVERSION=	0.6
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

MAKE_ARGS=	CROSS_COMPILE=${RISCV_PREFIX} I=${STAGEDIR}${PREFIX}

OPTIONS_GROUP=		PLATFORMS
OPTIONS_GROUP_PLATFORMS=QEMU_VIRT SIFIVE_FU540 SPIKE
OPTIONS_SUB=		yes
OPTIONS_DEFAULT=	QEMU_VIRT SIFIVE_FU540 SPIKE

QEMU_VIRT_DESC=		Support for QEMU Virt platform
QEMU_VIRT_PLATFORM=	qemu/virt

SIFIVE_FU540_DESC=	Support for SiFive U540 platform
SIFIVE_FU540_PLATFORM=	sifive/fu540

SPIKE_DESC=		Support for Spike ISA Simulator platform
SPIKE_PLATFORM=		spike
SPIKE_STRIP_ARGS=	-K tohost -K fromhost

INSTALL_TARGET=		install

.for platform in ${OPTIONS_GROUP_PLATFORMS}

post-build-${platform}-on:
	${MAKE_CMD} -C ${WRKSRC} ${MAKE_ARGS} PLATFORM=${${platform}_PLATFORM}

do-install-${platform}-on:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MAKE_CMD} -C ${WRKSRC} PLATFORM=${${platform}_PLATFORM} \
		I=${STAGEDIR}${DATADIR} install_firmwares
	${MAKE_CMD} -C ${WRKSRC} PLATFORM=${${platform}_PLATFORM} \
		I=${STAGEDIR}${DATADIR} install_libplatsbi

post-install-${platform}-on:
	${STRIP_CMD} ${${platform}_STRIP_ARGS} \
	    ${STAGEDIR}${DATADIR}/platform/${${platform}_PLATFORM}/firmware/fw_*.elf
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/platform/${${platform}_PLATFORM}/firmware/payloads/test.elf

.endfor # OPTIONS_GROUP_PLATFORMS

.include <bsd.port.mk>
