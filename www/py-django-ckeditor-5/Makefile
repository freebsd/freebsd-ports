PORTNAME=	django-ckeditor-5
DISTVERSION=	0.2.20
CATEGORIES=	www editors python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	gettoknowmi@yahoo.com
COMMENT=	Django ckeditor-5
WWW=		https://github.com/hvlads/django-ckeditor-5

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}django52>=4.2:www/py-django52@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
