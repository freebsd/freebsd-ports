# New ports collection makefile for:	tcl8.0
# Version required:	8.0
# Date created:		19 August 1997
# Whom:			jkh
#
# $Id: Makefile,v 1.17 1999/05/04 19:33:40 fenner Exp $
#

DISTNAME=	tcl8.0.5
PKGNAME=	tcl-8.0.5
CATEGORIES=	lang tcl80
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/tcl8_0/

MAINTAINER=	cwt@freebsd.org

Y2K=            http://www.scriptics.com/Y2K.html

WRKSRC=		${WRKDIR}/tcl8.0.5/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=  PORTSDIR=${PORTSDIR}
PKGINSTALL=	${PKGDIR}/INSTALL.tclsh

SHLIB_MAJOR=	1
SHLIB_MINOR=	5
MAKEFILE=	makefile
TCL_LIB=	libtcl80.so

MAN1=	tclsh.1

MAN3=	AddErrInfo.3 Alloc.3 AllowExc.3 AppInit.3 AssocData.3 Async.3 \
	BackgdErr.3 Backslash.3 BoolObj.3 CallDel.3 CmdCmplt.3 Concat.3 \
	CrtChannel.3 CrtChnlHdlr.3 CrtCloseHdlr.3 CrtCommand.3 CrtFileHdlr.3 \
	CrtInterp.3 CrtMathFnc.3 CrtObjCmd.3 CrtSlave.3 CrtTimerHdlr.3 \
	CrtTrace.3 DString.3 DetachPids.3 DoOneEvent.3 DoWhenIdle.3 \
	DoubleObj.3 Eval.3 EvalObj.3 Exit.3 ExprLong.3 ExprLongObj.3 \
	FindExec.3 GetIndex.3 GetInt.3 GetOpnFl.3 GetStdChan.3 Hash.3 IntObj.3 \
	Interp.3 LinkVar.3 ListObj.3 Notifier.3 ObjSetVar.3 Object.3 \
	ObjectType.3 OpenFileChnl.3 OpenTcp.3 PkgRequire.3 Preserve.3 \
	PrintDbl.3 RecEvalObj.3 RecordEval.3 RegExp.3 SetErrno.3 SetRecLmt.3 \
	SetResult.3 SetVar.3 Sleep.3 SplitList.3 SplitPath.3 StaticPkg.3 \
	StrMatch.3 StringObj.3 Tcl_Main.3 TraceVar.3 Translate.3 UpVar.3

MANN=	Tcl.n after.n append.n array.n bgerror.n binary.n break.n \
	case.n catch.n cd.n clock.n close.n concat.n continue.n eof.n error.n \
	eval.n exec.n exit.n expr.n fblocked.n fconfigure.n fcopy.n file.n \
	fileevent.n filename.n flush.n for.n foreach.n format.n gets.n glob.n \
	global.n history.n http.n if.n incr.n info.n interp.n join.n lappend.n \
	library.n lindex.n linsert.n list.n llength.n load.n lrange.n \
	lreplace.n lsearch.n lsort.n namespace.n open.n package.n pid.n \
	pkgMkIndex.n proc.n puts.n pwd.n read.n regexp.n registry.n regsub.n \
	rename.n resource.n return.n safe.n scan.n seek.n set.n socket.n \
	source.n split.n string.n subst.n switch.n tclvars.n tell.n time.n \
	trace.n unknown.n unset.n update.n uplevel.n upvar.n variable.n

MLINKS=	AddErrInfo.3 Tcl_AddErrorInfo.3 - Tcl_AddObjErrorInfo.3 \
	- Tcl_PosixError.3 - Tcl_SetErrorCode.3 \
	Alloc.3 Tcl_Alloc.3 - Tcl_Free.3 - Tcl_Realloc.3 \
	AllowExc.3 Tcl_AllowExceptions.3 \
	AppInit.3 Tcl_AppInit.3 \
	AssocData.3 Tcl_DeleteAssocData.3 - Tcl_GetAssocData.3 \
	- Tcl_SetAssocData.3 \
	Async.3 Tcl_AsyncCreate.3 - Tcl_AsyncDelete.3 - Tcl_AsyncInvoke.3 \
	- Tcl_AsyncMark.3 \
	BackgdErr.3 Tcl_BackgroundError.3 \
	Backslash.3 Tcl_Backslash.3 \
	BoolObj.3 Tcl_GetBooleanFromObj.3 - Tcl_NewBooleanObj.3 \
	- Tcl_SetBooleanObj.3 \
	CallDel.3 Tcl_CallWhenDeleted.3 - Tcl_DontCallWhenDeleted.3 \
	CmdCmplt.3 Tcl_CommandComplete.3 \
	Concat.3 Tcl_Concat.3 \
	CrtChannel.3 Tcl_BadChannelOption.3 - Tcl_CreateChannel.3 \
	- Tcl_GetChannelBufferSize.3 - Tcl_GetChannelHandle.3 \
	- Tcl_GetChannelInstanceData.3 - Tcl_GetChannelMode.3 \
	- Tcl_GetChannelName.3 - Tcl_GetChannelType.3 - Tcl_NotifyChannel.3 \
	- Tcl_SetChannelBufferSize.3 - Tcl_SetDefaultTranslation.3 \
	CrtChnlHdlr.3 Tcl_CreateChannelHandler.3 - Tcl_DeleteChannelHandler.3 \
	CrtCloseHdlr.3 Tcl_CreateCloseHandler.3 - Tcl_DeleteCloseHandler.3 \
	CrtCommand.3 Tcl_CreateCommand.3 \
	CrtFileHdlr.3 Tcl_CreateFileHandler.3 - Tcl_DeleteFileHandler.3 \
	CrtInterp.3 Tcl_CreateInterp.3 - Tcl_DeleteInterp.3 \
	- Tcl_InterpDeleted.3 \
	CrtMathFnc.3 Tcl_CreateMathFunc.3 \
	CrtObjCmd.3 Tcl_CreateObjCommand.3 - Tcl_DeleteCommand.3 \
	- Tcl_DeleteCommandFromToken.3 - Tcl_GetCommandInfo.3 \
	- Tcl_GetCommandName.3 - Tcl_SetCommandInfo.3 \
	CrtSlave.3 Tcl_CreateAlias.3 - Tcl_CreateAliasObj.3 \
	- Tcl_CreateSlave.3 - Tcl_ExposeCommand.3 - Tcl_GetAlias.3 \
	- Tcl_GetAliasObj.3 - Tcl_GetInterpPath.3 - Tcl_GetMaster.3 \
	- Tcl_GetSlave.3 - Tcl_HideCommand.3 - Tcl_IsSafe.3 - Tcl_MakeSafe.3 \
	CrtTimerHdlr.3 Tcl_CreateTimerHandler.3 - Tcl_DeleteTimerHandler.3 \
	CrtTrace.3 Tcl_CreateTrace.3 - Tcl_DeleteTrace.3 \
	DString.3 Tcl_DStringAppend.3 - Tcl_DStringAppendElement.3 \
	- Tcl_DStringEndSublist.3 - Tcl_DStringFree.3 - Tcl_DStringGetResult.3 \
	- Tcl_DStringInit.3 - Tcl_DStringLength.3 - Tcl_DStringResult.3 \
	- Tcl_DStringSetLength.3 - Tcl_DStringStartSublist.3 \
	- Tcl_DStringValue.3 \
	DetachPids.3 Tcl_DetachPids.3 - Tcl_ReapDetachedProcs.3 \
	DoOneEvent.3 Tcl_DoOneEvent.3 \
	DoWhenIdle.3 Tcl_CancelIdleCall.3 - Tcl_DoWhenIdle.3 \
	DoubleObj.3 Tcl_GetDoubleFromObj.3 - Tcl_NewDoubleObj.3 \
	- Tcl_SetDoubleObj.3 \
	Eval.3 Tcl_Eval.3 - Tcl_EvalFile.3 - Tcl_GlobalEval.3 - Tcl_VarEval.3 \
	EvalObj.3 Tcl_EvalObj.3 - Tcl_GlobalEvalObj.3 \
	Exit.3 Tcl_CreateExitHandler.3 - Tcl_DeleteExitHandler.3 - Tcl_Exit.3 \
	- Tcl_Finalize.3 \
	ExprLong.3 Tcl_ExprBoolean.3 - Tcl_ExprDouble.3 - Tcl_ExprLong.3 \
	- Tcl_ExprString.3 \
	ExprLongObj.3 Tcl_ExprBooleanObj.3 - Tcl_ExprDoubleObj.3 \
	- Tcl_ExprLongObj.3 - Tcl_ExprObj.3 \
	FindExec.3 Tcl_FindExecutable.3 - Tcl_GetNameOfExecutable.3 \
	GetIndex.3 Tcl_GetIndexFromObj.3 \
	GetInt.3 Tcl_GetBoolean.3 - Tcl_GetDouble.3 - Tcl_GetInt.3 \
	GetOpnFl.3 Tcl_GetOpenFile.3 \
	GetStdChan.3 Tcl_GetStdChannel.3 - Tcl_SetStdChannel.3 \
	Hash.3 Tcl_CreateHashEntry.3 - Tcl_DeleteHashEntry.3 \
	- Tcl_DeleteHashTable.3 - Tcl_FindHashEntry.3 - Tcl_FirstHashEntry.3 \
	- Tcl_GetHashKey.3 - Tcl_GetHashValue.3 - Tcl_HashStats.3 \
	- Tcl_InitHashTable.3 - Tcl_NextHashEntry.3 - Tcl_SetHashValue.3 \
	IntObj.3 Tcl_GetIntFromObj.3 - Tcl_GetLongFromObj.3 - Tcl_NewIntObj.3 \
	- Tcl_NewLongObj.3 - Tcl_SetIntObj.3 - Tcl_SetLongObj.3 \
	Interp.3 Tcl_Interp.3 \
	LinkVar.3 Tcl_LinkVar.3 - Tcl_UnlinkVar.3 - Tcl_UpdateLinkedVar.3 \
	ListObj.3 Tcl_ListObjAppendElement.3 - Tcl_ListObjAppendList.3 \
	- Tcl_ListObjGetElements.3 - Tcl_ListObjIndex.3 - Tcl_ListObjLength.3 \
	- Tcl_ListObjReplace.3 - Tcl_NewListObj.3 - Tcl_SetListObj.3 \
	Notifier.3 Tcl_CreateEventSource.3 - Tcl_DeleteEventSource.3 \
	- Tcl_DeleteEvents.3 - Tcl_GetServiceMode.3 - Tcl_QueueEvent.3 \
	- Tcl_ServiceAll.3 - Tcl_ServiceEvent.3 - Tcl_SetMaxBlockTime.3 \
	- Tcl_SetServiceMode.3 - Tcl_SetTimer.3 - Tcl_WaitForEvent.3 \
	ObjSetVar.3 Tcl_ObjGetVar2.3 - Tcl_ObjSetVar2.3 \
	Object.3 Tcl_DecrRefCount.3 - Tcl_DuplicateObj.3 - Tcl_IncrRefCount.3 \
	- Tcl_IsShared.3 - Tcl_NewObj.3 \
	ObjectType.3 Tcl_AppendAllObjTypes.3 - Tcl_ConvertToType.3 \
	- Tcl_GetObjType.3 - Tcl_RegisterObjType.3 \
	OpenFileChnl.3 Tcl_Close.3 - Tcl_Eof.3 - Tcl_Flush.3 \
	- Tcl_GetChannel.3 - Tcl_GetChannelOption.3 - Tcl_Gets.3 \
	- Tcl_InputBlocked.3 - Tcl_InputBuffered.3 - Tcl_MakeFileChannel.3 \
	- Tcl_OpenCommandChannel.3 - Tcl_OpenFileChannel.3 - Tcl_Read.3 \
	- Tcl_RegisterChannel.3 - Tcl_Seek.3 - Tcl_SetChannelOption.3 \
	- Tcl_Tell.3 - Tcl_UnregisterChannel.3 - Tcl_Write.3 \
	OpenTcp.3 Tcl_MakeTcpClientChannel.3 - Tcl_OpenTcpClient.3 \
	- Tcl_OpenTcpServer.3 \
	PkgRequire.3 Tcl_PkgProvide.3 - Tcl_PkgRequire.3 \
	Preserve.3 Tcl_EventuallyFree.3 - Tcl_Preserve.3 - Tcl_Release.3 \
	PrintDbl.3 Tcl_PrintDouble.3 \
	RecEvalObj.3 Tcl_RecordAndEvalObj.3 \
	RecordEval.3 Tcl_RecordAndEval.3 \
	RegExp.3 Tcl_RegExpCompile.3 - Tcl_RegExpExec.3 - Tcl_RegExpMatch.3 \
	- Tcl_RegExpRange.3 \
	SetErrno.3 Tcl_GetErrno.3 - Tcl_SetErrno.3 \
	SetRecLmt.3 Tcl_SetRecursionLimit.3 \
	SetResult.3 Tcl_AppendElement.3 - Tcl_AppendResult.3 \
	- Tcl_GetObjResult.3 - Tcl_GetStringResult.3 - Tcl_ResetResult.3 \
	- Tcl_SetObjResult.3 - Tcl_SetResult.3 \
	SetVar.3 Tcl_GetVar.3 - Tcl_GetVar2.3 - Tcl_SetVar.3 - Tcl_SetVar2.3 \
	- Tcl_UnsetVar.3 - Tcl_UnsetVar2.3 \
	Sleep.3 Tcl_Sleep.3 \
	SplitList.3 Tcl_ConvertElement.3 - Tcl_Merge.3 - Tcl_ScanElement.3 \
	- Tcl_SplitList.3 \
	SplitPath.3 Tcl_GetPathType.3 - Tcl_JoinPath.3 - Tcl_SplitPath.3 \
	StaticPkg.3 Tcl_StaticPackage.3 \
	StrMatch.3 Tcl_StringMatch.3 \
	StringObj.3 TclConcatObj.3 - Tcl_AppendStringsToObj.3 \
	- Tcl_AppendToObj.3 - Tcl_GetStringFromObj.3 - Tcl_NewStringObj.3 \
	- Tcl_SetObjLength.3 - Tcl_SetStringObj.3 \
	TraceVar.3 Tcl_TraceVar.3 - Tcl_TraceVar2.3 - Tcl_UntraceVar.3 \
	- Tcl_UntraceVar2.3 - Tcl_VarTraceInfo.3 - Tcl_VarTraceInfo2.3 \
	Translate.3 Tcl_TranslateFileName.3 \
	UpVar.3 Tcl_UpVar.3 - Tcl_UpVar2.3 \
	WrongNumArgs.3 Tcl_WrongNumArgs.3 \
	http.n Http.n \
	pkgMkIndex.n pkg_mkIndex.n

MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
TCL_LIB_FILE=	${TCL_LIB}.${SHLIB_MAJOR}
.else
TCL_LIB_FILE=	${TCL_LIB}.${SHLIB_MAJOR}.${SHLIB_MINOR}
.endif

post-patch:
	@${CP} ${WRKSRC}/mkLinks ${WRKSRC}/mkLinks.orig
	@${SED} -e 's/\.[3n]/&.gz/g' ${WRKSRC}/mkLinks.orig > ${WRKSRC}/mkLinks

post-configure:
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}
	@${CP} ${FILESDIR}/makefile     ${WRKSRC}

pre-build:
	@cd ${WRKSRC} && ${MAKE} -f Makefile.lib PREFIX=${PREFIX} \
	   SHLIB_MAJOR=${SHLIB_MAJOR} SHLIB_MINOR=${SHLIB_MINOR}

post-install:
	${LN} -sf ${TCL_LIB_FILE} ${PREFIX}/lib/${TCL_LIB}
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
.if exists(${PKGINSTALL})
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL}
.endif

test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.post.mk>
