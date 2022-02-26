PORTNAME=	nkeys
PORTVERSION=	0.3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net
PKGNAMEPREFIX=	nats-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Public-key signature system based on Ed25519 for the NATS ecosystem

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_TARGET=	./nk
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	nats-io
GH_TUPLE=	golang:crypto:e6e6c4f2bb5b:golang_crypto/vendor/golang.org/x/crypto

PLIST_FILES=	bin/nk \
		share/doc/${PORTNAME}/README.md

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
