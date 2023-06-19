PORTNAME=	iminuit
DISTVERSION=	2.21.3
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Jupyter-friendly Python frontend for MINUIT2 in C++
WWW=		https://iminuit.readthedocs.io/en/stable/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake-core
RUN_DEPENDS=	${PYNUMPY}

USES=		compiler:c++14-lang python:3.9+
USE_PYTHON=	distutils autoplist pytest # 1 test fails, see https://github.com/scikit-hep/iminuit/issues/901

TEST_ENV=      ${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
