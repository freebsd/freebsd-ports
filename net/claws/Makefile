PORTNAME=	claws
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.0
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Terminal UI for AWS resource management
WWW=		https://github.com/clawscli/claws

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/clawscli/claws
GO_TARGET=	./cmd/claws
GO_LDFLAGS=	-X main.version=${DISTVERSION}

PLIST_FILES=	bin/claws

.include <bsd.port.mk>
