PORTNAME=	Flask_Limiter
PORTVERSION=	3.12
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	3
DISTNAME=	flask_limiter-${PORTVERSION}

MAINTAINER=	matthew@wener.org
COMMENT=	Flask-Limiter adds rate limiting to Flask applications
WWW=		https://github.com/alisaifee/flask-limiter

LICENSE=	MIT

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=2:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}limits>=3.13:www/py-limits@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ordered-set>4,<5:devel/py-ordered-set@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=12:textproc/py-rich@${PY_FLAVOR} \

USES=		python
USE_PYTHON=	autoplist concurrent pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}flask_limiter

NO_ARCH=	yes

.include <bsd.port.mk>
