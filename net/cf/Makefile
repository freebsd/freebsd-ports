PORTNAME=	cf
PORTVERSION=	6.49.0
DISTVERSIONPREFIX=	v
PORTREVISION=	31
CATEGORIES=	net

MAINTAINER=	dumbbell@FreeBSD.org
COMMENT=	CLI for Cloud Foundry written in Go
WWW=		https://cloudfoundry.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Not updated in years, no demand for them
EXPIRATION_DATE=	2025-10-01

BUILD_DEPENDS=	${LOCALBASE}/bin/go-bindata:devel/go-bindata

USE_GITHUB=	yes
GH_ACCOUNT=	cloudfoundry
GH_PROJECT=	cli
GH_TUPLE=	golang:sys:v0.6.0:sys

USES=		go

CONFLICTS_INSTALL=	lbl-cf # bin/cf

GO_BUILDFLAGS=	-ldflags="-X code.cloudfoundry.org/cli/version.binaryVersion=${PORTVERSION}"
GO_PKGNAME=	code.cloudfoundry.org/cli
GO_TARGET=	:cf

PLIST_FILES=	bin/cf

PORTDOCS=	NOTICE README.md

OPTIONS_DEFINE=	DOCS

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for x in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${x} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
