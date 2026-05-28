PORTNAME=	django-mailman3
PORTVERSION=	1.3.15
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_mailman3-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Django library to help interaction with Mailman
WWW=		https://gitlab.com/mailman/django-mailman3

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>=0:devel/py-pdm-backend@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django-allauth>=0.63:www/py-django-allauth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-gravatar2>=1.0.6:www/py-django-gravatar2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django52>=4.2<5.3:www/py-django52@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mailmanclient>=3.3.3:mail/py-mailmanclient@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
