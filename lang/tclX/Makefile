# New ports collection makefile for:	tclX
# Date created:		6 February 1996
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	tclX
PORTVERSION=	8.3.5
PORTREVISION=	1
CATEGORIES=	lang tcl${TCL_DVER} tk${TCL_DVER}
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=tclx
DISTNAME=	tclx${PORTVERSION}
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Extended TCL

.ifdef WITHOUT_X11
LIB_DEPENDS=	tcl${TCL_DVER}.1:${PORTSDIR}/lang/tcl${TCL_DVER}
PKGNAMESUFFIX=	-nox11
.else
LIB_DEPENDS=	tk${TCL_DVER}.1:${PORTSDIR}/x11-toolkits/tk${TCL_DVER}
.endif

BROKEN=		Incorrect pkg-plist

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

.ifdef WITHOUT_X11
CONFIGURE_ARGS+=--enable-tk=NO
PLIST_SUB+=	X11='@comment '
.else
CONFIGURE_ARGS+=--with-tk="${LOCALBASE}/lib/tk${TCL_VER}"
PLIST_SUB+=	X11=''
.endif

MAKE_ENV=	LDFLAGS="-lm"

MAN3=   CmdWrite.3 Handles.3 Keylist.3 ObjCmdWrite.3 TclXInit.3 \
	TclCommandWriting.3 \
	TclX_KeyedListDelete.3 TclX_KeyedListGet.3 TclX_KeyedListGetKeys.3 \
	TclX_KeyedListSet.3 TclX_Main.3 TclX_NewKeyedListObj.3 \
	Tcl_HandleAlloc.3 Tcl_HandleFree.3 Tcl_HandleTblInit.3 \
	Tcl_HandleTblRelease.3 Tcl_HandleTblUseCount.3 Tcl_HandleWalk.3 \
	Tcl_HandleXlate.3  Tclx_Init.3  Tclxcmd_Init.3 TkX_Main.3 Tkx_Init.3

MANN=	Memory.n TclX.n Tcl_DisplayMemory.n Tcl_InitMemory.n \
	Tcl_ValidateAllMemory.n ckalloc.n ckfree.n

.include <bsd.port.pre.mk>

post-install:
	# Preventing the help files from being rebuilt over and over:
	${INSTALL_MAN} ${WRKSRC}/../doc/CmdWrite.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/../doc/Handles.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/../doc/Keylist.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/../doc/ObjCmdWrite.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/../doc/TclXInit.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/../doc/Memory.n ${PREFIX}/man/mann
	${INSTALL_MAN} ${WRKSRC}/../doc/TclX.n ${PREFIX}/man/mann

.include <bsd.port.post.mk>
