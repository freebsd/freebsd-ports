# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	statsmodels
PORTVERSION=	0.8.0
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	johannes@perceivon.net
COMMENT=	Complement to SciPy for statistical computations

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}patsy>0:math/py-patsy@${FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}patsy>0:math/py-patsy@${FLAVOR}

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		python shebangfix
USE_PYTHON=	autoplist distutils concurrent cython
USE_GITHUB=	yes
GH_TAGNAME=	8e812cd
SHEBANG_FILES=	tools/*.py statsmodels/datasets/*/data.py statsmodels/tools/print_version.py \
	statsmodels/regression/quantile_regression.py

PORTEXAMPLES=	*
PORTDOCS=	README.rst README_l1.txt

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/nonparametric/_smoothers_lowess.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/nonparametric/linbin.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/tsa/kalmanf/kalman_loglike.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/tsa/statespace/_statespace.so

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${WRKSRC}/README_l1.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
