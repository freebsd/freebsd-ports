# New ports collection makefile for:	sentry
# Version required:	0.61
# Date created:		3 January 1998
# Whom:			chris@still.whet.org
#
# $Id: Makefile,v 1.1.1.1 1998/12/19 16:53:20 jseger Exp $
#

DISTNAME=	sentry-0.61
CATEGORIES=	security
MASTER_SITES=	http://www.psionic.com/tools/sentry/

MAINTAINER=	chris@still.whet.org

WRKSRC=		${WRKDIR}/sentry_beta
ALL_TARGET=	bsd

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/sentry
	${INSTALL_DATA} ${WRKSRC}/README.install ${WRKSRC}/README.methods \
	  ${PREFIX}/share/doc/sentry
.endif

.include <bsd.port.mk>
