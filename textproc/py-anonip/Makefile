PORTNAME=	anonip
PORTVERSION=	1.1.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	m.ne@gmx.net
COMMENT=	Tool to anonymize IP addresses in log files
WWW=		https://github.com/DigitaleGesellschaft/Anonip

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

TEST_ARGS=	tests.py

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest
NO_ARCH=	yes

.include <bsd.port.mk>
