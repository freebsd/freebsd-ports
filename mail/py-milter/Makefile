# New ports collection makefile for:    py-miler
# Date created:         26 april 2002
# Whom:                 Vsevolod Lobko <seva@sevasoft.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	milter
PORTVERSION=	0.5.2
CATEGORIES=	mail python
MASTER_SITES=	http://www.bmsi.com/python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	seva@sevasoft.kiev.ua

.if !exists(/usr/lib/libmilter.so)
LIB_DEPENDS=	milter.2:${PORTSDIR}/mail/sendmail
.endif

DIST_SUBDIR=	python
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
