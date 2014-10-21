# Created by: Yasuhiro KIMURA <yasu@utahime.org>
# $FreeBSD$

PORTNAME=	authres
PORTVERSION=	0.602
CATEGORIES=	mail python
MASTER_SITES=	http://launchpad.net/authentication-results-python/trunk/0.602/+download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yasu@utahime.org
COMMENT=	Python module for RFC 5451 Authentication-Results headers

LICENSE=	APACHE20

USES=		python
USE_PYTHON=	distutils

PLIST_SUB+=	PORTNAME=${PORTNAME}

PORTDOCS=	CHANGES README

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
