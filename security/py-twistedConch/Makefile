# New ports collection makefile for:	py-twistedConch
# Date created:		13 April 2005
# Whom:	      		Neal Nelson <neal@nelson.name>
#
# $FreeBSD$
#

PORTNAME=	twistedConch
PORTVERSION=	0.8.0
CATEGORIES=	security devel python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Conch/${PORTVERSION:S/.0//}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedConch-${PORTVERSION}

MAINTAINER=	neal@nelson.name
COMMENT=	An SSH and SFTP protocol implementation with clients and servers

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Conch

.include <bsd.port.mk>
