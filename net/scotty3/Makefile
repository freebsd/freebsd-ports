# New ports collection makefile for:	scotty
# Version required:	1.2.0
# Date created:		18 Februar 1995
# Whom:			Gennady Sorokopud <gena@netvision.net.il>
#
# $Id: Makefile,v 1.4 1995/04/15 05:41:51 asami Exp $
#

DISTNAME=	scotty-1.2.0
CATEGORIES+=	networking
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/tkined/
DISTFILES=	scotty-1.2.0.tar.gz scotty-1.2.0-1.2.1.diff.gz \
		scotty-1.2.1-1.2.2.diff.gz
EXTRACT_ONLY=	scotty-1.2.0.tar.gz

LIB_DEPENDS=	tk\\.3\\.:${PORTSDIR}/x11/tk \
		tcl\\.7\\.:${PORTSDIR}/lang/tcl
EXEC_DEPENDS=	wishx:${PORTSDIR}/lang/tclX

HAS_CONFIGURE=  yes
GNU_CONFIGURE=  yes
USE_GMAKE=	yes
CONFIGURE_ARGS= --with-x --prefix=${PREFIX} --with-tcl-include=${PORTSDIR}/lang/tcl/work/tcl7.3 --with-tcl-library=${PORTSDIR}/lang/tcl/work/tcl7.3 --with-tk-include=${PORTSDIR}/x11/tk/work/tk3.6 --with-tk-library=${PORTSDIR}/x11/tk/work/tk3.6 --with-blt-library=${PORTSDIR}/lang/tclX/work/tclX7.3b/tclmaster/lib

pre-patch:
	@echo "===>  Pre-patching for ${DISTNAME}"
	@if [ ! -f ${CONFIGURE_COOKIE} ]; then \
		ln -s ${WRKSRC} ${WRKDIR}/scotty-1.2.1; \
		ln -s ${WRKSRC} ${WRKDIR}/scotty-1.2.2; \
		zcat ${DISTDIR}/scotty-1.2.0-1.2.1.diff.gz | \
			patch --quiet -E -p0 -d ${WRKDIR}; \
		zcat ${DISTDIR}/scotty-1.2.1-1.2.2.diff.gz | \
			patch --quiet -E -p0 -d ${WRKDIR}; \
		rm -f ${WRKDIR}/scotty-1.2.1; \
		rm -f ${WRKDIR}/scotty-1.2.2; \
	fi

pre-install:
	@echo "===>  Pre-installing for ${DISTNAME}"
	@cd ${WRKSRC};make sinstall

.include <bsd.port.mk>
