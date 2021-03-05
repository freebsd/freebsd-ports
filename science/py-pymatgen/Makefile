# $FreeBSD$

PORTNAME=	pymatgen
DISTVERSION=	2021.3.3
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python Materials Genomics is a robust materials analysis code

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.9.3:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=1.5:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}monty>=3.0.2:devel/py-monty@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2.2:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}palettable>=3.1.1:misc/py-palettable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plotly>=4.5.0:graphics/py-plotly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.15.6:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.5.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spglib>=1.9.9.44:science/py-spglib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>0:devel/py-tabulate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.7.4.3:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uncertainties>=3.1.4:math/py-uncertainties@${PY_FLAVOR}

USES=		compiler:c++11-lang python:3.7+
USE_PYTHON=	distutils cython concurrent autoplist

post-install:
	@cd ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME} && ${STRIP_CMD} \
		optimization/linear_assignment.so \
		optimization/neighbors.so \
		util/coord_cython.so

.include <bsd.port.mk>
