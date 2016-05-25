# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	statsmodels
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xmj@FreeBSD.org
COMMENT=	Complement to SciPy for statistical computations

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYNUMPY} \
		cython:lang/cython \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas \
		${PYTHON_PKGNAMEPREFIX}patsy>0:math/py-patsy
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas \
		${PYTHON_PKGNAMEPREFIX}patsy>0:math/py-patsy

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		python
USE_PYTHON=	autoplist distutils concurrent
USE_GITHUB=	yes
GH_TAGNAME=	8e812cd

PORTEXAMPLES=	*
PORTDOCS=	README.rst README_l1.txt

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/nonparametric/_smoothers_lowess.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/nonparametric/linbin.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/tsa/kalmanf/kalman_loglike.so

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${WRKSRC}/README_l1.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
