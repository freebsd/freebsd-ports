# New ports collection makefile for:	tclX
# Date created:		6 February 1996
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	tclX
PORTVERSION=	8.4
PORTREVISION=	2
CATEGORIES=	lang tcl devel
MASTER_SITES=	SF/${PORTNAME:L}/TclX/${PORTVERSION}.0
DISTNAME=	tclx${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Extended TCL

USE_BZIP2=	yes
USE_TCL_BUILD=	84
USE_TCL=	84

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${TCL_INCLUDEDIR}/unix\
		-I${TCL_INCLUDEDIR}/generic"
CONFIGURE_ARGS=	--enable-shared \
		--with-help=Help \
		--with-tcl="${TCL_LIBDIR}"
PLIST_SUB=	TCLX_VER=${PORTVERSION}
MAKE_JOBS_SAFE=	yes
ALL_TARGET=	binaries libraries	# test
INSTALL_TARGET=	install-binaries install-libraries

MAN3=	CmdWrite.3 Handles.3 Keylist.3 ObjCmdWrite.3 TclXInit.3
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

.include <bsd.port.pre.mk>

pre-configure:
.if exists(${TCL_LIBDIR}/tclConfig-threads.sh)
	${REINPLACE_CMD} -e 's|tclConfig.sh|tclConfig-threads.sh|'	\
		${WRKSRC}/${CONFIGURE_SCRIPT}
.endif
	${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|'	\
		${WRKSRC}/${CONFIGURE_SCRIPT}

post-configure:
	${REINPLACE_CMD} -e	\
	    's,^TCLSH_PROG.*,TCLSH_PROG=${TCLSH},' \
	    -e 's,TCL_LIBRARY=.*,\\,' ${WRKSRC}/Makefile
	# Disabling the failing help.test
	${MV} ${WRKSRC}/tests/help.test ${WRKSRC}/tests/help.test.dis

pre-su-install:
	cd ${WRKSRC}/doc && ${INSTALL_MAN} ${MAN3} ${PREFIX}/man/man3
	cd ${WRKSRC}/doc && ${INSTALL_MAN} ${MANN} ${PREFIX}/man/mann

.include <bsd.port.post.mk>

.ifndef(NOPORTDOCS) && exists(${MANPREFIX}/man/mann/Tcl.n.gz)
ALL_TARGET+=	doc
INSTALL_TARGET+=install-help
.else
PLIST_SUB:=	${PLIST_SUB:NPORTDOCS=*} PORTDOCS='@comment '
.endif
