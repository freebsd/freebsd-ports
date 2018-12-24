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
GH_ACCOUNT=	nbari:DEFAULT
GH_TUPLE=	golang:crypto:505ab14:crypto/src/golang.org/x/crypto
GH_SUBDIR=	src/github.com/nbari/${PORTNAME}

PLIST_FILES=	bin/www

post-patch:
	@${MKDIR} ${WRKSRC}/src/golang.org
	@${LN} -sf ${LOCALBASE}/share/go/src/golang.org/x ${WRKSRC}/src/golang.org/x

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}; \
	${SETENV} ${MAKE_ENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -ldflags \
	"-s -w" -o www;

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/www ${STAGEDIR}${PREFIX}/bin/www

.include <bsd.port.mk>
