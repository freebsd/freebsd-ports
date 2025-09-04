PORTNAME=	natscli
PORTVERSION=	0.2.4
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Command line utility to interact with and manage NATS
WWW=		https://github.com/nats-io/natscli

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/nats-io/natscli
GO_TARGET=	./nats
#GO_BUILDFLAGS=	-buildvcs=false

PLIST_FILES=	bin/nats \
		share/doc/${PORTNAME}/README.md

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
