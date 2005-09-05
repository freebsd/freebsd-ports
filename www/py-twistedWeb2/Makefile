# New ports collection makefile for:	py-twistedWeb2
# Date created:		5 August 2005
# Whom:			Landon Fuller <landonf@opendarwin.org>
#
# $FreeBSD$

PORTNAME=	twistedWeb2
PORTVERSION=	0.1
CATEGORIES=	www devel python
MASTER_SITES=	http://twistedmatrix.com/downloads/Web2/ \
		http://tmrc.mit.edu/mirror/twisted/Web2/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedWeb2-${PORTVERSION}

MAINTAINER=	landonf@opendarwin.org
COMMENT=	The next generation Web Server Framework built with Twisted

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/TwistedWeb2-${PORTVERSION}

USE_BZIP2=	yes
USE_PYTHON=	2.2+
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
