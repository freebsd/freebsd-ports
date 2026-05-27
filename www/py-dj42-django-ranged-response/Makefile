PORTNAME=	django-ranged-response
DISTVERSION=	0.2.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj42-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modified Django FileResponse that adds Content-Range headers
WWW=		https://github.com/i3thuan5/django-ranged-response

LICENSE=	MIT

DEPRECATED=	Serves as a transition only for www/seahub and requires Django 4.2, which has been end-of-life since April
EXPIRATION_DATE=2026-08-31

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=0:www/py-django42@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=	yes

.include <bsd.port.mk>
