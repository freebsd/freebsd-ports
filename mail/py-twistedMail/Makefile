# New ports collection makefile for:	py-twistedMail
# Date created:		14 April 2005
# Whom:	      		Neal Nelson <neal@nelson.name>
#
# $FreeBSD$
#

PORTNAME=	twistedMail
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	mail devel python
MASTER_SITES=	http://twistedmatrix.com/downloads/Mail/0.1/ \
		http://tmrc.mit.edu/mirror/twisted/Mail/0.1/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedMail-${PORTVERSION}

MAINTAINER=	neal@nelson.name
COMMENT=	An SMTP, IMAP and POP protocol implementation with clients and servers

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore \
		${PYTHON_SITELIBDIR}/twisted/names:${PORTSDIR}/dns/py-twistedNames
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/TwistedMail-${PORTVERSION}

USE_BZIP2=	yes
USE_PYTHON=	2.2+
USE_PYDISTUTILS=	yes

PLIST_SUB+=	S=${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}

.include <bsd.port.mk>
