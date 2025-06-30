PORTNAME=	wagtail
PORTVERSION=	7.0.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Django content management system
WWW=		https://wagtail.io/ \
		https://github.com/wagtail/wagtail

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyascii>=0.1.5:textproc/py-anyascii@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.8<5:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django42>=4.2:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-filter>=23.3:www/py-django-filter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-modelcluster>=6.2.1<7.0:www/py-django-modelcluster@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-permissionedforms>=0.1<1.0:www/py-django-permissionedforms@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-taggit>=5.0<7:www/py-django-taggit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-tasks>=0.7<0.8:www/py-django-tasks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-treebeard>=4.5.1<5.0:www/py-django-treebeard@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}djangorestframework>=3.15.1,1<4.0,1:www/py-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}draftjs-exporter>=2.1.5<6.0:www/py-draftjs-exporter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}laces>=0.1<0.2:www/py-laces@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=3.0.10<4.0:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=9.1.0<12.0.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.11.1<3.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}telepath>=0.3.1<1:devel/py-telepath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}willow>=1.10.0<2:graphics/py-willow@${PY_FLAVOR}

USES=		cpe python shebangfix
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

CPE_VENDOR=	torchbox

SHEBANG_FILES=	wagtail/project_template/manage.py-tpl

.include <bsd.port.mk>
