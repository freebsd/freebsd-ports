PORTNAME=	flask_limiter
PORTVERSION=	3.13
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	Flask-Limiter adds rate limiting to Flask applications
WWW=		https://github.com/alisaifee/flask-limiter

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=2:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}limits>=2.8:www/py-limits@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ordered-set>4,<5:devel/py-ordered-set@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=12:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
