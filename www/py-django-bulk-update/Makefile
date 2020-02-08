# $FreeBSD$

PORTNAME=	django-bulk-update
PORTVERSION=	2.2.0
PORTREVISION=	5
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bulk update using a single query over Django ORM

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django111>=1.8:www/py-django111@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-extract:
	${RM} ${WRKSRC}/tests/__init__.py # prevent conflict with devel/py-phply in textproc/pootle

.include <bsd.port.mk>
