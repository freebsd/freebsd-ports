# $FreeBSD$

PORTNAME=	2fa
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	security

MAINTAINER=	dg@syrec.org
COMMENT=	Two-factor authentication on the command line

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	rsc
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/2fa
PORTDOCS=	README.md

do-build:
	@cd ${WRKSRC}/${GH_SUBDIR} && ${SETENV} ${MAKE_ENV} GOCACHE=off GOPATH=${WRKSRC} go build -o ${PORTNAME}

do-test:
	@cd ${WRKSRC}/${GH_SUBDIR} && ${SETENV} ${MAKE_ENV} GOCACHE=off GOPATH=${WRKSRC} go test

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
