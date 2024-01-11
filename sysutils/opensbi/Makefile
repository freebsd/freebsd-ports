PORTNAME=	opensbi
DISTVERSIONPREFIX=v
DISTVERSION=	1.4
CATEGORIES=	sysutils

MAINTAINER=	mhorne@FreeBSD.org
COMMENT=	RISC-V SBI bootloader and firmware
WWW=		https://github.com/riscv-software-src/opensbi

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	bash:shells/bash \
		dtc:sysutils/dtc

USES=		gmake python:build shebangfix
SHEBANG_FILES=	scripts/Kconfiglib/*.py

USE_GITHUB=	yes
GH_ACCOUNT=	riscv-software-src

MAKE_ARGS=	LLVM=1 I=${STAGEDIR}${PREFIX} V=1 FW_PAYLOAD=n

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

do-install: # only need install_firmwares target

.for platform in ${OPTIONS_GROUP_PLATFORMS}

post-build-${platform}-on:
	${MAKE_CMD} -C ${WRKSRC} ${MAKE_ARGS} PLATFORM=${${platform}_PLATFORM}

do-install-${platform}-on:
	${MKDIR} ${STAGEDIR}${PREFIX}
	${MAKE_CMD} -C ${WRKSRC} PLATFORM=${${platform}_PLATFORM} ${MAKE_ARGS} \
		I=${STAGEDIR}${PREFIX} V=1 install_firmwares

post-install-${platform}-on:
	${STRIP_CMD} ${${platform}_STRIP_ARGS} \
	    ${STAGEDIR}${DATADIR}/${PLATFORM_RISCV_ABI}/${${platform}_PLATFORM}/firmware/fw_*.elf

.endfor # OPTIONS_GROUP_PLATFORMS

.include <bsd.port.mk>
