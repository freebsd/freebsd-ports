# $FreeBSD$

PORTNAME=	obfs4proxy
DISTVERSION=	0.0.11
PORTREVISION=	2
CATEGORIES=	security net
MASTER_SITES=	https://people.torproject.org/~yawning/releases/${PORTNAME}/
PKGNAMESUFFIX=	-tor
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Pluggable transport proxy for Tor (obfs4, The Obfuscator)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKDIR}/LICENSE

USES=		cpe go:modules tar:xz

CPE_VENDOR=	torproject

USE_GITHUB=	nodefault
GH_TUPLE=	agl:ed25519:5312a61:ed25519/vendor/github.com/agl/ed25519 \
		dchest:siphash:v1.2.1:siphash/vendor/github.com/dchest/siphash \
		dsnet:compress:v0.0.1:dsnet_compress/vendor/github.com/dsnet/compress \
		golang:crypto:9e8e0b3:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:7b1cca2:golang_net/vendor/golang.org/x/net \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		golang:sys:b09fb70:golang_sys/vendor/golang.org/x/sys \
		torbsd:goptlib:v1.1.0:goptlib/vendor/git.torproject.org/pluggable-transports/goptlib.git \
		Yawning:bsaes:26d1add:Yawning_bsaes/vendor/git.schwanenlied.me/yawning/bsaes.git

USE_GITLAB=	nodefault
GL_TUPLE=	yawning:utls:ad258eb64575fd468dbd2f93ef229df5f7fe72b4:yawning_utls/vendor/gitlab.com/yawning/utls.git

GO_TARGET=	../obfs4proxy

SUB_FILES=	pkg-message

PLIST_FILES=	bin/obfs4proxy \
		man/man1/obfs4proxy.1.gz

post-patch:
	${LN} -s ${WRKSRC}/vendor ${WRKDIR}

post-install:
	${INSTALL_MAN} ${WRKDIR}/doc/obfs4proxy.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
