# New ports collection makefile for:	tclX
# Date created:		6 February 1996
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	tclX
PORTVERSION=	8.3.5
PORTREVISION=	2
CATEGORIES=	lang tcl${TCL_DVER} tk${TCL_DVER}
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=tclx
DISTNAME=	tclx${PORTVERSION}
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Extended TCL

.ifdef WITHOUT_X11
LIB_DEPENDS=	tcl${TCL_DVER}:${PORTSDIR}/lang/tcl${TCL_DVER}
PKGNAMESUFFIX=	-nox11
.else
LIB_DEPENDS=	tk${TCL_DVER}:${PORTSDIR}/x11-toolkits/tk${TCL_DVER}
.endif

TCL_VER?=	8.4
TCL_DVER?=	${TCL_VER:S/.//}

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --enable-shared \
		--with-help=Help \
		--with-tcl="${LOCALBASE}/lib/tcl${TCL_VER}" \
		--with-tk="${LOCALBASE}/lib/tk${TCL_VER}"
PLIST_SUB=	TCLX_LONG_VER=${PORTVERSION:R} \
		TCLX_SHORT_VER=${PORTVERSION:R:S/.//}
INSTALL_TARGET=	install-binaries install-libraries

.ifdef WITHOUT_X11
CONFIGURE_ARGS+=--enable-tk=NO
PLIST_SUB+=	X11='@comment '
.else
CONFIGURE_ARGS+=--with-tk="${LOCALBASE}/lib/tk${TCL_VER}"
PLIST_SUB+=	X11=''
.endif

MAKE_ENV=	LDFLAGS="-lm"

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

post-patch:
	# This man-page is now part of Tcl distribution:
	${RM} ${WRKSRC:H}/doc/Memory.n

pre-install:
	cd ${WRKSRC:H}/doc && ${INSTALL_MAN} ${MAN3} ${PREFIX}/man/man3
	cd ${WRKSRC:H}/doc && ${INSTALL_MAN} ${MANN} ${PREFIX}/man/mann

post-install:
	######
	# If you have spare time, try running ``make test'' and
	# debug any tests, that fail. Thank you.
	######

test:
	cd ${WRKSRC:H}/tcl/tests && ${SETENV} LANG=C ${WRKSRC}/runtcl all
.ifndef WITHOUT_X11
	cd ${WRKSRC:H}/tk/tests && ${WRKSRC}/runtcl signal.test
.endif

.include <bsd.port.mk>
