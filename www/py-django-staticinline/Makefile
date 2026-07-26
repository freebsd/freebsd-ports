PORTNAME=	django-staticinline
DISTVERSION=	1.4
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Django template tag to load static files inline with your template
WWW=		https://github.com/bartTC/django-staticinline

LICENSE=	MIT
#LICENSE_FILE=  Not yet packaged in sdist

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django52>=2.2:www/py-django52@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
