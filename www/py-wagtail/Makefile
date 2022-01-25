# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	wagtail
PORTVERSION=	2.15.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Django content management system

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyascii>=0.1.5:textproc/py-anyascii@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.8<4.11:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django32>=3.0<3.3:www/py-django32@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj32-django-filter>=2.2<22:www/py-dj32-django-filter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj32-django-modelcluster>=5.2<6.0:www/py-dj32-django-modelcluster@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj32-django-taggit>=1.0:www/py-dj32-django-taggit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj32-django-treebeard>=4.2.0<5.0:www/py-dj32-django-treebeard@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj32-djangorestframework>=3.11.1<4.0:www/py-dj32-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}draftjs-exporter>=2.1.5:www/py-draftjs-exporter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>=0.999<2:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}l18n>=2018.5:devel/py-l18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=4.0.0<10.0.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.11.1<3.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tablib>=0.14.0:textproc/py-tablib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}telepath>=0.1.1<1:devel/py-telepath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}willow>=1.4<1.5:graphics/py-willow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XlsxWriter>=1.2.8<4.0:textproc/py-xlsxwriter@${PY_FLAVOR}

USES=		cpe python:3.6+ shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

CPE_VENDOR=	torchbox

SHEBANG_FILES=	wagtail/project_template/manage.py

.include <bsd.port.mk>
