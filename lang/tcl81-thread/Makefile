# New ports collection makefile for:	tcl8.1
# Date created:		19 August 1997
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	tcl-thread
PORTVERSION=	8.1.b1
CATEGORIES=	lang tcl81
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/tcl8_1/
DISTNAME=	tcl8.1b1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tcl81 with threads support

FILE_DEPENDS=	${PORTSDIR}/lang/tcl80

NO_LATEST_LINK=	yes
INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --enable-threads
CONFIGURE_ENV=	PORTSDIR=${PORTSDIR}
PKGINSTALL=	${PORTSDIR}/lang/tcl82/pkg/pkg-install.tclsh
PKGDEINSTALL=	${PORTSDIR}/lang/tcl82/pkg/pkg-deinstall.tclsh

MAN1=	tclsh.1

MAN3=	AddErrInfo.3 Alloc.3 AllowExc.3 AppInit.3 AssocData.3 Async.3 \
	BackgdErr.3 Backslash.3 BoolObj.3 ByteArrObj.3 CallDel.3 CmdCmplt.3 \
	Concat.3 CrtChannel.3 CrtChnlHdlr.3 CrtCloseHdlr.3 CrtCommand.3 \
	CrtFileHdlr.3 CrtInterp.3 CrtMathFnc.3 CrtObjCmd.3 CrtSlave.3 \
	CrtTimerHdlr.3 CrtTrace.3 DString.3 DetachPids.3 DoOneEvent.3 \
	DoWhenIdle.3 DoubleObj.3 Encoding.3 Eval.3 Exit.3 ExprLong.3 \
	ExprLongObj.3 FindExec.3 GetIndex.3 GetInt.3 GetOpnFl.3 GetStdChan.3 \
	Hash.3 IntObj.3 Interp.3 LinkVar.3 ListObj.3 Notifier.3 Object.3 \
	ObjectType.3 OpenFileChnl.3 OpenTcp.3 ParseCmd.3 PkgRequire.3 \
	Preserve.3 PrintDbl.3 RecEvalObj.3 RecordEval.3 RegExp.3 SaveResult.3 \
	SetErrno.3 SetRecLmt.3 SetResult.3 SetVar.3 Sleep.3 SplitList.3 \
	SplitPath.3 StaticPkg.3 StrMatch.3 StringObj.3 Tcl_Main.3 Thread.3 \
	ToUpper.3 TraceVar.3 Translate.3 UpVar.3 Utf.3 WrongNumArgs.3

MANN=	Tcl.n after.n append.n array.n bgerror.n binary.n break.n case.n \
	catch.n cd.n clock.n close.n concat.n continue.n encoding.n eof.n \
	error.n eval.n exec.n exit.n expr.n fblocked.n fconfigure.n fcopy.n \
	file.n fileevent.n filename.n flush.n for.n foreach.n format.n gets.n \
	glob.n global.n history.n http.n if.n incr.n info.n interp.n join.n \
	lappend.n library.n lindex.n linsert.n list.n llength.n load.n \
	lrange.n lreplace.n lsearch.n lsort.n msgcat.n namespace.n open.n \
	package.n pid.n pkgMkIndex.n proc.n puts.n pwd.n read.n regexp.n \
	registry.n regsub.n rename.n resource.n return.n safe.n scan.n seek.n \
	set.n socket.n source.n split.n string.n subst.n switch.n tclvars.n \
	tell.n time.n trace.n unknown.n unset.n update.n uplevel.n upvar.n \
	variable.n vwait.n while.n

MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Does not compile on sparc64"
.endif

post-install:
.if exists(${PKGINSTALL})
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL}
.endif

test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.post.mk>
