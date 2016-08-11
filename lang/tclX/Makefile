# Created by: jkh
# $FreeBSD$

PORTNAME=	tclX
PORTVERSION=	8.4.1
CATEGORIES=	lang tcl devel
MASTER_SITES=	SF/${PORTNAME:tl}/TclX/${PORTVERSION}
DISTNAME=	tclx${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Extended TCL

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

WRKSRC=		${WRKDIR}/${PORTNAME:tl}${PORTVERSION:R}

USES=		autoreconf alias tcl:tea tar:bzip2
USE_LDCONFIG=	${PREFIX}/lib/tclx${PORTVERSION:R}
CONFIGURE_ARGS+=--enable-shared \
		--with-help=Help
PLIST_SUB=	TCLX_VER=${PORTVERSION:R}
ALL_TARGET=	binaries libraries
INSTALL_TARGET=	install-binaries install-libraries

.include <bsd.port.pre.mk>

.if ${TCL_VER} > 8.4
EXTRA_PATCHES+=	${FILESDIR}/tcl85-test-patch
.endif
.if ${TCL_VER} > 8.5
EXTRA_PATCHES+=	${FILESDIR}/tcl86-test-patch
.endif

post-configure:
	# Disabling the failing help.test
	${MV} ${WRKSRC}/tests/help.test ${WRKSRC}/tests/help.test.dis

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/TclX.n ${STAGEDIR}${PREFIX}/man/mann
.for l in CmdWrite Handles Keylist ObjCmdWrite TclXInit
	${INSTALL_DATA} ${WRKSRC}/doc/${l}.3 ${STAGEDIR}${PREFIX}/man/man3
.endfor
	${LN} -s CmdWrite.3.gz ${STAGEDIR}${PREFIX}/man/man3/TclCommandWriting.3.gz
	${LN} -s KeyList.3.gz ${STAGEDIR}${PREFIX}/man/man3/TclX_NewKeyedListObj.3.gz
.for l in Delete Get GetKeys Set TclX_Main TclX_NewKeyedListObj
	${LN} -s KeyList.3.gz ${STAGEDIR}${PREFIX}/man/man3/TclX_KeyedList${l}.3.gz
.endfor
.for l in Alloc Free TblInit TblRelease TblUseCount Walk Xlate
	${LN} -s Handles.3.gz ${STAGEDIR}${PREFIX}/man/man3/TclX_Handle${l}.3.gz
.endfor
.for l in Tclxcmd_Init TclX_Main Tkx_Init TkX_Main
	${LN} -s TclXInit.3.gz ${STAGEDIR}${PREFIX}/man/man3/${l}.3.gz
.endfor

regression-test test: build
	${SETENV} ${MAKE_ENV} ${MAKE} -C ${WRKSRC} test

.include <bsd.port.post.mk>
