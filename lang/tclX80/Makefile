# New ports collection makefile for:	tclX
# Version required:	7.5.2
# Date created:		6 February 1996
# Whom:			jkh
#
# $Id: Makefile,v 1.19 1997/10/09 08:19:14 tg Exp $
#

DISTNAME=	tclX7.5.2
PKGNAME=	tclX-7.5.2
CATEGORIES=	lang tk41
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/tclx-distrib/

LIB_DEPENDS=	tk41\\.1:${PORTSDIR}/x11/tk41

MAINTAINER=	ports@FreeBSD.ORG

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --enable-shared --with-tk
CONFIGURE_ENV=	PREFIX=${PREFIX}
MAN3=		CmdWrite.3 Handles.3 Keylist.3 TclCommandWriting.3 \
		TclXInit.3 Tcl_HandleAlloc.3 Tcl_HandleFree.3 \
		Tcl_HandleTblInit.3 Tcl_HandleTblRelease.3 \
		Tcl_HandleTblUseCount.3 Tcl_HandleWalk.3 \
		Tcl_HandleXlate.3 Tcl_GetKeyedListKeys.3 \
		Tcl_GetKeyedListField.3 Tcl_SetKeyedListField.3 \
		Tcl_DeleteKeyedListField.3 Tclx_Init.3 \
		Tclxcmd_Init.3 TclX_Main.3 Tkx_Init.3 TkX_Main.3
MANN=		Memory.n TclX.n ckalloc.n memory.n ckfree.n \
		Tcl_DisplayMemory.n Tcl_InitMemory.n Tcl_ValidateAllMemory.n

post-install:
	$(INSTALL_MAN) $(WRKSRC)/../doc/CmdWrite.3 $(PREFIX)/man/man3
	$(INSTALL_MAN) $(WRKSRC)/../doc/Handles.3 $(PREFIX)/man/man3
	$(INSTALL_MAN) $(WRKSRC)/../doc/Keylist.3 $(PREFIX)/man/man3
	$(INSTALL_MAN) $(WRKSRC)/../doc/TclXInit.3 $(PREFIX)/man/man3
	$(INSTALL_MAN) $(WRKSRC)/../doc/Memory.n $(PREFIX)/man/mann
	$(INSTALL_MAN) $(WRKSRC)/../doc/TclX.n $(PREFIX)/man/mann
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
