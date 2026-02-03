PORTNAME=	django-annoying
PORTVERSION=	0.10.8
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_annoying-${PORTVERSION}

PATCH_SITES=	https://github.com/skorokithakis/django-annoying/commit/
PATCHFILES=	d1434314175dc8f7211ba525c5da6435b8d405c3.patch:-p1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Eliminate annoying things in the Django framework
WWW=		https://skorokithakis.github.io/django-annoying/ \
		https://github.com/skorokithakis/django-annoying

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=1.11:www/py-django42@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
