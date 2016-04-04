# $FreeBSD$

PORTNAME=	spiff
PORTVERSION=	1.0.6
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Declarative YAML templating system tuned for BOSH deployment manifests

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	cloudfoundry-incubator

PLIST_FILES=	bin/spiff

PORTDOCS=	LICENSE README.md examples/cf-aws.yml \
		examples/multi-az-cf-aws.yml examples/tutorial.md

STRIP=		# stripping can break go binaries

OPTIONS_DEFINE=	DOCS

post-patch:
	@cd ${WRKSRC} ; ${MKDIR} src/github.com/${GH_ACCOUNT}/${GH_PROJECT} ; \
		${MV} .gitignore .travis.yml Godeps LICENSE Makefile README.md \
		compare dynaml examples flow init_test.go scripts spiff.go \
		spiff_test.go yaml \
		src/github.com/${GH_ACCOUNT}/${GH_PROJECT}
	@${MV} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/Godeps/_workspace/src/github.com/${GH_ACCOUNT}/candiedyaml \
		${WRKSRC}/src/github.com/${GH_ACCOUNT}
	@${MV} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/Godeps/_workspace/src/github.com/codegangsta \
		${WRKSRC}/src/github.com

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT} ; \
		${SETENV} GOPATH=${WRKSRC} go build spiff.go

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/LICENSE \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/README.md \
		${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT} && ${COPYTREE_SHARE} examples ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
