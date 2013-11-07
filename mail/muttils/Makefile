# Created by: Jason Helfman <jhelfman@experts-exchange.com>
# $FreeBSD$

PORTNAME=	muttils
PORTVERSION=	1.3
CATEGORIES=	mail python
MASTER_SITES=	https://bitbucket.org/blacktrash/${PORTNAME}/get/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTVERSION}

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Python utilities for console mail clients (eg. mutt)

CONFLICTS=	zh-wenju-[0-9]* talkfilters-[0-9]* reed-[0-9]*

CHANGESET=	8bb26094df06
WRKSRC=		${WRKDIR}/blacktrash-${PORTNAME}-${CHANGESET}
USE_PYTHON_BUILD=	yes
USE_PYTHON_RUN=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

PORTEXAMPLES=	*

.include <bsd.port.options.mk>

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	( cd ${WRKSRC}/contrib && ${INSTALL_DATA} \example-* ${STAGEDIR}${EXAMPLESDIR} )

.include <bsd.port.mk>
