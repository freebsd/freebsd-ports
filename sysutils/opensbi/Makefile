# $FreeBSD$

PORTNAME=	opensbi
DISTVERSIONPREFIX=v
DISTVERSION=	0.5
CATEGORIES=	sysutils

MAINTAINER=	mhorne@FreeBSD.org
COMMENT=	RISC-V SBI bootloader and firmware

LICENSE=	BSD2CLAUSE

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	riscv

RISCV_PREFIX=	riscv64-unknown-${OPSYS:tl}${OSREL}-
BUILD_DEPENDS=	${RISCV_PREFIX}gcc:devel/riscv64-xtoolchain-gcc

MAKE_ARGS=	CROSS_COMPILE=${RISCV_PREFIX} I=${STAGEDIR}${PREFIX}

OPTIONS_GROUP=		PLATFORMS
OPTIONS_GROUP_PLATFORMS=QEMU_VIRT SIFIVE_FU540
OPTIONS_SUB=		yes
OPTIONS_DEFAULT=	QEMU_VIRT SIFIVE_FU540

QEMU_VIRT_DESC=		Support for QEMU Virt platform
QEMU_VIRT_PLATFORM=	qemu/virt

SIFIVE_FU540_DESC=	Support for SiFive U540 platform
SIFIVE_FU540_PLATFORM=	sifive/fu540

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
.for i in dynamic jump payload
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/platform/${${platform}_PLATFORM}/firmware/fw_${i}.elf
.endfor
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/platform/${${platform}_PLATFORM}/firmware/payloads/test.elf

.endfor # OPTIONS_GROUP_PLATFORMS

.include <bsd.port.mk>
