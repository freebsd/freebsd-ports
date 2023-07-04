PORTNAME=	emmet-core
DISTVERSION=	0.58.1
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Materials API Toolkit for the Materials Project
WWW=		https://github.com/materialsproject/emmet

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}monty>=2021.3:devel/py-monty@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybtex>=0.24:textproc/py-pybtex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic>=1.10.2:devel/py-pydantic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spglib>=2.0.1:science/py-spglib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.7<5.0:devel/py-typing-extensions@${PY_FLAVOR}
#RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pymatgen>=2023.5.8:science/py-pymatgen@${PY_FLAVOR} # break dependency circle: pymatgen -> mp-api -> emmet-core, see https://github.com/materialsproject/api/issues/825

USES=		python pytest
USE_PYTHON=	distutils autoplist pytest

.include <bsd.port.mk>
