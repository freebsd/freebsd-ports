# $FreeBSD$

PORTNAME=	cf
PORTVERSION=	6.12.2
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	swills@FreeBSD.org
COMMENT=	CLI for Cloud Foundry written in Go

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go \
		${LOCALBASE}/bin/go-bindata:devel/go-bindata

USE_GITHUB=	yes
GH_ACCOUNT=	cloudfoundry
GH_PROJECT=	cli

PLIST_FILES=	bin/cf

PORTDOCS=	BUILDING.md CHANGELOG.md INSTALL.md LICENSE README.md VERSION

STRIP=		# stripping can break go binaries

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s/BUILT_FROM_SOURCE/${PORTVERSION}/g" ${WRKSRC}/cf/app_constants.go
	@cd ${WRKSRC} ; ${MKDIR} Godeps/_workspace/src/github.com/${GH_ACCOUNT}/${GH_PROJECT} ; \
		${CP} -R .gitignore .travis.yml BUILDING.md CHANGELOG.md \
		INSTALL.md LICENSE README.md VERSION bin cf \
		cf_commands_excluded.json ci excluded.json fileutils fixtures \
		flags generic glob installers json main makefile plugin \
		plugin_examples release testhelpers utils words \
		Godeps/_workspace/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}

do-build:
	cd ${WRKSRC}/Godeps/_workspace/src/github.com/${GH_ACCOUNT}/${GH_PROJECT} ; \
		${SETENV} GOPATH=${WRKSRC}/Godeps/_workspace go-bindata -pkg \
		resources -o cf/resources/i18n_resources.go \
		cf/i18n/resources/...  cf/i18n/test_fixtures/...
	cd ${WRKSRC} ; \
		${SETENV} GOPATH=${WRKSRC}/Godeps/_workspace go build -o out/cf ./main

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out/cf \
		${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for x in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${x} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
