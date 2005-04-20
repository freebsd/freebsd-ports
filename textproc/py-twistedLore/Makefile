# New ports collection makefile for:	py-twistedLore
# Date created:		14 April 2005
# Whom:	      		Neal Nelson <neal@nelson.name>
#
# $FreeBSD$
#

PORTNAME=	twistedLore
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	http://twistedmatrix.com/downloads/Lore/0.1/ \
    http://tmrc.mit.edu/mirror/twisted/Lore/0.1/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedLore-${PORTVERSION}

MAINTAINER=	neal@nelson.name
COMMENT=	Documentation generator with HTML and LaTeX support

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/TwistedLore-${PORTVERSION}

USE_BZIP2=	yes
USE_PYTHON=	2.2+
USE_PYDISTUTILS=	yes

PLIST_SUB+=	S=${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}

.include <bsd.port.mk>
