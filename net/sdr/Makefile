# New ports collection makefile for:	sdr
# Version required:			2.3a1
# Date created:				5 September 1996
# Whom:	      Bill Fenner <fenner@FreeBSD.ORG>
#
#   $Id: Makefile,v 1.4 1997/04/20 13:19:25 wosch Exp $
#

DISTNAME=	sdr.V2.3a1
PKGNAME=	sdr-2.3a1
CATEGORIES=	mbone tk80
MASTER_SITES=	ftp://cs.ucl.ac.uk/mice/sdr/

MAINTAINER=	fenner@FreeBSD.org

LIB_DEPENDS=	tk80\\.1:${PORTSDIR}/x11/tk80

RESTRICTED=	"Contains DES encryption"
NO_WRKSUBDIR=	yes
USE_GMAKE=	yes
USE_X11=	yes

.include <bsd.port.mk>
