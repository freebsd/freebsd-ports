# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wagtail
PORTVERSION=	2.9
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Django content management system

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup448>=4.8<4.9:www/py-beautifulsoup448@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django22>=2.1<3.1:www/py-django22@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-modelcluster>=5.0<6.0:www/py-django-modelcluster@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-taggit>=1.0<2.0:www/py-dj22-django-taggit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-treebeard>=4.2.0<5.0:www/py-dj22-django-treebeard@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-djangorestframework>=3.7.4<4.0:www/py-dj22-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}draftjs_exporter>=2.1.5:www/py-draftjs_exporter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>=0.999<2:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}l18n>=2018.5:devel/py-l18n@${PY_FLAVOR} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.11.1<3.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unidecode>=0.04.14<2.0:converters/py-unidecode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}willow>=1.3<1.4:graphics/py-willow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XlsxWriter>=1.2.8<2.0:textproc/py-xlsxwriter@${PY_FLAVOR}

USES=		cpe python:3.5+ shebangfix
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

CPE_VENDOR=	torchbox

SHEBANG_FILES=	wagtail/project_template/manage.py

.include <bsd.port.mk>
