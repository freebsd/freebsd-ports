PORTNAME=	chempy
DISTVERSION=	0.9.0
PORTREVISION=	3
CATEGORIES=	science python # chemistry
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package useful for solving problems in chemistry
WWW=		https://github.com/bjodah/chempy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dot2tex>=2.11.3:print/dot2tex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=2.2.3:math/py-matplotlib@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}PuLP>=1.6.8:math/py-PuLP@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyneqsys>=0.5.5:math/py-pyneqsys@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyodesys>=0.14.1:math/py-pyodesys@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=2.0.3:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}quantities>=0.12.1:science/py-quantities@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.0.1:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sym>=0.3.4:math/py-sym@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>=1.1.1:math/py-sympy@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}black>0:devel/py-black@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-flakes>0:devel/py-pytest-flakes@${PY_FLAVOR} \
		gsl>0:math/gsl

USES=		localbase:ldflags python # localbase and math/gsl are only for tests
USE_PYTHON=	distutils autoplist pytest # 5 tests fail, see https://github.com/bjodah/chempy/issues/222

NO_ARCH=	yes

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}pymol # https://github.com/schrodinger/pymol-open-source/issues/100

OPTIONS_DEFINE=		EXTRAS
OPTIONS_DEFAULT=	EXTRAS

EXTRAS_DESC=		Install optional dependencies for additional functionality
EXTRAS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>0:devel/py-appdirs@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}bokeh>=0.13.0:www/py-bokeh@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}ipywidgets>0:devel/py-ipywidgets@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pycodeexport>=0.1.3:devel/py-pycodeexport@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pycompilation>=0.4.12:devel/py-pycompilation@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pygslodeiv2>=0.9.4:math/py-pygslodeiv2@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyodeint>=0.10.4:math/py-pyodeint@${PY_FLAVOR}
			# TODO pycvodes>=0.14.0, pykinsol>=0.1.6

.include <bsd.port.mk>
