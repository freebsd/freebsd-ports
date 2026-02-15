PORTNAME=	www
PORTVERSION=	2.0.5
CATEGORIES=	www
PKGNAMEPREFIX=	go-

MAINTAINER=	nbari@tequila.io
COMMENT=	Web server for static content
WWW=		https://github.com/nbari/www

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	nbari
GH_SUBDIR=	src/github.com/nbari/${PORTNAME}
GH_TUPLE=	golang:crypto:v0.48.0:crypto/vendor/golang.org/x/crypto \
		golang:net:v0.50.0:net/vendor/golang.org/x/net \
		golang:text:v0.34.0:text/vendor/golang.org/x/text

PLIST_FILES=	bin/www

.include <bsd.port.mk>
