# New ports collection makefile for: analog
# Version required:	1.9.6
# Date created:		9 June 1996
# Whom:			jraynard
#
# $Id$
#

DISTNAME=	analog.1.9.6
PKGNAME=	analog-1.9.6
CATEGORIES+=	www
MASTER_SITES=	http://www.statslab.cam.ac.uk/~sret1/analog/

MAINTAINER=	jraynard@freebsd.org

WRKSRC=		${WRKDIR}/analog

do-install:
	@mkdir -p ${PREFIX}/share/analog
	@(cd ${WRKSRC}; cp -r Readme.html domains.tab primes.tab analogo.gif images ${PREFIX}/share/analog; cp analog ${PREFIX}/bin)
	@(cd ${PREFIX}/share/analog; chmod +r *)

.include <bsd.port.mk>
