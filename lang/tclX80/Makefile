# New ports collection makefile for:	tclX
# Version required:	8.0.2
# Date created:		6 February 1996
# Whom:			jkh
#
# $Id: Makefile,v 1.26 1998/12/01 03:06:30 asami Exp $
#

DISTNAME=	tclX8.0.2
PKGNAME=	tclX-8.0.2
CATEGORIES=	lang tcl80 tk80
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/tclx-distrib/

MAINTAINER=	jseger@FreeBSD.ORG

LIB_DEPENDS=	tk80.1:${PORTSDIR}/x11-toolkits/tk80

FILE_DEPENDS=	${PORTSDIR}/x11-toolkits/tk80

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --enable-shared --with-tk
PKGINSTALL=     ${PORTSDIR}/x11-toolkits/tk80/pkg/INSTALL.wish
MAN3=   CmdWrite.3 Handles.3 Keylist.3 TclCommandWriting.3 TclXInit.3 \
	TclX_KeyedListDelete.3 TclX_KeyedListGet.3 TclX_KeyedListGetKeys.3 \
	TclX_KeyedListSet.3 TclX_Main.3 TclX_NewKeyedListObj.3 \
	Tcl_HandleAlloc.3 Tcl_HandleFree.3 Tcl_HandleTblInit.3 \
	Tcl_HandleTblRelease.3 Tcl_HandleTblUseCount.3 Tcl_HandleWalk.3 \
	Tcl_HandleXlate.3  Tclx_Init.3  Tclxcmd_Init.3 TkX_Main.3 Tkx_Init.3

MANN=   Memory.n TclX.n Tcl_DisplayMemory.n Tcl_InitMemory.n \
	Tcl_ValidateAllMemory.n ckalloc.n ckfree.n memory.n

.include <bsd.port.pre.mk>
post-install:
	$(INSTALL_MAN) $(WRKSRC)/../doc/CmdWrite.3 $(PREFIX)/man/man3
	$(INSTALL_MAN) $(WRKSRC)/../doc/Handles.3 $(PREFIX)/man/man3
	$(INSTALL_MAN) $(WRKSRC)/../doc/Keylist.3 $(PREFIX)/man/man3
	$(INSTALL_MAN) $(WRKSRC)/../doc/TclXInit.3 $(PREFIX)/man/man3
	$(INSTALL_MAN) $(WRKSRC)/../doc/Memory.n $(PREFIX)/man/mann
	$(INSTALL_MAN) $(WRKSRC)/../doc/TclX.n $(PREFIX)/man/mann
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
.if exists(${PKGINSTALL})
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL}
.endif

.include <bsd.port.post.mk>
