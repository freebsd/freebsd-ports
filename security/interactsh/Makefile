PORTNAME=	interactsh
PORTVERSION=	1.2.4
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	OOB interaction gathering server and client library
WWW=		https://github.com/projectdiscovery/interactsh

LICENSE=	MIT

USES=		go:modules

GO_MODULE=	github.com/projectdiscovery/${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME}-server ./cmd/${PORTNAME}-client

PLIST_FILES=	bin/${PORTNAME}-server bin/${PORTNAME}-client

.include <bsd.port.mk>
