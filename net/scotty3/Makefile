# New ports collection makefile for:	scotty
# Version required:	1.2.0
# Date created:		18 Februar 1995
# Whom:			Gennady Sorokopud <gena@netvision.net.il>
#
# $Id: Makefile,v 1.7 1995/09/15 10:41:29 asami Exp $
#

DISTNAME=	scotty-1.2.0
CATEGORIES+=	net
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/tkined/

PATCHFILES=	scotty-1.2.0-1.2.1.diff.gz scotty-1.2.1-1.2.2.diff.gz
PATCH_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/tkined/
PATCH_DIST_STRIP=	-p1

LIB_DEPENDS=	tk\\.3\\.:${PORTSDIR}/x11/tk \
		tcl\\.7\\.:${PORTSDIR}/lang/tcl
EXEC_DEPENDS=	wishx:${PORTSDIR}/lang/tclX

HAS_CONFIGURE=  yes
GNU_CONFIGURE=  yes
USE_GMAKE=	yes
CONFIGURE_ARGS= --with-x --prefix=${PREFIX}

pre-configure:
	@find ${WRKSRC} -name Makefile.in -exec ${SCRIPTDIR}/untrue \{} \;

pre-install:
	@cd ${WRKSRC};make sinstall

.include <bsd.port.mk>
