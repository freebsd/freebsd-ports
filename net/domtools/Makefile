# New ports collection makefile for:	domtools
# Version required:			1.4.0
# Date created:				12 Jun 1999
# Whom:					alexp
#
# $Id: Makefile,v 1.1.1.1 1999/06/12 04:45:52 jmg Exp $
#

DISTNAME=       domtools1.4.0
PKGNAME= 	domtools-1.4.0
CATEGORIES=     net
MASTER_SITES=   http://www.domtools.com/pub/

MAINTAINER=     veers@disturbed.net

WRKSRC=		${WRKDIR}/domtools1.4.0/

USE_PERL5= 	YES

NO_BUILD=	YES

post-install:
	${MKDIR} ${PREFIX}/domtools/lib/zonecache

.include <bsd.port.mk>
