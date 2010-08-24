# New ports collection makefile for:	py-twistedNews
# Date created:		14 April 2005
# Whom:	      		Neal Nelson <neal@nelson.name>
#
# $FreeBSD$
#

PORTNAME=	twistedNews
PORTVERSION=	10.1.0
CATEGORIES=	news devel python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/News/${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedNews-${PORTVERSION}

MAINTAINER=	neal@nelson.name
COMMENT=	An NNTP protocol implementation with client and server

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Twisted_News

.include <bsd.port.mk>
