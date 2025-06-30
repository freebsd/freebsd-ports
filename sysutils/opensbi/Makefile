PORTNAME=	opensbi
DISTVERSIONPREFIX=v
DISTVERSION=	1.7
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

MAKE_ARGS=	LLVM=1 I=${STAGEDIR}${PREFIX} V=1 \
		FW_PAYLOAD=n FW_TEXT_START=0x80000000 \
		OPENSBI_VERSION_GIT= PLATFORM=generic

GENERIC_STRIP_ARGS=	-K tohost -K fromhost

INSTALL_TARGET=		install

PLIST_SUB+=		RISCV_ABI=${PLATFORM_RISCV_ABI}

PLATFORM_RISCV_ABI=	lp64

post-install:
	${STRIP_CMD} ${GENERIC_STRIP_ARGS} \
	    ${STAGEDIR}${DATADIR}/${PLATFORM_RISCV_ABI}/generic/firmware/fw_*.elf

.include <bsd.port.mk>
