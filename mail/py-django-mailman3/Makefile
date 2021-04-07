PORTNAME=	django-mailman3
PORTVERSION=	1.3.4
CATEGORIES=	mail
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Libraries and templates for Django-based interfaces interacting with Mailman

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>0:www/py-django22@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mailmanclient>=3.3.1:mail/py-mailmanclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-allauth>0:www/py-django-allauth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-gravatar2>1.0.6:www/py-django-gravatar2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
