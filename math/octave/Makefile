# New ports collection makefile for:	octave
# Version required:	1.1.1
# Date created:		26 Apr 1995
# Whom:			thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id: Makefile,v 1.2 1995/10/04 10:18:49 asami Exp $
#

DISTNAME=	octave-1.1.1
CATEGORIES+=	math 
MASTER_SITES=	ftp://ftp.che.utexas.edu/pub/octave/

MAINTAINER=	ports@FreeBSD.ORG

RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot

HAS_CONFIGURE=	yes
USE_GMAKE=	yes

PATCH_STRIP=	-p1
MAKE_FLAGS=	CFLAGS="-O2 -pipe -m486" CXXFLAGS="-O2 -pipe -m486" LDFLAGS="-s" -f

.include <bsd.port.mk>
