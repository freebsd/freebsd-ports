# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	statsmodels
PORTVERSION=	0.11.1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Complement to SciPy for statistical computations

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cython>=0.29:lang/cython@${PY_FLAVOR} \
		${RUN_DEPENDS}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pandas>=0.21:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}patsy>=0.5:math/py-patsy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.0:science/py-scipy@${PY_FLAVOR}

USES=		python:3.5+ shebangfix
USE_PYTHON=	autoplist concurrent cython distutils

PORTDOCS=	README.rst README_l1.txt
PORTEXAMPLES=	*

SHEBANG_GLOB=	*.py

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${WRKSRC}/README_l1.txt ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
