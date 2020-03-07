# $FreeBSD$

PORTNAME=	chempy
DISTVERSION=	0.7.10
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package useful for solving problems in chemistry

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}dot2tex>=2.11.3:print/dot2tex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PuLP>=1.6.8:math/py-PuLP@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyneqsys>=0.5.5:math/py-pyneqsys@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyodesys>=0.12.5:math/py-pyodesys@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=2.0.3:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}quantities>=0.12.1:science/py-quantities@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.0.1:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sym>=0.3.4:math/py-sym@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>=1.1.1:math/py-sympy@${PY_FLAVOR} \
		${NUMPY}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-flakes>0:devel/py-pytest-flakes@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

OPTIONS_DEFINE=		EXTRAS
OPTIONS_DEFAULT=	EXTRAS

EXTRAS_DESC=		Install optional dependencies for additional functionality
EXTRAS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>0:devel/py-appdirs@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}bokeh>=0.11.1:www/py-bokeh@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pycodeexport>=0.1.2:devel/py-pycodeexport@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pycompilation>=0.4.3:devel/py-pycompilation@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pygslodeiv2>=0.9.1:math/py-pygslodeiv2@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyodeint>=0.10.1:math/py-pyodeint@${PY_FLAVOR}

do-test:
	@cd ${WRKSRC} && pytest -rs --pyargs chempy

.include <bsd.port.mk>
