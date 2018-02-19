# Created by: Gregory Bond <gnb@itga.com.au>
# $FreeBSD$

PORTNAME=	albatross
PORTVERSION=	1.42
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://object-craft.com.au/projects/albatross/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-html-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	gnb@itga.com.au
COMMENT=	Python toolkit for developing highly stateful web applications

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		python:2.7
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes
OPTIONS_DEFINE=	DOCS EXAMPLES
PORTDOCS=	*
PORTEXAMPLES=	*

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${EXAMPLESDIR} \
		${STAGEDIR}${DOCSDIR}/html
	(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/)
	(cd ${WRKDIR}/albatross-html-${PORTVERSION} && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/html)
	(cd ${WRKSRC}/samples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/)

.include <bsd.port.mk>
