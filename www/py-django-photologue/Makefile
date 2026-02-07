PORTNAME=	django-photologue
PORTVERSION=	3.18
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Powerful image management and gallery application for Django
WWW=		https://github.com/richardbarran/django-photologue

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=4.2:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-sortedm2m>=4.0.0:www/py-django-sortedm2m@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ExifRead>=3:graphics/py-exifread@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=10:graphics/py-pillow@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
