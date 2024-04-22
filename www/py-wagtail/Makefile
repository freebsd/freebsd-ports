PORTNAME=	wagtail
PORTVERSION=	6.0.2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Django content management system
WWW=		https://wagtail.io/ \
		https://github.com/wagtail/wagtail

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyascii>=0.1.5:textproc/py-anyascii@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.8<4.13:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django42>=4.2<6.0:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj42-django-filter>=23.3<24:www/py-dj42-django-filter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj42-django-modelcluster>=6.2.1<7.0:www/py-dj42-django-modelcluster@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj42-django-permissionedforms>=0.1<1.0:www/py-dj42-django-permissionedforms@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj42-django-taggit>=4.0<5.1:www/py-dj42-django-taggit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj42-django-treebeard>=4.5.1<5.0:www/py-dj42-django-treebeard@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj42-djangorestframework>=3.11.1<4.0:www/py-dj42-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}draftjs-exporter>=2.1.5<6.0:www/py-draftjs-exporter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>=0.999<2:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}l18n>=2018.5:devel/py-l18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}laces>=0.1<0.2:www/py-laces@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=3.0.10<4.0:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=9.1.0<11.0.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.11.1<3.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}telepath>=0.3.1<1:devel/py-telepath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}willow>=1.6.2<2:graphics/py-willow@${PY_FLAVOR}

USES=		cpe python shebangfix
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

CPE_VENDOR=	torchbox

SHEBANG_FILES=	wagtail/project_template/manage.py

.include <bsd.port.mk>
