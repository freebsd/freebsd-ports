# New ports collection makefile for:	py-twistedNews
# Date created:		14 April 2005
# Whom:	      		Neal Nelson <neal@nelson.name>
#
# $FreeBSD$
#

PORTNAME=	twistedNews
PORTVERSION=	12.0.0
CATEGORIES=	news devel python
MASTER_SITES=	http://twistedmatrix.com/Releases/News/${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedNews-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	An NNTP protocol implementation with client and server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Twisted_News

.include <bsd.port.mk>
