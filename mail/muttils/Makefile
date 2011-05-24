# New ports collection makefile for:	muttils
# Date created:		April 2 2011
# Whom:			Jason Helfman <jhelfman@experts-exchange.com>
#
# $FreeBSD$
#

PORTNAME=	muttils
PORTVERSION=	1.1
CATEGORIES=	mail python
MASTER_SITES=	https://bitbucket.org/blacktrash/${PORTNAME}/get/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTVERSION}

MAINTAINER=	jhelfman@experts-exchange.com
COMMENT=	Python utilities for console mail clients (eg. mutt)

CHANGESET=	977f2e350221
WRKSRC=		${WRKDIR}/blacktrash-${PORTNAME}-${CHANGESET}
USE_PYTHON_BUILD=	yes
USE_PYTHON_RUN=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_EGGINFO=	${PORTNAME}-unknown-${PYTHON_VERSION:S/thon//}.egg-info

post-install:
	${MKDIR} ${EXAMPLESDIR}
	( cd ${WRKSRC}/contrib && ${INSTALL_DATA} \example-* ${EXAMPLESDIR} )

.include <bsd.port.mk>
