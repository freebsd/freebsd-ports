# Created by: Johannes Meixner <johannes@perceivon.net>

PORTNAME=	statsmodels
PORTVERSION=	0.13.2
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Complement to SciPy for statistical computations

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cython>=0.29.26:lang/cython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.17,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.3:science/py-scipy@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.17,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=21.3:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=0.25,1:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}patsy>=0.5.2:math/py-patsy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.3:science/py-scipy@${PY_FLAVOR}

USES=		python:3.7+ shebangfix
USE_PYTHON=	autoplist concurrent cython distutils

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
