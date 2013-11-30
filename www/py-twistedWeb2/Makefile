# Created by: Landon Fuller <landonf@opendarwin.org>
# $FreeBSD$

PORTNAME=	twistedWeb2
PORTVERSION=	8.1.0
CATEGORIES=	www devel python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Web2/${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedWeb2-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	The next generation Web Server Framework built with Twisted

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/TwistedWeb2-${PORTVERSION}

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Twisted_Web2

.include <bsd.port.mk>
