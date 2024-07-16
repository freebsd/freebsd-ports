PORTNAME=	pytensor
DISTVERSION=	2.25.2
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Optimizing compiler for evaluating mathematical expressions
WWW=		https://pytensor.readthedocs.io/en/latest/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/doc/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}versioneer>0:devel/py-versioneer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PY_DEPENDS}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cons>0:devel/py-cons@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}etuples>0:devel/py-etuples@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filelock>=3.15:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}logical-unification>0:math/py-logical-unification@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}miniKanren>0:devel/py-miniKanren@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.14:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 cython autoplist pytest # tests fail to run, see https://github.com/pymc-devs/pytensor/issues/355

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pytensor/scan/scan_perform${PYTHON_EXT_SUFFIX}.so

# BUG: installs the file /usr/local/lib/python3.9/site-packages/bin/__init__.py, see https://github.com/pymc-devs/pytensor/issues/356

.include <bsd.port.mk>
