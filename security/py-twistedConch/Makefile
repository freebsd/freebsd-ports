# New ports collection makefile for:	py-twistedConch
# Date created:		13 April 2005
# Whom:	      		Neal Nelson <neal@nelson.name>
#
# $FreeBSD$
#

PORTNAME=	twistedConch
PORTVERSION=	12.1.0
CATEGORIES=	security devel python
MASTER_SITES=	http://twistedmatrix.com/Releases/Conch/${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedConch-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	An SSH and SFTP protocol implementation with clients and servers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twistedCore>=${PORTVERSION}:${PORTSDIR}/devel/py-twistedCore
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1>=0.0.9a:${PORTSDIR}/devel/py-asn1 \
		${PYTHON_PKGNAMEPREFIX}twistedCore>=${PORTVERSION}:${PORTSDIR}/devel/py-twistedCore

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	${PORTNAME:S/twisted/Twisted_/}

.include <bsd.port.mk>
