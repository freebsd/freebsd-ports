# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	numeric
PORTVERSION=	24.2
PORTREVISION=	4
CATEGORIES=	math python
MASTER_SITES=	http://numpy.scipy.org/:doc \
		SF/numpy/Old%20Numeric/${PORTVERSION}:source
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	Numeric-${PORTVERSION}${EXTRACT_SUFX}:source \
		numpy.pdf:doc
EXTRACT_ONLY=	Numeric-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Numeric Extension to Python

USES=		python:2.7
USE_PYTHON=	distutils autoplist

WRKSRC=		${WRKDIR}/Numeric-${PORTVERSION}

DOCSDIR=	${PREFIX}/share/doc/py-numeric
EXAMPLESDIR=	${PREFIX}/share/examples/py-numeric
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-extract:
	@${CP} ${DISTDIR}/numpy.pdf ${WRKDIR}
#
# Force the setup.py file to use a specific version of Python,
# since more than one may be installed, and we want to use
# the correct one, because if one has setuptools and another
# doesn't, that could mess with how pkg-plist is constructed.
#
	@${REINPLACE_CMD} \
		-e "s|/usr/bin/env python|/usr/bin/env python${PYTHON_VER}|" \
		-e 's,distutils\.command\.install ,setuptools\.command\.install ,' \
		${WRKSRC}/setup.py

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/Numeric -name "*.so" -exec \
		${STRIP_CMD} {} \;

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/numpy.pdf ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Demo/*.py ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/NumTut
	${INSTALL_DATA} ${WRKSRC}/Demo/NumTut/* ${STAGEDIR}${EXAMPLESDIR}/NumTut

.include <bsd.port.mk>
