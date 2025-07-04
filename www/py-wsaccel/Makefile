PORTNAME=	wsaccel
DISTVERSION=	0.6.7
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	WebSocket Accelerator for ws4py and AutobahnPython
WWW=		https://github.com/methane/wsaccel

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Upstream ceased development
EXPIRATION_DATE=2025-08-03

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist cython3 pep517 pytest

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/utf8validator*.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/xormask*.so

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENVI} ${WRK_ENV} ${TEST_ENV} pytest \
		-k '${_PYTEST_FILTER_EXPRESSION}' \
		-v -rs -o addopts= \
		${PYTEST_ARGS})

.include <bsd.port.mk>
