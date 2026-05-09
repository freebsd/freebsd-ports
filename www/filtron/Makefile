PORTNAME=	filtron
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Filtering reverse HTTP proxy
WWW=		https://github.com/asciimoo/filtron

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/asciimoo/filtron
GO_PKGNAME=	${GO_MODULE}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
