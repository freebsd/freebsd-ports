PORTNAME=	postorius
PORTVERSION=	1.3.7
CATEGORIES=	www
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Django app provoding web user interface to access GNU Mailman
WWW=		https://pypi.org/project/postorius/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django-gravatar2>1.0.6:www/py-django-gravatar2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-mailman3>=1.3.8:mail/py-django-mailman3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django32>=3.2<4.2:www/py-django32@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mailmanclient>=3.3.3:mail/py-mailmanclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}readme-renderer>0:devel/py-readme-renderer@${PY_FLAVOR}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isort>0:devel/py-isort@${PY_FLAVOR}

USES=		cpe python:3.6+
CPE_VENDOR=	${PORTNAME}_project
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
