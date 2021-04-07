PORTNAME=	django-assets
PORTVERSION=	2.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Compress and merge CSS and Javascript files

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=1.7:www/py-django22@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webassets>=2.0:www/py-webassets@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
