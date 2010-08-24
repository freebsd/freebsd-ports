# New ports collection makefile for:	py-twistedMail
# Date created:		14 April 2005
# Whom:	      		Neal Nelson <neal@nelson.name>
#
# $FreeBSD$
#

PORTNAME=	twistedMail
PORTVERSION=	10.1.0
CATEGORIES=	mail devel python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Mail/${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedMail-${PORTVERSION}

MAINTAINER=	neal@nelson.name
COMMENT=	An SMTP, IMAP and POP protocol implementation with clients and servers

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore \
		${PYTHON_SITELIBDIR}/twisted/names:${PORTSDIR}/dns/py-twistedNames
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Twisted_Mail

.include <bsd.port.mk>
