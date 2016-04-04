# Created by: Kevin Golding <ports@caomhin.org>
# $FreeBSD$

PORTNAME=	django-threaded-multihost
PORTVERSION=	1.4.1
PORTREVISION=	3
CATEGORIES=	www python
MASTER_SITES=	http://www.caomhin.org/geek/ports/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Multi-host utilities to Django

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_hg>=0.4:devel/py-setuptools_hg
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:www/py-django18

LICENSE=	BSD3CLAUSE

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
