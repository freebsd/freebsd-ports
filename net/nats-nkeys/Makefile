PORTNAME=	nkeys
PORTVERSION=	0.4.7
DISTVERSIONPREFIX=	v
PORTREVISION=	7
CATEGORIES=	net
PKGNAMEPREFIX=	nats-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Public-key signature system based on Ed25519 for the NATS ecosystem
WWW=		https://github.com/nats-io/nkeys

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	nats-io
GH_TUPLE=	golang:crypto:v0.17.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:v0.15.0:golang_sys/vendor/golang.org/x/sys
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	./nk

PLIST_FILES=	bin/nk \
		share/doc/${PORTNAME}/README.md

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
