PORTNAME=	limits
PORTVERSION=	3.9.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	Perform rate limiting with commonly used storage backends
WWW=		https://github.com/alisaifee/limits

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}deprecated>=1.2:devel/py-deprecated@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-resources>=1.3:devel/py-importlib-resources@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=21,<24:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0.8:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
