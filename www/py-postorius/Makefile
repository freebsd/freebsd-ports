PORTNAME=	postorius
PORTVERSION=	1.3.12
CATEGORIES=	www
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Web user interface for GNU Mailman
WWW=		https://gitlab.com/mailman/postorius

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>=0:devel/py-pdm-backend@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django-mailman3>=1.3.13:mail/py-django-mailman3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django42>=4.2<5.1:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mailmanclient>=3.3.3:mail/py-mailmanclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}readme-renderer>=0:devel/py-readme-renderer@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-debug-toolbar>=0:www/py-django-debug-toolbar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-requests-debug-toolbar>=0:www/py-django-requests-debug-toolbar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isort>=0:devel/py-isort@${PY_FLAVOR}

USES=		cpe python shebangfix
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

CPE_VENDOR=	postorius_project

SHEBANG_FILES=	example_project/manage.py

.include <bsd.port.mk>
