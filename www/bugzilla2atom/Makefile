# $FreeBSD$

PORTNAME=	bugzilla2atom
PORTVERSION=	g20190711
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Convert Bugzilla bugs into Atom feeds

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	t6
GH_TAGNAME=	02fec79c229d67abfdde4b310b05f41c079ce5ec
GH_TUPLE=	golang:sys:d0b11bdaac8a:golang_sys/vendor/golang.org/x/sys \
		golang:tools:7b25e351ac0e:golang_tools/vendor/golang.org/x/tools

GO_TARGET=	./cmd/bugzilla2atom

PLIST_FILES=	bin/bugzilla2atom

.include <bsd.port.mk>
