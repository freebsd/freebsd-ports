# Created by: Nicolas de Bari Embriz Garcia Rojas <nbari@tequila.io>
# $FreeBSD$

PORTNAME=	www
PORTVERSION=	0.3.1
CATEGORIES=	www
PKGNAMEPREFIX=	go-

MAINTAINER=	nbari@tequila.io
COMMENT=	Web server for static content

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	nbari:DEFAULT,violetear
GH_PROJECT=	violetear:violetear
GH_TAGNAME=	2.2.0:violetear

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

STRIP=		# stripping can break go binaries

PLIST_FILES=	bin/www

post-patch:
	@${LN} -sf ${WRKDIR}/${GH_PROJECT_violetear}-${GH_TAGNAME_violetear} \
		${GO_WRKDIR_SRC}/github.com/${GH_ACCOUNT_violetear}/${GH_PROJECT_violetear}

do-build:
	@(cd ${GO_WRKSRC} && \
		${SETENV} ${BUILD_ENV} GOPATH=${WRKDIR} go build -ldflags \
			"-X main.version=${PORTVERSION}" -o www cmd/www/main.go)

do-install:
	${INSTALL_PROGRAM} ${GO_WRKSRC}/www ${STAGEDIR}${PREFIX}/bin/www

.include <bsd.port.mk>
