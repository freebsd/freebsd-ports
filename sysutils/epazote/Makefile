PORTNAME=	epazote
PORTVERSION=	2.1.2
PORTREVISION=	27
CATEGORIES=	sysutils

MAINTAINER=	nbari@tequila.io
COMMENT=	Automated HTTP (microservices) supervisor
WWW=		https://epazote.io

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_TUPLE=	epazote:scheduler:0.1.0:scheduler/vendor/github.com/epazote/scheduler \
		go-yaml:yaml:cd8b52f:yaml/vendor/github.com/go-yaml/yaml
GH_SUBDIR=	src/github.com/${PORTNAME}/${PORTNAME}

GO_BUILDFLAGS=	-ldflags "-X main.version=${PORTVERSION}"
GO_TARGET=	./cmd/epazote

PLIST_FILES=	bin/epazote

.include <bsd.port.mk>
