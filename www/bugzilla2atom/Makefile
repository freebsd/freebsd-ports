# $FreeBSD$

PORTNAME=	bugzilla2atom
PORTVERSION=	g20190710
CATEGORIES=	www

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Convert Bugzilla bugs into Atom feeds

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	t6
GH_TAGNAME=	56126912bf314a80744827758d582e5e60e7178c
GH_TUPLE=	golang:tools:7b25e351ac0e:golang_tools/vendor/golang.org/x/tools

GO_TARGET=	./cmd/bugzilla2atom

PLIST_FILES=	bin/bugzilla2atom

.include <bsd.port.mk>
