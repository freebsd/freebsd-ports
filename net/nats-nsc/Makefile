PORTNAME=	nsc
PORTVERSION=	2.11.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net
PKGNAMEPREFIX=	nats-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Tool for creating NATS account and user access configurations
WWW=		https://github.com/nats-io/nsc

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/nats-io/nsc/v2

PLIST_FILES=	bin/nsc \
		share/doc/${PORTNAME}/README.md

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
