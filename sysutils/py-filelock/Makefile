PORTNAME=	filelock
DISTVERSION=	3.10.3
PORTREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Platform independent file lock
WWW=		https://github.com/benediktschmitt/py-filelock

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.13:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0.3:devel/py-hatch-vcs@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}covdefaults>0:devel/py-covdefaults@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>=7.0.1:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>=2.1:devel/py-pytest-timeout@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

.include <bsd.port.mk>
