PORTNAME=	go-ethereum
DISTVERSIONPREFIX=	v
DISTVERSION=	1.16.8
PORTREVISION=	1
CATEGORIES=	net-p2p

MAINTAINER=	me@enriquefynn.com
COMMENT=	Go implementation of the Ethereum y/w paper
WWW=		https://github.com/ethereum/go-ethereum

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libiconv.so:converters/libiconv \
		libhidapi.so:comms/hidapi

USES=		cpe go:modules
CPE_VENDOR=	ethereum
CPE_PRODUCT=	go_ethereum

GO_MODULE=	github.com/ethereum/go-ethereum

CGO_LDFLAGS=	-liconv

TMPDIR=	${WRKDIR}

OPTIONS_DEFINE=	DEVTOOLS
OPTIONS_SUB=	yes
DEVTOOLS_DESC=	Ethereum developer tools

DEVTOOLS_VARS=		GO_TARGET="./cmd/geth ./cmd/abigen ./cmd/evm ./cmd/rlpdump ./cmd/clef"
DEVTOOLS_VARS_OFF=	GO_TARGET=./cmd/geth

.include <bsd.port.mk>
