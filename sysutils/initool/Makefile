PORTNAME=	initool
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	sysutils

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Manipulate INI files from the command line
WWW=		https://github.com/dbohdan/initool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	mlton>0:lang/mlton
LIB_DEPENDS=	libgmp.so:math/gmp

USE_GITHUB=	yes
GH_ACCOUNT=	dbohdan

ALL_TARGET=	initool

PLIST_FILES=	bin/initool

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/initool ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
