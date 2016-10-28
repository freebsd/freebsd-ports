# $FreeBSD$

PORTNAME=       epazote
PORTVERSION=    2.1.0
CATEGORIES=     sysutils

MAINTAINER=     nbari@tequila.io
COMMENT=        Automated HTTP (microservices) supervisor

LICENSE=        BSD3CLAUSE
LICENSE_FILE=   ${WRKSRC}/LICENSE

BUILD_DEPENDS=  go>=1.7:lang/go

USES=           compiler

USE_GITHUB=     yes
GH_ACCOUNT=     epazote:DEFAULT \
		epazote:scheduler \
		go-yaml:yaml
GH_PROJECT=     epazote scheduler:scheduler yaml:yaml
GH_TAGNAME=	0.1.0:scheduler v2:yaml

STRIP=          # stripping can break go binaries

PLIST_FILES=	bin/epazote

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}
.for src in a_test.go block.go block_test.go changelog.md cmd color.go \
       	color_test.go config.go config_test.go epazote.go examples \
	mail.go mail_test.go mailman.go mailman_test.go report.go \
	report_test.go request.go request_test.go scandir.go \
	scandir_test.go singleton.go singleton_test.go start.go \
       	start_test.go supervice.go supervice_test.go test try.go try_test.go
	@${MV} ${WRKSRC}/${src} \
	${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}
.endfor
	@${MV} ${WRKSRC_scheduler}/${src} \
		${WRKSRC}/src/github.com/${GH_ACCOUNT}/scheduler
	@${MKDIR} ${WRKSRC}/src/gopkg.in
	@${MV} ${WRKSRC_yaml}/ \
		${WRKSRC}/src/gopkg.in/yaml.v2

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}; \
	${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -ldflags \
	"-X main.version=${PORTVERSION}" -o epazote cmd/epazote/main.go;

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/epazote ${STAGEDIR}${PREFIX}/bin/epazote

.include <bsd.port.mk>
