# New ports collection makefile for:	tclX
# Date created:		6 February 1996
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	tclX
PORTVERSION=	8.4
CATEGORIES=	lang tcl${TCL_DVER} devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=tclx
DISTNAME=	tclx${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Extended TCL

USE_BZIP2=	yes
LIB_DEPENDS=	tcl${TCL_DVER}:${PORTSDIR}/lang/tcl${TCL_DVER}

TCL_VER?=	8.4
TCL_DVER?=	${TCL_VER:S/.//}

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include/tcl${TCL_VER}/unix\
		-I${LOCALBASE}/include/tcl${TCL_VER}/generic"
CONFIGURE_ARGS= --enable-shared \
		--with-help=Help \
		--with-tcl="${LOCALBASE}/lib/tcl${TCL_VER}"
PLIST_SUB=	TCLX_VER=${PORTVERSION}
ALL_TARGET=	binaries libraries test
INSTALL_TARGET=	install-binaries install-libraries
.ifndef(NOPORTDOCS)
ALL_TARGET+=	doc
INSTALL_TARGET+=install-help
.endif

MAN3=   CmdWrite.3 Handles.3 Keylist.3 ObjCmdWrite.3 TclXInit.3
MANN=	TclX.n

MLINKS=	CmdWrite.3	TclCommandWriting.3	\
	Keylist.3	TclX_NewKeyedListObj.3
.for l in Delete Get GetKeys Set TclX_Main TclX_NewKeyedListObj
MLINKS+=	Keylist.3	TclX_KeyedList$l.3
.endfor
.for l in Alloc Free TblInit TblRelease TblUseCount Walk Xlate
MLINKS+=	Handles.3	TclX_Handle$l.3
.endfor
.for l in Tclxcmd_Init TclX_Main Tkx_Init TkX_Main
MLINKS+=	TclXInit.3	$l.3
.endfor

post-configure:
	${REINPLACE_CMD} -e	\
	    's,^TCLSH_PROG.*,TCLSH_PROG=${LOCALBASE}/bin/tclsh${TCL_VER},' \
	    -e 's,TCL_LIBRARY=.*,\\,' ${WRKSRC}/Makefile
	# Disabling the failing help.test
	mv ${WRKSRC}/tests/help.test ${WRKSRC}/tests/help.test.dis

pre-su-install:
	cd ${WRKSRC}/doc && ${INSTALL_MAN} ${MAN3} ${PREFIX}/man/man3
	cd ${WRKSRC}/doc && ${INSTALL_MAN} ${MANN} ${PREFIX}/man/mann

.include <bsd.port.mk>
