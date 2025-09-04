PORTNAME=	bugzilla2atom
DISTVERSIONPREFIX=	v
DISTVERSION=	${MODVERSION:S/-/./g:R}
PORTREVISION=	18
CATEGORIES=	www

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Convert Bugzilla bugs into Atom feeds
WWW=		https://codeberg.org/tobik/bugzilla2atom

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
MODVERSION=	0.0.0-20230318132821-2ccd379511f3
GO_MODULE=	codeberg.org/tobik/bugzilla2atom@v${MODVERSION}
GO_TARGET=	./cmd/bugzilla2atom

PLIST_FILES=	bin/bugzilla2atom

.include <bsd.port.mk>
