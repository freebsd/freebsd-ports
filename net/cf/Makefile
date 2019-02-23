# $FreeBSD$

PORTNAME=	cf
PORTVERSION=	6.43.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	dumbbell@FreeBSD.org
COMMENT=	CLI for Cloud Foundry written in Go

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/go-bindata:devel/go-bindata

USE_GITHUB=	yes
GH_ACCOUNT=	cloudfoundry
GH_PROJECT=	cli

USES=		go
GO_PKGNAME=	code.cloudfoundry.org/cli

PLIST_FILES=	bin/cf

PORTDOCS=	NOTICE README.md

OPTIONS_DEFINE=	DOCS

do-build:
	(cd ${WRKDIR}; \
	${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} \
		install -v -ldflags="-X code.cloudfoundry.org/cli/version.binaryVersion=${PORTVERSION}" ${GO_TARGET})

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for x in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${x} ${STAGEDIR}${DOCSDIR}
.endfor

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/cli ${STAGEDIR}${PREFIX}/bin/cf

.include <bsd.port.mk>
