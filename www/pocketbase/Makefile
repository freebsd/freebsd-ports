PORTNAME=	pocketbase
DISTVERSIONPREFIX=	v
DISTVERSION=	0.40.5
CATEGORIES=	www

MAINTAINER=	longros@FreeBSD.org
COMMENT=	Open source realtime backend in a single binary
WWW=		https://pocketbase.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:1.27+,modules

GO_MODULE=	github.com/pocketbase/pocketbase
GO_TARGET=	./examples/base:${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-s -w -X github.com/pocketbase/pocketbase.Version=${DISTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
