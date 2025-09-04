PORTNAME=	nkeys
PORTVERSION=	0.4.11
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	net
PKGNAMEPREFIX=	nats-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Public-key signature system based on Ed25519 for the NATS ecosystem
WWW=		https://github.com/nats-io/nkeys

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/nats-io/nkeys
GO_TARGET=	./nk

PLIST_FILES=	bin/nk \
		share/doc/${PORTNAME}/README.md

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
