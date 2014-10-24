# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	pyaixi
PORTVERSION=	1.0.3
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xmj@chaot.net
COMMENT=	Implementation of the MC-AIXI-CTW AI algorithm

LICENSE=	CCbySA
LICENSE_NAME=	Creative Commons Attribution-ShareAlike 3.0 \
		Unported License
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	auto-accept dist-mirror pkg-mirror pkg-sell dist-sell

USES=		dos2unix python:2
USE_PYTHON=	distutils autoplist

PORTDOCS=	changelog.txt \
		todo.txt

PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} \
		${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/conf/|} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
