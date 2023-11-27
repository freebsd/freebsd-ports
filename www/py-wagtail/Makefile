PORTNAME=	wagtail
PORTVERSION=	5.2.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Django content management system
WWW=		https://wagtail.io/ \
		https://github.com/wagtail/wagtail

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyascii>=0.1.5:textproc/py-anyascii@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.8<4.13:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django32>=3.2<4.3:www/py-django32@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-filter>=23.3<24:www/py-django-filter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-modelcluster>=6.1<7.0:www/py-django-modelcluster@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-permissionedforms>=0.1<1.0:www/py-django-permissionedforms@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-taggit>=2.0<5.0:www/py-django-taggit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-treebeard>=4.5.1<5.0:www/py-django-treebeard@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}djangorestframework>=3.11.1,1<4.0,1:www/py-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}draftjs-exporter>=2.1.5:www/py-draftjs-exporter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>=0.999<2:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}l18n>=2018.5:devel/py-l18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=3.0.10<4.0:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=9.1.0<11.0.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.11.1<3.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}telepath>=0.1.1<1:devel/py-telepath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}willow>=1.6.2<1.7:graphics/py-willow@${PY_FLAVOR}

USES=		cpe python shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

CPE_VENDOR=	torchbox

SHEBANG_FILES=	wagtail/project_template/manage.py

.include <bsd.port.mk>
