# $FreeBSD$

PORTNAME=	go-ethereum
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.22
CATEGORIES=	net-p2p

MAINTAINER=	me@enriquefynn.com
COMMENT=	Go implementation of the Ethereum y/w paper

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	go>=1.9.2:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	ethereum

OPTIONS_DEFINE=	DEVTOOLS
OPTIONS_SUB=	yes

DEVTOOLS_DESC=	Developer tools
TMPDIR=	${WRKDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/bin/geth ${STAGEDIR}${PREFIX}/bin

do-install-DEVTOOLS-on:
	${INSTALL_PROGRAM} ${WRKSRC}/build/bin/abigen ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/build/bin/bootnode ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/build/bin/evm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/build/bin/rlpdump ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/build/bin/swarm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/build/bin/puppeth ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
