# Created by: ijliao
# $FreeBSD$

PORTNAME=	xmlsec
PORTVERSION=	0.3.0
PORTREVISION=	4
CATEGORIES=	security python
MASTER_SITES=	http://labs.libre-entreprise.org/frs/download.php/430/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python bindings for XML Security Library

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxmlsec1.so:security/xmlsec1
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2.py:textproc/py-libxml2

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		python:2
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
PORTDOCS=	*
PORTEXAMPLES=	*

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/xmlsecmod.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/html/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/)

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/)

.include <bsd.port.mk>
