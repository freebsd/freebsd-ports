# New ports collection makefile for:	tclX
# Version required:	7.5.2
# Date created:		6 February 1996
# Whom:			jkh
#
# $Id: Makefile,v 1.10 1996/11/17 06:12:51 obrien Exp $
#

DISTNAME=	tclX7.5.2
PKGNAME=	tclX-7.5.2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/tclx-distrib/

MAINTAINER=	jkh@FreeBSD.org

DEPENDS=	${TK_DIR}
LIB_DEPENDS=	tk41\\.1:${TK_DIR}

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --with-tk
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

TCL_BASE=	/usr/libdata/tcl
TCL_SRC=	/usr/src/contrib/tcl

TK_DIR=		${PORTSDIR}/x11/tk41
TK_SRC=		${TK_DIR}/work/tk4.1

pre-configure:
	cd ${WRKSRC} ; \
	mv Config.mk Config.mk.orig2 && \
	sed -e 's;TCL_SRC=$${srcbasedir}/../tcl7.5;TCL_SRC=${TCL_SRC};' \
	    -e 's;TCL_BUILD=$${bldbasedir}/../tcl7.5;TCL_BUILD=${TCL_SRC};' \
	    -e 's;TCL_CONFIG=$${TCL_BUILD}/unix/tclConfig.sh;TCL_CONFIG=${TCL_BASE}/tclConfig.sh;' \
	    -e 's;TCL_LIB=$${TCL_BUILD_LIB_SPEC};TCL_LIB=$${TCL_LIB_SPEC};' \
	    -e 's;TCL_SHLIB_DIR=$${bldbasedir};TCL_SHLIB_DIR=${TCL_SRC};' \
	    -e 's;TK_SRC=$${srcbasedir};TK_SRC=${TK_SRC};' \
	    -e 's;TK_BUILD=$${bldbasedir};TK_BUILD=${TK_SRC};' \
	    -e 's;TK_LIB=$${bldbasedir};TK_LIB=${TK_SRC};' \
	    -e 's;TK_SHLIB_DIR=$${bldbasedir};TK_SHLIB_DIR=${TK_SRC};' \
	Config.mk.orig2 >Config.mk

post-install:
	$(INSTALL_MAN) $(WRKSRC)/../doc/CmdWrite.3 $(PREFIX)/man/man3
	$(INSTALL_MAN) $(WRKSRC)/../doc/Handles.3 $(PREFIX)/man/man3
	$(INSTALL_MAN) $(WRKSRC)/../doc/Keylist.3 $(PREFIX)/man/man3
	$(INSTALL_MAN) $(WRKSRC)/../doc/TclXInit.3 $(PREFIX)/man/man3
	$(INSTALL_MAN) $(WRKSRC)/../doc/Memory.n $(PREFIX)/man/mann
	$(INSTALL_MAN) $(WRKSRC)/../doc/TclX.n $(PREFIX)/man/mann
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
