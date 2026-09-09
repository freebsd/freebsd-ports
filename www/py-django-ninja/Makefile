PORTNAME=	django-ninja
PORTVERSION=	1.7.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_ninja-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Django Ninja - Fast Django REST framework
WWW=		https://django-ninja.dev/ \
		https://github.com/vitalik/django-ninja

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.8<5:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django52>=3.1:www/py-django52@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0<3.0.0:devel/py-pydantic2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
