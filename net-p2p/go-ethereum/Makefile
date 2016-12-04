# $FreeBSD$

PORTNAME=	go-ethereum
PORTVERSION=	1.5.4
DISTVERSIONPREFIX=	v
CATEGORIES=	net-p2p

MAINTAINER=	enriquefynn@gmail.com
COMMENT=	Go implementation of the Ethereum y/w paper

LICENSE=	GPLv3

BUILD_DEPENDS=	go:lang/go
RUN_DEPENDS=	go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	ethereum

USE_GCC=	yes

OPTIONS_DEFINE=	BOOTNODE ETHTEST EVM DISASM RLPDUMP
OPTIONS_SUB=	yes

BOOTNODE_DESC=	Runs a bootstrap node for the Discovery Protocol
ETHTEST_DESC=	Test tool which runs with the tests suite
EVM_DESC=	A generic Ethereum Virtual Machine
DISASM_DESC=	Disassembles EVM code
RLPDUMP_DESC=	Prints RLP structures

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/bin/geth ${STAGEDIR}${PREFIX}/bin

do-install-BOOTNODE-on:
	${INSTALL_PROGRAM} ${WRKSRC}/build/bin/bootnode ${STAGEDIR}${PREFIX}/bin

do-install-ETHTEST-on:
	${INSTALL_PROGRAM} ${WRKSRC}/build/bin/ethtest ${STAGEDIR}${PREFIX}/bin

do-install-EVM-on:
	${INSTALL_PROGRAM} ${WRKSRC}/build/bin/evm ${STAGEDIR}${PREFIX}/bin

do-install-DISASM-on:
	${INSTALL_PROGRAM} ${WRKSRC}/build/bin/disasm ${STAGEDIR}${PREFIX}/bin

do-install-RLPDUMP-on:
	${INSTALL_PROGRAM} ${WRKSRC}/build/bin/rlpdump ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
