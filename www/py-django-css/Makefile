# New ports collection makefile for:	py-django-css
# Date created:		2011-05-31
# Whom:			Lung-Pin Chang <changlp@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	django-css
PORTVERSION=	2.3.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	changlp@cs.nctu.edu.tw
COMMENT=	Django application that automates CSS compilation and compression

DEPRECATED=	Upstream development stopped. Use www/py-django_compressor instead
EXPIRATION_DATE=2012-05-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:${PORTSDIR}/www/py-beautifulsoup

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
