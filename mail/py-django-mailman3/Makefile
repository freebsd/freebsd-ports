PORTNAME=	django-mailman3
PORTVERSION=	1.3.9
CATEGORIES=	mail
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libraries and templates for Django-based interfaces interacting with Mailman
WWW=		https://gitlab.com/mailman/django-mailman3

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django-allauth>0:www/py-django-allauth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-gravatar2>1.0.6:www/py-django-gravatar2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django32>3.2<4.2:www/py-django32@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mailmanclient>=3.3.3:mail/py-mailmanclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
