# New ports collection makefile for:	py-twistedConch
# Date created:		13 April 2005
# Whom:	      		Neal Nelson <neal@nelson.name>
#
# $FreeBSD$
#

PORTNAME=	twistedConch
PORTVERSION=	10.1.0
CATEGORIES=	security devel python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Conch/${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedConch-${PORTVERSION}

MAINTAINER=	neal@nelson.name
COMMENT=	An SSH and SFTP protocol implementation with clients and servers

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore \
		${PYTHON_PKGNAMEPREFIX}asn1>=0.0.9a:${PORTSDIR}/devel/py-asn1

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Twisted_Conch

.include <bsd.port.mk>
