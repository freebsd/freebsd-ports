# New ports collection makefile for: analog
# Version required:	1.92b1
# Date created:		October 21st 1996
# Whom:			jfitz
#
# $Id: Makefile,v 1.4 1996/10/22 00:48:59 jfitz Exp $
#

DISTNAME=	analog.1.92.1
PKGNAME=	analog-1.92.1
CATEGORIES=	www
MASTER_SITES=	http://www.statslab.cam.ac.uk/~sret1/ \
		http://www.lightside.net/analog/ \
		http://www.gamesdomain.com/analog/ \
		http://www.monash.edu.au/mirror/analog/ \
		http://www.gamesdomain.co.uk/analog/ \
		ftp://download.netvision.net.il/pub/mirrors/analog/ \
		ftp://mabuse.phil.uni-passau.de/pub/mirrors/analog/

MAINTAINER=	jfitz@freebsd.org

WRKSRC=		${WRKDIR}/analog

do-install:
	@mkdir -p ${PREFIX}/share/analog
	@(cd ${WRKSRC}; cp -r Readme.html domains.tab primes.tab images ${PREFIX}/share/analog; cp analog ${PREFIX}/bin)
	@(cd ${PREFIX}/share/analog; chmod +r *)
	@strip ${PREFIX}/bin/analog

.include <bsd.port.mk>
