# $FreeBSD$

PORTNAME=	dwatch-json
DISTVERSION=	0.4.1
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FreeBSD dwatch profiles to produce JSON logs

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	FrauBSD

NO_ARCH=	yes
NO_BUILD=	yes

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/dwatch
	${INSTALL_DATA} ${WRKSRC}/json-* ${STAGEDIR}${PREFIX}/libexec/dwatch
	${INSTALL_DATA} ${WRKSRC}/dwatch-json-net.conf ${STAGEDIR}${PREFIX}/etc/dwatch-json-net.conf.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
