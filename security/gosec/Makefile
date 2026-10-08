PORTNAME=	gosec
DISTVERSIONPREFIX=	v
DISTVERSION=	2.29.0
PORTREVISION=	1
CATEGORIES=	security devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Go security checker
WWW=		https://securego.io/ \
		https://github.com/securego/gosec

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules

GO_MODULE=	github.com/securego/gosec/v2
GO_TARGET=	./cmd/${PORTNAME}
# TestRules uses sample Go code that imports modules not vendored in the project
GO_TESTFLAGS+=	-skip TestRules

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
