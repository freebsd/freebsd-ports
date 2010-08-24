# New ports collection makefile for:	py-twistedWords
# Date created:		14 April 2005
# Whom:	      		Neal Nelson <neal@nelson.name>
#
# $FreeBSD$
#

PORTNAME=	twistedWords
PORTVERSION=	10.1.0
CATEGORIES=	net-im devel python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Words/${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedWords-${PORTVERSION}

MAINTAINER=	neal@nelson.name
COMMENT=	Twisted Words has more chat than you can handle

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Twisted_Words

.include <bsd.port.mk>
