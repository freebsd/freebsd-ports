# Created by: Kevin Golding <ports@caomhin.org>
# $FreeBSD$

PORTNAME=	django-extensions
PORTVERSION=	1.3.8
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Global custom management extensions for the Django Framework

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>0:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six

USES=		python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
