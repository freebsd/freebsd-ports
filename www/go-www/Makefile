# Created by: Nicolas de Bari Embriz Garcia Rojas <nbari@tequila.io>
# $FreeBSD$

PORTNAME=	www
PORTVERSION=	2.0.0
CATEGORIES=	www
PKGNAMEPREFIX=	go-

MAINTAINER=	nbari@tequila.io
COMMENT=	Web server for static content

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	nbari
GH_TUPLE=	golang:crypto:505ab14:crypto/vendor/golang.org/x/crypto
GH_SUBDIR=	src/github.com/nbari/${PORTNAME}

GO_BUILDFLAGS=	-ldflags "-s -w"

PLIST_FILES=	bin/www

.include <bsd.port.mk>
