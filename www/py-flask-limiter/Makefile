PORTNAME=	flask_limiter
PORTVERSION=	4.1.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	Flask-Limiter adds rate limiting to Flask applications
WWW=		https://github.com/alisaifee/flask-limiter

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR}

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=2:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}limits>=3.13:www/py-limits@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ordered-set>4,<5:devel/py-ordered-set@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.3:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
