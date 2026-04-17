PORTNAME=	go-ethereum
DISTVERSIONPREFIX=	v
DISTVERSION=	1.17.2
CATEGORIES=	net-p2p

MAINTAINER=	me@enriquefynn.com
COMMENT=	Go implementation of the Ethereum y/w paper
WWW=		https://github.com/ethereum/go-ethereum

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhidapi.so:comms/hidapi \
		libiconv.so:converters/libiconv

USES=		cpe go:modules
CPE_VENDOR=	ethereum
CPE_PRODUCT=	go_ethereum

GO_MODULE=	github.com/ethereum/go-ethereum

CGO_LDFLAGS=	-liconv

TMPDIR=		${WRKDIR}

OPTIONS_DEFINE=	DEVTOOLS
OPTIONS_SUB=	yes
DEVTOOLS_DESC=	Ethereum developer tools

DEVTOOLS_VARS=		GO_TARGET="./cmd/geth ./cmd/abigen ./cmd/evm ./cmd/rlpdump ./cmd/clef ./cmd/ethkey ./cmd/blsync ./cmd/era"
DEVTOOLS_VARS_OFF=	GO_TARGET=./cmd/geth

.include <bsd.port.mk>
