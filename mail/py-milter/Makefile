# New ports collection makefile for:    py-milter
# Date created:         26 april 2002
# Whom:                 Vsevolod Lobko <seva@sevasoft.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	milter
PORTVERSION=	0.9.5
CATEGORIES=	mail python
MASTER_SITES=	SOURCEFORGE
MASTER_SITE_SUBDIR=	${PYPORTNAME}/${PYPORTNAME}/${DISTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYPORTNAME}-${PORTVERSION}

MAINTAINER=	georg@graf.priv.at
COMMENT=	Python interface to Sendmail milter API

LICENSE=	GPLv2

.if !exists(/usr/lib/libmilter.so)
LIB_DEPENDS=	milter:${PORTSDIR}/mail/sendmail
.endif

PYPORTNAME=	${PKGNAMEPREFIX:C/[0-9]+-//}${PORTNAME}

DIST_SUBDIR=	python
USE_PYTHON=	2.6-2.9
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	${PYPORTNAME}

.include <bsd.port.mk>
