PORTNAME=	2fa
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
PORTREVISION=	28
CATEGORIES=	security

MAINTAINER=	mauroeldritch@gmail.com
COMMENT=	Two-factor authentication on the command line
WWW=		https://github.com/rsc/2fa

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	rsc.io/2fa

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/2fa
PORTDOCS=	README.md

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
