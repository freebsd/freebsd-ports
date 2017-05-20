# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	scrypt
PORTVERSION=	1.4.2
CATEGORIES=	security pear

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	PHP wrapper to Colin Percival's scrypt implementation

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:pecl
USE_PHP=	hash:build

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	README.md
PORTEXAMPLES=	scrypt.php

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
