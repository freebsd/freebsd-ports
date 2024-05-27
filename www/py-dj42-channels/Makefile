PORTNAME=	channels
PORTVERSION=	4.0.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj42-

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Brings async, event-driven capabilities to Django
WWW=		https://channels.readthedocs.io/en/latest/ \
		https://github.com/django/channels

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Obsolete, please use www/py-channels instead
EXPIRATION_DATE=2024-06-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asgiref>=3.5.0<4:www/py-asgiref@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django42>=3.2:www/py-django42@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
