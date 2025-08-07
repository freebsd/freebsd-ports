PORTNAME=	kepubify
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.4
PORTREVISION=	28
CATEGORIES=	textproc converters

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	EPUB to KEPUB converter
WWW=		https://pgaskin.net/kepubify

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/pgaskin/kepubify/v4

GO_TARGET=	./cmd/covergen ./cmd/kepubify ./cmd/seriesmeta
GO_BUILDFLAGS=	-ldflags '-X main.version=${DISTVERSIONPREFIX}${DISTVERSION}'
PLIST_FILES=	bin/covergen \
		bin/kepubify \
		bin/seriesmeta

.include <bsd.port.mk>
