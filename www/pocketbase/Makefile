PORTNAME=	pocketbase
DISTVERSIONPREFIX=	v
DISTVERSION=	0.36.9
CATEGORIES=	www

MAINTAINER=	chris.longros@gmail.com
COMMENT=	Open source realtime backend in a single binary
WWW=		https://pocketbase.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:modules

GO_MODULE=	github.com/pocketbase/pocketbase
GO_TARGET=	./examples/base
GO_BUILDFLAGS=	-ldflags="-s -w -X github.com/pocketbase/pocketbase.Version=${DISTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/base ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
