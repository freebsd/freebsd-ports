PORTNAME=	uhi
DISTVERSION=	0.4.0
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Universal Histogram Interface
WWW=		https://uhi.readthedocs.io/en/latest/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boost-histogram>=1.0:misc/py-boost-histogram@${PY_FLAVOR}

USES=		compiler:c++14-lang python
USE_PYTHON=	pep517 autoplist pytest # tests fail fail to run: KeyError: <WorkerController gw0>, see https://github.com/scikit-hep/uhi/issues/125

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

pre-configure: # uhi is officially built with "build" (https://github.com/pypa/build), but this is easily circumvented with this simple setup.py
	@( \
		${ECHO} "from setuptools import setup" && \
		${ECHO} "setup()" \
	) > ${WRKSRC}/setup.py

.include <bsd.port.mk>
