# $FreeBSD$

PORTNAME=	2fa
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	security

MAINTAINER=	dg@syrec.org
COMMENT=	Two-factor authentication on the command line

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	rsc

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/2fa
PORTDOCS=	README.md

do-build:
	@cd ${WRKSRC} && ${SETENV} GOPATH=${WRKSRC} go build -o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
