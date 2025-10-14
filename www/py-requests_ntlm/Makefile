PORTNAME=	requests_ntlm
DISTVERSION=	1.3.0
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	HTTP NTLM authentication using the requests library
WWW=		https://github.com/requests/requests-ntlm

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}isort>=5.13.2:devel/py-isort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyspnego>0:security/py-pyspnego@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>2.0.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-requests>0:devel/py-types-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}black>=24.4.2:devel/py-black@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist cryptography pytest

NO_ARCH=	yes

# tests as of 1.3.0: 9 failed, 10 passed in 9.55s

.include <bsd.port.mk>
