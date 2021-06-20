# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	wagtail
PORTVERSION=	2.13.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Django content management system

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyascii>=0.1.5:textproc/py-anyascii@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.8<4.10:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django22>=2.1<3.3:www/py-django22@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-modelcluster>=5.1<6.0:www/py-django-modelcluster@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-taggit>=1.0<2.0:www/py-django-taggit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-treebeard>=4.2.0<5.0:www/py-django-treebeard@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}djangorestframework>=3.11.1,1<4.0,1:www/py-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}draftjs-exporter>=2.1.5:www/py-draftjs-exporter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>=0.999<2:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}l18n>=2018.5:devel/py-l18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=4.0.0<9.0.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.11.1<3.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}telepath>=0.1.1<1:devel/py-telepath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}willow>=1.4<1.5:graphics/py-willow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XlsxWriter>=1.2.8<2.0:textproc/py-xlsxwriter@${PY_FLAVOR}

USES=		cpe python:3.6+ shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

CPE_VENDOR=	torchbox

SHEBANG_FILES=	wagtail/project_template/manage.py

.include <bsd.port.mk>
