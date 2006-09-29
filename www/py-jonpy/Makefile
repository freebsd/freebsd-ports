# New ports collection makefile for:	jonpy
# Date created:				12 Sep 2005
# Whom:					Søren Straarup <xride@x12.dk>
#
# $FreeBSD$
#

PORTNAME=	jonpy
PORTVERSION=	0.06
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jonpy
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Python FastCGI interface library

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
NO_BUILD=		yes

PORTDOCS=	*

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/example && ${FIND} . | \
		${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR})

.include <bsd.port.mk>
