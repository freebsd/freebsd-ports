PORTNAME=	ipygany
DISTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	3-D scientific visualization in Jupyter Notebooks
WWW=		https://github.com/martinRenou/ipygany

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jupyter-packaging>0:devel/py-jupyter-packaging@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipywidgets>0:devel/py-ipywidgets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traittypes>0:devel/py-traittypes@${PY_FLAVOR} \
		${PYNUMPY}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipydatawidgets>0:devel/py-ipydatawidgets@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist pytest

NO_ARCH=	yes

.include <bsd.port.mk>
