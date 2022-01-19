PORTNAME=	opensbi
DISTVERSIONPREFIX=v
DISTVERSION=	1.0
CATEGORIES=	sysutils

MAINTAINER=	mhorne@FreeBSD.org
COMMENT=	RISC-V SBI bootloader and firmware

LICENSE=	BSD2CLAUSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	riscv

MAKE_ARGS=	CC=clang I=${STAGEDIR}${PREFIX} V=1 FW_PAYLOAD=n

OPTIONS_GROUP=		PLATFORMS
OPTIONS_GROUP_PLATFORMS=GENERIC
OPTIONS_SUB=		yes
OPTIONS_DEFAULT=	GENERIC

GENERIC_DESC=		Support for generic platform
GENERIC_PLATFORM=	generic
GENERIC_STRIP_ARGS=	-K tohost -K fromhost

INSTALL_TARGET=		install

PLIST_SUB+=		RISCV_ABI=${PLATFORM_RISCV_ABI}

PLATFORM_RISCV_ABI=	lp64

.for platform in ${OPTIONS_GROUP_PLATFORMS}

post-build-${platform}-on:
	${MAKE_CMD} -C ${WRKSRC} ${MAKE_ARGS} PLATFORM=${${platform}_PLATFORM}

do-install-${platform}-on:
	${MKDIR} ${STAGEDIR}${PREFIX}
	${MAKE_CMD} -C ${WRKSRC} PLATFORM=${${platform}_PLATFORM} ${MAKE_ARGS} \
		I=${STAGEDIR}${PREFIX} V=1 install_firmwares
	${MAKE_CMD} -C ${WRKSRC} PLATFORM=${${platform}_PLATFORM} ${MAKE_ARGS} \
		I=${STAGEDIR}${PREFIX} V=1 install_libplatsbi

post-install-${platform}-on:
	${STRIP_CMD} ${${platform}_STRIP_ARGS} \
	    ${STAGEDIR}${DATADIR}/${PLATFORM_RISCV_ABI}/${${platform}_PLATFORM}/firmware/fw_*.elf

.endfor # OPTIONS_GROUP_PLATFORMS

.include <bsd.port.mk>
