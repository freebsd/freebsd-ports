# New ports collection makefile for:	tclX
# Version required:	7.5
# Date created:		6 February 1996
# Whom:			jkh
#
# $Id: Makefile,v 1.4 1996/05/13 09:43:23 asami Exp $
#

DISTNAME=	tclX7.5.0
PKGNAME=	tclX-7.5
CATEGORIES+=	lang
MASTER_SITES=	ftp://mirror.neosoft.com/pub/tcl/tclx-distrib/

TCL_DIR=	${PORTSDIR}/lang/tcl75
TCL_SRC=	${TCL_DIR}/work/tcl7.5

TK_DIR=		${PORTSDIR}/x11/tk41
TK_SRC=		${TK_DIR}/work/tk4.1

DEPENDS=	${TCL_DIR} ${TK_DIR}
LIB_DEPENDS=	tcl7\\.5\\.1:${TCL_DIR} \
		tk4\\.1\\.1:${TK_DIR}

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --with-tk

pre-configure:
	cd ${WRKSRC} ; \
	mv Config.mk Config.mk.orig2 && \
	sed -e 's;TCL_SRC=$${srcbasedir};TCL_SRC=${TCL_SRC};' \
	    -e 's;TCL_CONFIG=$${srcbasedir};TCL_CONFIG=${TCL_SRC};' \
	    -e 's;TCL_LIB=$${bldbasedir};TCL_LIB=${TCL_SRC};' \
	    -e 's;TCL_SHLIB_DIR=$${bldbasedir};TCL_SHLIB_DIR=${TCL_SRC};' \
	    -e 's;TK_SRC=$${srcbasedir};TK_SRC=${TK_SRC};' \
	    -e 's;TK_CONFIG=$${srcbasedir};TK_CONFIG=${TK_SRC};' \
	    -e 's;TK_LIB=$${bldbasedir};TK_LIB=${TK_SRC};' \
	    -e 's;TK_SHLIB_DIR=$${bldbasedir};TK_SHLIB_DIR=${TK_SRC};' \
	Config.mk.orig2 >Config.mk

post-install:
	install -c -m 444 $(WRKSRC)/../doc/CmdWrite.3 $(PREFIX)/man/man3
	install -c -m 444 $(WRKSRC)/../doc/Handles.3 $(PREFIX)/man/man3
	install -c -m 444 $(WRKSRC)/../doc/Keylist.3 $(PREFIX)/man/man3
	install -c -m 444 $(WRKSRC)/../doc/TclXInit.3 $(PREFIX)/man/man3
	install -c -m 444 $(WRKSRC)/../doc/Memory.n $(PREFIX)/man/mann
	install -c -m 444 $(WRKSRC)/../doc/TclX.n $(PREFIX)/man/mann
.if !defined(NOMANCOMPRESS)
	gzip -9nf $(PREFIX)/man/man3/CmdWrite.3
	gzip -9nf $(PREFIX)/man/man3/Handles.3
	gzip -9nf $(PREFIX)/man/man3/Keylist.3
	gzip -9nf $(PREFIX)/man/man3/TclXInit.3
	gzip -9nf $(PREFIX)/man/mann/Memory.n
	gzip -9nf $(PREFIX)/man/mann/TclX.n
.endif
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
