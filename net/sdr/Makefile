# New ports collection makefile for:	sdr
# Version required:			2.3a1
# Date created:				5 September 1996
# Whom:	      Bill Fenner <fenner@FreeBSD.ORG>
#
#   $Id: Makefile,v 1.2 1996/11/18 11:33:19 asami Exp $
#

DISTNAME=	sdr.V2.3a1
PKGNAME=	sdr-2.3a1
CATEGORIES=	mbone
MASTER_SITES=	ftp://cs.ucl.ac.uk/mice/sdr/

MAINTAINER=	fenner@FreeBSD.org

LIB_DEPENDS=	tk41\\.1:${PORTSDIR}/x11/tk41

RESTRICTED=	"Contains DES encryption"
NO_WRKSUBDIR=	yes
USE_GMAKE=	yes
USE_X11=	yes

.include <bsd.port.mk>
