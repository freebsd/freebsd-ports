# New ports collection makefile for:   dejasearch
# Version required:    1.1
# Date created:        15 March 1999
# Whom:                Kris Kennaway <kris@FreeBSD.ORG>
#
# $Id$
#

DISTNAME=	dejasearch11
PKGNAME=	dejasearch-1.1
CATEGORIES=	news
MASTER_SITES=	http://homemade.hypermart.net/dejasearch/ \
		http://homemade.virtualave.net/dejasearch/

MAINTAINER=	kris@FreeBSD.ORG

WRKSRC=		${WRKDIR}/dejasearch/

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dejasearch ${PREFIX}/bin/

.ifndef NOPORTDOCS
	${MKDIR} ${PREFIX}/share/doc/dejasearch/
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dejasearch/
.endif

.include <bsd.port.mk>
