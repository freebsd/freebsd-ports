# Created by: Kevin Golding <ports@caomhin.org>
# $FreeBSD$

PORTNAME=	django-signals-ahoy
PORTVERSION=	0.1.0
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	http://cdn.bitbucket.org/bkroeze/django-signals-ahoy/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION:C/([[:digit:]]\.[[:digit:]])\./\1-/g}

MAINTAINER=	ports@caomhin.org
COMMENT=	Extended set of signals for use by Django apps

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:${PORTSDIR}/www/py-django

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

post-extract:
	${RM} -r ${WRKSRC}/tests

.include <bsd.port.mk>
