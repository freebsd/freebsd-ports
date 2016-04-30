# $FreeBSD$

PORTNAME=	go-ethereum
PORTVERSION=	1.3.6
DISTVERSIONPREFIX=	v
CATEGORIES=	net-p2p

MAINTAINER=	enriquefynn@gmail.com
COMMENT=	Go implementation of the Ethereum y/w paper

LICENSE=	GPLv3

LIB_DEPENDS=	libgmp.so:math/gmp
BUILD_DEPENDS=	go:lang/go
RUN_DEPENDS=	go:lang/go

OPTIONS_DEFINE=	BOOTNODE ETHTEST EVM DISASM RLPDUMP
OPTIONS_SUB=	yes

BOOTNODE_DESC=	Runs a bootstrap node for the Discovery Protocol
ETHTEST_DESC=	Test tool which runs with the tests suite
EVM_DESC=	A generic Ethereum Virtual Machine
DISASM_DESC=	Disassembles EVM code
RLPDUMP_DESC=	Prints RLP structures

USE_GITHUB=	yes
GH_ACCOUNT=	ethereum

USE_GCC=	4.8+

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/bin/geth ${STAGEDIR}${PREFIX}/bin
	@if [ ${PORT_OPTIONS:MBOOTNODE} ]; then \
		${INSTALL_PROGRAM} ${WRKSRC}/build/bin/bootnode ${STAGEDIR}${PREFIX}/bin; \
	fi;
	@if [ ${PORT_OPTIONS:METHTEST} ]; then \
		${INSTALL_PROGRAM} ${WRKSRC}/build/bin/ethtest ${STAGEDIR}${PREFIX}/bin; \
	fi;
	@if [ ${PORT_OPTIONS:MEVM} ]; then \
		${INSTALL_PROGRAM} ${WRKSRC}/build/bin/evm ${STAGEDIR}${PREFIX}/bin; \
	fi;
	@if [ ${PORT_OPTIONS:MDISASM} ]; then \
		${INSTALL_PROGRAM} ${WRKSRC}/build/bin/disasm ${STAGEDIR}${PREFIX}/bin; \
	fi;
	@if [ ${PORT_OPTIONS:MRLPDUMP} ]; then \
		${INSTALL_PROGRAM} ${WRKSRC}/build/bin/rlpdump ${STAGEDIR}${PREFIX}/bin; \
	fi;

.include <bsd.port.mk>
