# New ports collection makefile for:	tclX
# Version required:	8.0.2
# Date created:		6 February 1996
# Whom:			jkh
#
# $Id: Makefile,v 1.20 1997/12/24 01:21:39 alex Exp $
#

DISTNAME=	tclX8.0.2
PKGNAME=	tclX-8.0.2
CATEGORIES=	lang tcl80 tk80
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/tclx-distrib/

MAINTAINER=	jseger@FreeBSD.ORG

LIB_DEPENDS=	tk80\\.1:${PORTSDIR}/x11/tk80

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --enable-shared --with-tk
MAN3=   CmdWrite.3 Handles.3 Keylist.3 TclXInit.3
MANN=   Memory.n TclX.n

post-install:
	$(INSTALL_MAN) $(WRKSRC)/../doc/CmdWrite.3 $(PREFIX)/man/man3
	$(INSTALL_MAN) $(WRKSRC)/../doc/Handles.3 $(PREFIX)/man/man3
	$(INSTALL_MAN) $(WRKSRC)/../doc/Keylist.3 $(PREFIX)/man/man3
	$(INSTALL_MAN) $(WRKSRC)/../doc/TclXInit.3 $(PREFIX)/man/man3
	$(INSTALL_MAN) $(WRKSRC)/../doc/Memory.n $(PREFIX)/man/mann
	$(INSTALL_MAN) $(WRKSRC)/../doc/TclX.n $(PREFIX)/man/mann
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
