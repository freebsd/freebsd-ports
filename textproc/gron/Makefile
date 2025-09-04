PORTNAME=	gron
PORTVERSION=	0.7.1
DISTVERSIONPREFIX=	v
PORTREVISION=	5
CATEGORIES=	textproc

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Transforms JSON into discrete assignments that are easier to grep
WWW=		https://github.com/tomnomnom/gron

LICENSE=	MIT

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	tomnomnom
GH_TUPLE=	fatih:color:v1.7.0:color/vendor/github.com/fatih/color \
		mattn:go-colorable:v0.1.1:colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.6:isatty/vendor/github.com/mattn/go-isatty \
		nwidger:jsoncolor:75a6de4:jsoncolor/vendor/github.com/nwidger/jsoncolor \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors
GO_BUILDFLAGS=	-ldflags="-X main.gronVersion=${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
