# New ports collection makefile for:	sdr
# Version required:			2.3a1
# Date created:				5 September 1996
# Whom:	      Bill Fenner <fenner@FreeBSD.ORG>
#
#   $Id$
#

DISTNAME=	sdr.V2.3a1
PKGNAME=	sdr-2.3a1
CATEGORIES+=	mbone
MASTER_SITES=	ftp://cs.ucl.ac.uk/mice/sdr/
RESTRICTED=	"Contains DES encryption"

MAINTAINER=	fenner@FreeBSD.org

LIB_DEPENDS=	tk41\\.1:${PORTSDIR}/x11/tk41

NO_WRKSUBDIR=	yes
USE_GMAKE=	yes
USE_X11=	yes

.include <bsd.port.mk>
