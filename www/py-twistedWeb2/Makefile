# New ports collection makefile for:	py-twistedWeb2
# Date created:		5 August 2005
# Whom:			Landon Fuller <landonf@opendarwin.org>
#
# $FreeBSD$

PORTNAME=	twistedWeb2
PORTVERSION=	0.1
PORTREVISION=	1
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

post-extract:
	# temporal hack to work with Twisted 2.4
	${ECHO_CMD} "from twisted.python import versions" > ${WRKSRC}/twisted/web2/_version.py
	${ECHO_CMD} "version = versions.Version(__name__[:__name__.rfind('.')], 0, 1, 0)" >> ${WRKSRC}/twisted/web2/_version.py

.include <bsd.port.mk>
