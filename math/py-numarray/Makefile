# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	numarray
PORTVERSION=	1.5.2
PORTREVISION=	3
CATEGORIES=	math python
MASTER_SITES=	SF/numpy/Old%20Numarray/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Numeric array manipulation extension module for Python

LICENSE=	BSD3CLAUSE

USES=		python:2.7 shebangfix
SHEBANG_FILES=	Examples/convolve/benchmark.py
USE_PYTHON=	distutils autoplist

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-configure:
	cd ${WRKSRC} && \
		${PYTHON_CMD} generate.py && \
		${PYTHON_CMD} Include/numarray/genapis.py

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/numarray -name "*.so" -exec \
		${STRIP_CMD} {} \;

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${TAR} -C ${WRKSRC}/Doc -cf- .|${TAR} -C ${STAGEDIR}${DOCSDIR} -xf-

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${TAR} -C ${WRKSRC}/Examples -cf- .|${TAR} -C ${STAGEDIR}${EXAMPLESDIR} -xf-
	@${RM} -r ${STAGEDIR}${EXAMPLESDIR}/ufunc/build

.include <bsd.port.mk>
