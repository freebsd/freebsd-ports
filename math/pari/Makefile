# New ports collection makefile for:	PARI 
# Version required:	1.39.03
# Date created:		6 June 1997
# Whom:			Yoshiaki UCHIKAWA <yoshiaki@kt.rim.or.jp>
#
# $Id: Makefile,v 1.4 1998/11/28 05:38:59 asami Exp $
#

DISTNAME=	pari-1.39.03
CATEGORIES=	math
MASTER_SITES=	ftp://megrez.math.u-bordeaux.fr/pub/pari/unix/OLDVERSIONS/

MAINTAINER=     yoshiaki@kt.rim.or.jp

USE_XLIB=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAN1=		gp.1

do-configure:
	@(cd ${WRKSRC} ; ./Makemakefile i386)

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
