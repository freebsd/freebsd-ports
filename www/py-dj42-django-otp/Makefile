PORTNAME=	django-otp
PORTVERSION=	1.4.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
DISTNAME=	django_otp-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj42-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pluggable framework for adding two-factor authentication to Django
WWW=		https://github.com/django-otp/django-otp

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=3.2:www/py-django42@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
