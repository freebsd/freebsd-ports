# New ports collection makefile for:	py-gsl
# Date created:		14 February 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	gsl
PORTVERSION=	0.0.4
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pygsl
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pygsl-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	perky@FreeBSD.org

LIB_DEPENDS=	gsl.3:${PORTSDIR}/math/gsl

PLIST_SUB=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S,^${LOCALBASE}/,,g}
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
