# Created by: Kevin Golding <ports@caomhin.org>
# $FreeBSD$

PORTNAME=	django-keyedcache
PORTVERSION=	1.4.4
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://www.caomhin.org/ports/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Simplified, speedy way to manage caching in Django apps

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:${PORTSDIR}/www/py-django

LICENSE=	BSD

WRKSRC=		${WRKDIR}/bkroeze-django-keyedcache-4be18235b372
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
