# New ports collection makefile for:	scotty
# Version required:	2.0.2
# Date created:		18 Februar 1995
# Whom:			Gennady Sorokopud <gena@netvision.net.il>
#
# $Id: Makefile,v 1.8 1995/11/27 04:05:32 asami Exp $
#

DISTNAME=	scotty-2.0.2
CATEGORIES+=	net
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/tkined/

LIB_DEPENDS=	tk40\\.1\\.:${PORTSDIR}/x11/tk \
		tcl74\\.1\\.:${PORTSDIR}/lang/tcl
EXEC_DEPENDS=	wishx:${PORTSDIR}/lang/tclX

HAS_CONFIGURE=  yes
GNU_CONFIGURE=  yes
CONFIGURE_ARGS= --with-x --prefix=${PREFIX}

pre-configure:
	@find ${WRKSRC} -name Makefile.in -exec ${SCRIPTDIR}/untrue \{} \;

pre-install:
	@cd ${WRKSRC};make sinstall

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/scotty.1
	gzip -9nf ${PREFIX}/man/man1/scwish.1
	gzip -9nf ${PREFIX}/man/man8/ntping.8
	gzip -9nf ${PREFIX}/man/man8/straps.8
	gzip -9nf ${PREFIX}/man/mann/msqltcl.n
	gzip -9nf ${PREFIX}/man/mann/cmiptcl.n
	gzip -9nf ${PREFIX}/man/mann/gdmotcl.n
.endif


.include <bsd.port.mk>
