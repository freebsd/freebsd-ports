# New ports collection makefile for:	scotty
# Version required:	1.2.0
# Date created:		18 Februar 1995
# Whom:			Gennady Sorokopud <gena@netvision.net.il>
#
# $Id: Makefile,v 1.5 1995/04/18 05:42:21 asami Exp $
#

DISTNAME=	scotty-1.2.0
CATEGORIES+=	networking
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
CONFIGURE_ARGS= --with-x --prefix=${PREFIX} --with-tcl-include=${PORTSDIR}/lang/tcl/work/tcl7.3 --with-tcl-library=${PORTSDIR}/lang/tcl/work/tcl7.3 --with-tk-include=${PORTSDIR}/x11/tk/work/tk3.6 --with-tk-library=${PORTSDIR}/x11/tk/work/tk3.6 --with-blt-library=${PORTSDIR}/lang/tclX/work/tclX7.3b/tclmaster/lib

pre-configure:
	@find ${WRKSRC} -name Makefile.in -exec ${SCRIPTDIR}/untrue \{} \;

pre-install:
	@cd ${WRKSRC};make sinstall

.include <bsd.port.mk>
