# New ports collection makefile for:	tclX
# Version required:	7.5.2
# Date created:		6 February 1996
# Whom:			jkh
#
# $Id: Makefile,v 1.9 1996/11/12 02:19:20 obrien Exp $
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
MAN3=		CmdWrite.3 Handles.3 Keylist.3 TclXInit.3
MANN=		Memory.n TclX.n

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
