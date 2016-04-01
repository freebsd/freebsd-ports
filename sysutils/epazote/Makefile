# $FreeBSD$

PORTNAME=       epazote
PORTVERSION=    1.5.2
CATEGORIES=     sysutils

MAINTAINER=     nbari@dalmp.com
COMMENT=        Automated microservices supervisor

LICENSE=        BSD3CLAUSE
LICENSE_FILE=   ${WRKSRC}/LICENSE

BUILD_DEPENDS=  go>=1.6:lang/go

USES=           compiler

USE_GITHUB=     yes
GH_ACCOUNT=     nbari:DEFAULT \
		go-yaml:yaml
GH_PROJECT=     epazote yaml:yaml
GH_TAGNAME=	v2:yaml

STRIP=          # stripping can break go binaries

PLIST_FILES=	bin/epazote

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}
.for src in .gitignore a_test.go cmd config.go mail.go mailman_test.go \
	request.go scandir_test.go singleton_test.go supervice.go try.go \
	block.go color.go config_test.go mail_test.go report.go \
	request_test.go scheduler start.go supervice_test.go \
	try_test.go .travis.yml README.md changelog.md color_test.go \
	examples mailman.go report_test.go scandir.go singleton.go \
	start_test.go test
	@${MV} ${WRKSRC}/${src} \
	${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}
.endfor
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
