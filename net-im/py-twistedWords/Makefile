# New ports collection makefile for:	py-twistedWords
# Date created:		14 April 2005
# Whom:	      		Neal Nelson <neal@nelson.name>
#
# $FreeBSD$
#

PORTNAME=	twistedWords
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	net devel python
MASTER_SITES=	http://twistedmatrix.com/downloads/Words/0.1/ \
		http://tmrc.mit.edu/mirror/twisted/Words/0.1/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedWords-${PORTVERSION}

MAINTAINER=	neal@nelson.name
COMMENT=	Twisted Words has more chat than you can handle

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/TwistedWords-${PORTVERSION}

USE_BZIP2=	yes
USE_PYTHON=	2.2+
USE_PYDISTUTILS=	yes

PLIST_SUB+=	S=${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}

.include <bsd.port.mk>
