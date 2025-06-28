PORTNAME=	trio
DISTVERSION=	0.30.0
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Library for async concurrency and I/O
WWW=		https://pypi.org/project/trio/ \
		https://github.com/python-trio/trio

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.APACHE2
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE.MIT

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PY_EXCEPTIONGROUP} \
		${PYTHON_PKGNAMEPREFIX}async_generator>0:devel/py-async_generator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>=19.2.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cffi>=1.14:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>0:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}outcome>0:devel/py-outcome@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sniffio>0:devel/py-sniffio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>0:devel/py-sortedcontainers@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astor>=0:devel/py-astor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}black>=0:devel/py-black@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jedi>=0.18.0:devel/py-jedi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruff>=0:devel/py-ruff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trustme>=0:security/py-trustme@${PY_FLAVOR} \
		pylint${PYTHON_PKGNAMESUFFIX}>=0:devel/pylint@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

do-test:
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.mk>
