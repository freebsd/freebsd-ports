PORTNAME=	django-advanced-filters
DISTVERSION=	2.0.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gettoknowmi@yahoo.com
COMMENT=	Django ModelAdmin mixin
WWW=		https://github.com/modlinltd/django-advanced-filters

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django52>=3.2:www/py-django52@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>=3.6.5<4:devel/py-simplejson@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
