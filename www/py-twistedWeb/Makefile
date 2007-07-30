# New ports collection makefile for:	py-twistedWeb
# Date created:		14 April 2005
# Whom:	      		Neal Nelson <neal@nelson.name>
#
# $FreeBSD$
#

PORTNAME=	twistedWeb
PORTVERSION=	0.7.0
CATEGORIES=	www devel python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Web/${PORTVERSION:S/.0//}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedWeb-${PORTVERSION}

MAINTAINER=	neal@nelson.name
COMMENT=	An HTTP protocol implementation together with clients and servers

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Twisted_Web

.include <bsd.port.mk>
