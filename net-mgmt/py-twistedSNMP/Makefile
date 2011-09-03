# New ports collection makefile for:	py-twistedSNMP
# Date created:		8 May 2006
# Whom:			Zane C. Bowers <v.velox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	twistedSNMP
PORTVERSION=	0.3.13
PORTREVISION=	1
CATEGORIES=	net-mgmt python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedSNMP-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Twisted Python framework for doing SNMP stuff

DEPRECATED=	Relies on net-mgmt/py-snmp, which is deprecated
EXPIRATION=	2011-09-30

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/twisted/__init__.py:${PORTSDIR}/devel/py-twistedCore \
		${PYTHON_SITELIBDIR}/pysnmp/__init__.py:${PORTSDIR}/net-mgmt/py-snmp
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	TwistedSNMP

.include <bsd.port.mk>
