# $FreeBSD$

PORTNAME=	dwatch-gource
DISTVERSION=	0.9
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FreeBSD dwatch profiles for creating gource logs

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	FrauBSD
NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gwatch ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/dwatch
	${INSTALL_DATA} ${WRKSRC}/gource-* ${STAGEDIR}${PREFIX}/libexec/dwatch

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
