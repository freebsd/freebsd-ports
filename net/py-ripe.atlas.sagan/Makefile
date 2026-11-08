PORTNAME=	ripe.atlas.sagan
DISTVERSION=	2.0.1
DISTNAME=	ripe_atlas_sagan-${DISTVERSION}

CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zarychtam@plan-b.pwste.edu.pl
COMMENT=	Parsing library for RIPE Atlas measurement results
WWW=		https://github.com/RIPE-NCC/ripe.atlas.sagan

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-dateutil>0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cryptography pep517 pytest
PYTEST_IGNORED_TESTS=	test_invalid_country_code #WIP

TEST_ARGS=	tests/*.py

NO_ARCH=	yes

.include <bsd.port.mk>
