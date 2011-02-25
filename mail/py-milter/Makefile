# New ports collection makefile for:    py-milter
# Date created:         26 april 2002
# Whom:                 Vsevolod Lobko <seva@sevasoft.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	milter
PORTVERSION=	0.8.7
PORTREVISION=	1
CATEGORIES=	mail python
MASTER_SITES=	SF/py${PORTNAME}/OldFiles \
		http://www.bmsi.com/python/

PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	georg@graf.priv.at
COMMENT=	Python interface to sendmail-8.1x milter API

.if !exists(/usr/lib/libmilter.so)
LIB_DEPENDS=	milter.2:${PORTSDIR}/mail/sendmail
.endif

DIST_SUBDIR=	python
USE_PYTHON=	2.5-2.9
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
