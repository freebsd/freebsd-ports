# $FreeBSD$

PORTNAME=	obfs4proxy
DISTVERSION=	0.0.7
CATEGORIES=	security net ipv6
MASTER_SITES=	https://people.torproject.org/~yawning/releases/${PORTNAME}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
PKGNAMESUFFIX=	-tor

MAINTAINER=	egypcio@googlemail.com
COMMENT=	Pluggable transport proxy for Tor (obfs4, The Obfuscator)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go

CPE_VENDOR=	torproject

USES=		cpe tar:xz
USE_GITHUB=	nodefault
GH_TUPLE=	Yawning:goptlib:9b7a700:goptlib/obfs4proxy/src/git.torproject.org/pluggable-transports/goptlib.git \
		agl:ed25519:5312a61:ed25519/obfs4proxy/src/github.com/agl/ed25519 \
		dchest:siphash:4ebf1de:siphash/obfs4proxy/src/github.com/dchest/siphash \
		golang:crypto:d585fd2:crypto/obfs4proxy/src/golang.org/x/crypto \
		golang:net:d866cfc:net/obfs4proxy/src/golang.org/x/net

SUB_FILES=	pkg-message

PLIST_FILES=	bin/obfs4proxy \
		man/man1/obfs4proxy.1.gz

do-build:
	@${RLN} ${WRKSRC} ${WRKSRC}/obfs4proxy/src/git.torproject.org/pluggable-transports/obfs4.git 
	@cd ${WRKSRC}/obfs4proxy && \
		${SETENV} GOPATH=${WRKSRC}/obfs4proxy go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obfs4proxy/obfs4proxy ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/obfs4proxy.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
