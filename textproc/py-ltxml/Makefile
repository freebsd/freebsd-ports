# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ltxml
PORTVERSION=	1.3
PORTREVISION=	5
CATEGORIES=	textproc python
MASTER_SITES=	ftp://ftp.cogsci.ed.ac.uk/pub/LTXML/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyLTXML-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python bindings to the LT XML toolkit

LICENSE=	GPLv2 # only `GPL' is mentioned, assuming v2

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-03-19

BUILD_DEPENDS=	${LOCALBASE}/include/ltxml12/lt-safe.h:textproc/ltxml
RUN_DEPENDS=	${LOCALBASE}/include/ltxml12/lt-safe.h:textproc/ltxml

USES=		python:2.7
USE_PYTHON=	distutils autoplist
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
PORTDOCS=	00README
PORTEXAMPLES=	*

OPTIONS_DEFINE= DOCS EXAMPLES

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON}${PYTHON_SITELIBDIR}/PyLTXML/LTXMLinter.so

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
