# Created by: Landon Fuller <landonf@opendarwin.org>
# $FreeBSD$

PORTNAME=	twistedWeb2
PORTVERSION=	8.1.0
PORTREVISION=	1
CATEGORIES=	www devel python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Web2/${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedWeb2-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	The next generation Web Server Framework built with Twisted

LICENSE=	MIT

WRKSRC=		${WRKDIR}/TwistedWeb2-${PORTVERSION}

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes
USES=		tar:bzip2 twisted

.include <bsd.port.mk>
