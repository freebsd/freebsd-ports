PORTNAME=	django-extensions
PORTVERSION=	3.2.3
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj52-

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Global custom management extensions for the Django Framework
WWW=		https://github.com/django-extensions/django-extensions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=     Obsolete, please use www/py-django-extensions instead
EXPIRATION_DATE=2026-06-30

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django52>=5.2:www/py-django52@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
