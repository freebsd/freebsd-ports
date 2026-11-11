PORTNAME=	fx
PORTVERSION=	40.0.1
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Terminal JSON viewer and processor
WWW=		https://fx.wtf/ \
		https://github.com/antonmedv/fx

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

# https://pkg.go.dev/github.com/antonmedv/fx
GO_MODULE=	github.com/antonmedv/fx@v0.0.0-20261022134922-5d57637b00f4

PLIST_FILES=	bin/fx

.include <bsd.port.mk>
