# New ports collection makefile for:	py-twistedPair
# Date created:		14 April 2005
# Whom:	      		Neal Nelson <neal@nelson.name>
#
# $FreeBSD$
#

PORTNAME=	twistedPair
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	net devel python
MASTER_SITES=	http://twistedmatrix.com/downloads/Pair/0.1/ \
		http://tmrc.mit.edu/mirror/twisted/Pair/0.1/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedPair-${PORTVERSION}

MAINTAINER=	neal@nelson.name
COMMENT=	Twisted Pair can do low level TCP work

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/TwistedPair-${PORTVERSION}

USE_BZIP2=	yes
USE_PYTHON=	2.2+
USE_PYDISTUTILS=	yes

PLIST_SUB+=	S=${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}

.include <bsd.port.mk>
