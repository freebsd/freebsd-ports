# New ports collection makefile for:	py-twistedPair
# Date created:		14 April 2005
# Whom:	      		Neal Nelson <neal@nelson.name>
#
# $FreeBSD$
#

PORTNAME=	twistedPair
PORTVERSION=	9.0.0
CATEGORIES=	net devel python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Pair/${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedPair-${PORTVERSION}

MAINTAINER=	neal@nelson.name
COMMENT=	Twisted Pair can do low level TCP work

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/TwistedPair-${PORTVERSION}

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Twisted_Pair

.include <bsd.port.mk>
