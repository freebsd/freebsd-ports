PORTNAME=	django-cron
PORTVERSION=	0.6.0
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Running Python crons in a Django project
WWW=		https://github.com/tivix/django-cron

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Upstream inactive since 3+ years, not compatible with Django 5.2 or newer
EXPIRATION_DATE=2026-03-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=3.2:www/py-django42@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
