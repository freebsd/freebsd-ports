# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wagtail
PORTVERSION=	2.4
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Django content management system

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.5.1:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-modelcluster>=4.2:www/py-django-modelcluster@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-taggit>=0.23:www/py-django-taggit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-treebeard>=4.2.0:www/py-django-treebeard@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django111>=1.11:www/py-django111@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}djangorestframework>=3.7.4:www/py-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}draftjs_exporter>=2.1.5:www/py-draftjs_exporter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>=0.999:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=4.0.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2016.6:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.11.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.11:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unidecode>=0.04.14:converters/py-unidecode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}willow>=1.1:graphics/py-willow@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

SHEBANG_FILES=	wagtail/project_template/manage.py

.include <bsd.port.mk>
