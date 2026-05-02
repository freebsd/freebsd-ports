PORTNAME=	fabric
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.451
CATEGORIES=	misc # machine-learning
PKGNAMESUFFIX=	-ai

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Framework for augmenting humans using AI
WWW=		https://github.com/danielmiessler/fabric

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/danielmiessler/fabric
GO_TARGET=	./cmd/fabric

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
