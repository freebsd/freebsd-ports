# $FreeBSD$

PORTNAME=       epazote
PORTVERSION=    2.1.1
CATEGORIES=     sysutils

MAINTAINER=     nbari@tequila.io
COMMENT=        Automated HTTP (microservices) supervisor

LICENSE=        BSD3CLAUSE
LICENSE_FILE=   ${WRKSRC}/LICENSE

BROKEN=		checksum and size mismatch

BUILD_DEPENDS=  go>=1.7:lang/go

USES=           compiler

USE_GITHUB=     yes
GH_TUPLE=	epazote:scheduler:0.1.0:scheduler/src/github.com/epazote/scheduler \
		go-yaml:yaml:v2:yaml/src/gopkg.in/yaml.v2
GH_SUBDIR=	src/github.com/${PORTNAME}/${PORTNAME}

STRIP=          # stripping can break go binaries

PLIST_FILES=	bin/epazote

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}; \
	${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -ldflags \
	"-X main.version=${PORTVERSION}" -o epazote cmd/epazote/main.go;

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/epazote ${STAGEDIR}${PREFIX}/bin/epazote

.include <bsd.port.mk>
