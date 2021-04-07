PORTNAME=	postorius
PORTVERSION=	1.3.3
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Django app provoding web user interface to access GNU Mailman

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django-mailman3>=1.3.3:mail/py-django-mailman3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django22>0:www/py-django22@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mailmanclient>=3.3.1:mail/py-mailmanclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-gravatar2>1.0.6:www/py-django-gravatar2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}readme-renderer>0:devel/py-readme-renderer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isort>0:devel/py-isort@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
