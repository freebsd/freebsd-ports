# New ports collection makefile for:	muttils
# Date created:		April 2 2011
# Whom:			Jason Helfman <jhelfman@experts-exchange.com>
#
# $FreeBSD$
#

PORTNAME=	muttils
PORTVERSION=	1.2
CATEGORIES=	mail python
MASTER_SITES=	https://bitbucket.org/blacktrash/${PORTNAME}/get/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTVERSION}

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Python utilities for console mail clients (eg. mutt)

CONFLICTS=	zh-wenju-[0-9]* talkfilters-[0-9]* reed-[0-9]*

CHANGESET=	42b380758b70
WRKSRC=		${WRKDIR}/blacktrash-${PORTNAME}-${CHANGESET}
USE_PYTHON_BUILD=	yes
USE_PYTHON_RUN=		yes
USE_PYDISTUTILS=	yes

PORTEXAMPLES=	*

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	( cd ${WRKSRC}/contrib && ${INSTALL_DATA} \example-* ${EXAMPLESDIR} )
.endif

.include <bsd.port.mk>
