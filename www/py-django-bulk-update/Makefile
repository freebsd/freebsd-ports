# $FreeBSD$

PORTNAME=	django-bulk-update
PORTVERSION=	2.2.0
PORTREVISION=	4
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bulk update using a single query over Django ORM

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>=1.11:www/py-django@${PY_FLAVOR}

USES=		python:-3.4
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-extract:
	${RM} ${WRKSRC}/tests/__init__.py # prevent conflict with devel/py-phply in textproc/pootle

.include <bsd.port.mk>
