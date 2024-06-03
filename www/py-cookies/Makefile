PORTNAME=	cookies
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	www devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Friendlier RFC 6265-compliant cookie parser/renderer
WWW=		https://gitlab.com/sashahart/cookies

LICENSE=	MIT

BROKEN=		does not build with Python 3.11
DEPRECATED=	Upstream is inactive for many years
EXPIRATION_DATE=2024-06-30

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
