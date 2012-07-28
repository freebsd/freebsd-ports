# New ports collection makefile for:	py-twistedMail
# Date created:		14 April 2005
# Whom:	      		Neal Nelson <neal@nelson.name>
#
# $FreeBSD$
#

PORTNAME=	twistedMail
PORTVERSION=	12.1.0
CATEGORIES=	mail devel python
MASTER_SITES=	http://twistedmatrix.com/Releases/Mail/${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedMail-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	SMTP, IMAP, and POP protocol implementation with clients and servers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twistedCore>=${PORTVERSION}:${PORTSDIR}/devel/py-twistedCore \
		${PYTHON_PKGNAMEPREFIX}twistedNames>=${PORTVERSION}:${PORTSDIR}/dns/py-twistedNames
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	${PORTNAME:S/twisted/Twisted_/}

.include <bsd.port.mk>
