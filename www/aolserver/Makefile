# New ports collection makefile for:	aolserver
# Date created:		13 January 2000
# Whom:			Matthew Braithwaite <mab@red-bean.com>
#
# $FreeBSD$
#

PORTNAME=	aolserver
PORTVERSION=	4.0.10
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	aolserver
DISTFILES=	${PORTNAME}-${PORTVERSION}-src.tar.gz \
		nssha1-0.1.tar.gz \
		nscache-1.5.tar.gz \
		nspostgres-4.0.tar.gz \
		nsoracle-2.7.tar.gz

MAINTAINER=	aldert@nooitgedagt.net
COMMENT=	A multithreaded web server with embedded TCL interpreter

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
MANPREFIX=	${PREFIX}/${PORTNAME}
AOLSERVERBASE=	${PREFIX}/${PORTNAME}

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${AOLSERVERBASE} \
			--with-tcl=${LOCALBASE}/lib/tcl8.4

LIB_DEPENDS+=	tcl84.1:${PORTSDIR}/lang/tcl84-thread

USE_RC_SUBR=	YES
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-message aolserver.sh pkg-install
SUB_LIST+=	AOLSERVERBASE=${AOLSERVERBASE}

.if defined(WITH_NSCACHE)
PLIST_SUB+=	nscache=""
.else
PLIST_SUB+=	nscache="@comment "
.endif

.if defined(WITH_NSSHA1)
PLIST_SUB+=	nssha1=""
.else
PLIST_SUB+=	nssha1="@comment "
.endif

.if defined(WITH_ORACLE)
PLIST_SUB+=	nsoracle=""
.else
PLIST_SUB+=	nsoracle="@comment "
.endif

.if defined(WITH_NSPOSTGRES)
PLIST_SUB+=	nspostgres=""
BUILD_DEPENDS+=	${LOCALBASE}/bin/postmaster:${PORTSDIR}/databases/postgresql74-server
.else
PLIST_SUB+=	nspostgres="@comment "
.endif

MANCOMPRESSED=	no
MAN1=		nsd.1
MAN3=		Ns_AbsTimedWaitForEvent.3 Ns_AbsoluteUrl.3 Ns_AdjTime.3 \
		Ns_Adp.3 Ns_AdpRegisterParser.3 Ns_AdpRequest.3 Ns_After.3 \
		Ns_Alloc.3 Ns_AllocThreadLocalStorage.3 Ns_Auth.3 \
		Ns_AuthorizeRequest.3 Ns_AuthorizeUser.3 \
		Ns_BeginDetachedThread.3 Ns_BeginThread.3 Ns_BindSock.3 \
		Ns_BroadcastEvent.3 Ns_Cache.3 Ns_CacheBroadcast.3 \
		Ns_CacheCreate.3 Ns_CacheCreateEntry.3 Ns_CacheCreateSz.3 \
		Ns_CacheDeleteEntry.3 Ns_CacheDestroy.3 Ns_CacheFind.3 \
		Ns_CacheFindEntry.3 Ns_CacheFirstEntry.3 Ns_CacheFlush.3 \
		Ns_CacheFlushEntry.3 Ns_CacheFree.3 Ns_CacheGetValue.3 \
		Ns_CacheKey.3 Ns_CacheLock.3 Ns_CacheMalloc.3 Ns_CacheName.3 \
		Ns_CacheNextEntry.3 Ns_CacheSetValue.3 Ns_CacheSetValueSz.3 \
		Ns_CacheSignal.3 Ns_CacheTimedWait.3 Ns_CacheUnlock.3 \
		Ns_CacheUnsetValue.3 Ns_CacheWait.3 Ns_Calloc.3 Ns_Cancel.3 \
		Ns_ClearSockErrno.3 Ns_CloseOnExec.3 Ns_Cls.3 Ns_ClsAlloc.3 \
		Ns_ClsGet.3 Ns_ClsSet.3 Ns_Cond.3 Ns_CondBroadcast.3 \
		Ns_CondDestroy.3 Ns_CondInit.3 Ns_CondSignal.3 \
		Ns_CondTimedWait.3 Ns_CondWait.3 Ns_Config.3 Ns_ConfigGetBool.3 \
		Ns_ConfigGetInt.3 Ns_ConfigGetInt64.3 Ns_ConfigGetPath.3 \
		Ns_ConfigGetSection.3 Ns_ConfigGetSections.3 \
		Ns_ConfigGetValue.3 Ns_ConfigGetValueExact.3 Ns_Conn.3 \
		Ns_ConnAuthPasswd.3 Ns_ConnAuthUser.3 Ns_ConnClose.3 \
		Ns_ConnCondSetHeaders.3 Ns_ConnConstructHeaders.3 \
		Ns_ConnContent.3 Ns_ConnContentLength.3 Ns_ConnContentSent.3 \
		Ns_ConnCopy.3 Ns_ConnCopyToChannel.3 Ns_ConnCopyToDString.3 \
		Ns_ConnCopyToFd.3 Ns_ConnCopyToFile.3 Ns_ConnDriver.3 \
		Ns_ConnDriverContext.3 Ns_ConnDriverName.3 \
		Ns_ConnFlushContent.3 Ns_ConnFlushHeaders.3 \
		Ns_ConnGetEncoding.3 Ns_ConnGetQuery.3 Ns_ConnGets.3 \
		Ns_ConnHeaders.3 Ns_ConnHost.3 Ns_ConnId.3 Ns_ConnInit.3 \
		Ns_ConnLocation.3 Ns_ConnModifiedSince.3 Ns_ConnOutputHeaders.3 \
		Ns_ConnPeer.3 Ns_ConnPeerPort.3 Ns_ConnPort.3 \
		Ns_ConnPrintfHeader.3 Ns_ConnPuts.3 Ns_ConnQueueHeaders.3 \
		Ns_ConnRead.3 Ns_ConnReadHeaders.3 Ns_ConnReadLine.3 \
		Ns_ConnRedirect.3 Ns_ConnReplaceHeaders.3 Ns_ConnRequest.3 \
		Ns_ConnResetReturn.3 Ns_ConnResponseLength.3 \
		Ns_ConnResponseStatus.3 Ns_ConnReturn.3 \
		Ns_ConnReturnAdminNotice.3 Ns_ConnReturnBadRequest.3 \
		Ns_ConnReturnData.3 Ns_ConnReturnFile.3 \
		Ns_ConnReturnForbidden.3 Ns_ConnReturnHtml.3 \
		Ns_ConnReturnInternalError.3 Ns_ConnReturnNoResponse.3 \
		Ns_ConnReturnNotFound.3 Ns_ConnReturnNotImplemented.3 \
		Ns_ConnReturnNotModified.3 Ns_ConnReturnNotice.3 \
		Ns_ConnReturnOk.3 Ns_ConnReturnOpenChannel.3 \
		Ns_ConnReturnOpenFd.3 Ns_ConnReturnOpenFile.3 \
		Ns_ConnReturnRedirect.3 Ns_ConnReturnStatus.3 \
		Ns_ConnReturnUnauthorized.3 Ns_ConnRunRequest.3 Ns_ConnSend.3 \
		Ns_ConnSendChannel.3 Ns_ConnSendDString.3 Ns_ConnSendFd.3 \
		Ns_ConnSendFp.3 Ns_ConnServer.3 Ns_ConnSetEncoding.3 \
		Ns_ConnSetExpiresHeader.3 Ns_ConnSetHeaders.3 \
		Ns_ConnSetLastModifiedHeader.3 Ns_ConnSetLengthHeader.3 \
		Ns_ConnSetRequiredHeaders.3 Ns_ConnSetTypeHeader.3 \
		Ns_ConnSock.3 Ns_ConnWrite.3 Ns_CopyEnviron.3 Ns_CritSec.3 \
		Ns_CsDestroy.3 Ns_CsEnter.3 Ns_CsInit.3 Ns_CsLeave.3 Ns_DRand.3 \
		Ns_DString.3 Ns_DStringAppend.3 Ns_DStringAppendArg.3 \
		Ns_DStringAppendArgv.3 Ns_DStringAppendElement.3 \
		Ns_DStringExport.3 Ns_DStringFree.3 Ns_DStringInit.3 \
		Ns_DStringLength.3 Ns_DStringNAppend.3 Ns_DStringPop.3 \
		Ns_DStringPrintf.3 Ns_DStringPush.3 Ns_DStringSetLength.3 \
		Ns_DStringTrunc.3 Ns_DStringVPrintf.3 Ns_DStringValue.3 \
		Ns_DStringVarAppend.3 Ns_Db.3 Ns_Db0or1Row.3 Ns_Db1Row.3 \
		Ns_DbBindRow.3 Ns_DbBouncePool.3 Ns_DbCancel.3 Ns_DbDML.3 \
		Ns_DbDriver.3 Ns_DbDriverDbType.3 Ns_DbDriverName.3 Ns_DbExec.3 \
		Ns_DbFlush.3 Ns_DbGetRow.3 Ns_DbInterpretSqlFile.3 Ns_DbPool.3 \
		Ns_DbPoolAllowable.3 Ns_DbPoolDefault.3 Ns_DbPoolDescription.3 \
		Ns_DbPoolGetHandle.3 Ns_DbPoolGetMultipleHandles.3 \
		Ns_DbPoolList.3 Ns_DbPoolPutHandle.3 Ns_DbPoolTimedGetHandle.3 \
		Ns_DbPoolTimedGetMultipleHandles.3 Ns_DbQuoteValue.3 \
		Ns_DbRegisterDriver.3 Ns_DbResetHandle.3 Ns_DbSelect.3 \
		Ns_DbSetException.3 Ns_DbSp.3 Ns_DbSpExec.3 Ns_DbSpGetParams.3 \
		Ns_DbSpReturnCode.3 Ns_DbSpSetParam.3 Ns_DbSpStart.3 \
		Ns_DbUtil.3 Ns_DecodeUrl.3 Ns_DestroyCriticalSection.3 \
		Ns_DestroyEvent.3 Ns_DestroyMutex.3 Ns_DestroyRWLock.3 \
		Ns_DestroySemaphore.3 Ns_DiffTime.3 Ns_Driver.3 Ns_DriverInit.3 \
		Ns_DupHigh.3 Ns_EncodeUrl.3 Ns_Encoding.3 Ns_Encrypt.3 \
		Ns_EnterCriticalSection.3 Ns_Env.3 Ns_Exec.3 Ns_ExecArgblk.3 \
		Ns_ExecArgv.3 Ns_ExecProc.3 Ns_ExecProcess.3 Ns_ExitThread.3 \
		Ns_ExtDb.3 Ns_ExtDbMsgCodeToName.3 Ns_ExtDbMsgNameToCode.3 \
		Ns_ExtDbMsgRequiresArg.3 Ns_Fatal.3 Ns_Fd.3 Ns_Fetch.3 \
		Ns_FetchPage.3 Ns_FetchURL.3 Ns_Filter.3 Ns_Fork.3 Ns_Free.3 \
		Ns_FreeConnInterp.3 Ns_FreeRequest.3 Ns_GenSeeds.3 \
		Ns_GetAddrByHost.3 Ns_GetCharsetEncoding.3 Ns_GetConn.3 \
		Ns_GetConnInterp.3 Ns_GetDriverContext.3 Ns_GetEncoding.3 \
		Ns_GetEnviron.3 Ns_GetFileEncoding.3 Ns_GetGid.3 \
		Ns_GetHostByAddr.3 Ns_GetMimeType.3 Ns_GetProcInfo.3 \
		Ns_GetRequest.3 Ns_GetSockAddr.3 Ns_GetSockErrno.3 Ns_GetTemp.3 \
		Ns_GetThread.3 Ns_GetThreadId.3 Ns_GetThreadLocalStorage.3 \
		Ns_GetThreadServer.3 Ns_GetTime.3 Ns_GetTypeEncoding.3 \
		Ns_GetUid.3 Ns_GetUserGid.3 Ns_GetUserHome.3 Ns_HomePath.3 \
		Ns_HttpTime.3 Ns_Htuu.3 Ns_HtuuDecode.3 Ns_HtuuEncode.3 \
		Ns_IncrTime.3 Ns_Index.3 Ns_IndexAdd.3 Ns_IndexDel.3 \
		Ns_IndexDestroy.3 Ns_IndexDup.3 Ns_IndexEl.3 Ns_IndexFind.3 \
		Ns_IndexFindInf.3 Ns_IndexFindMultiple.3 Ns_IndexInit.3 \
		Ns_IndexIntInit.3 Ns_IndexStringAppend.3 \
		Ns_IndexStringDestroy.3 Ns_IndexStringDup.3 \
		Ns_IndexStringInit.3 Ns_IndexStringTrunc.3 Ns_IndexTrunc.3 \
		Ns_InetAddr.3 Ns_Info.3 Ns_InfoAddress.3 Ns_InfoBootTime.3 \
		Ns_InfoBuildDate.3 Ns_InfoConfigFile.3 Ns_InfoErrorLog.3 \
		Ns_InfoHomePath.3 Ns_InfoHostname.3 Ns_InfoLabel.3 \
		Ns_InfoNameOfExecutable.3 Ns_InfoPid.3 Ns_InfoPlatform.3 \
		Ns_InfoServerName.3 Ns_InfoServerVersion.3 \
		Ns_InfoServersStarted.3 Ns_InfoShutdownPending.3 \
		Ns_InfoStarted.3 Ns_InfoTag.3 Ns_InfoUptime.3 \
		Ns_InitializeCriticalSection.3 Ns_InitializeEvent.3 \
		Ns_InitializeMutex.3 Ns_InitializeRWLock.3 \
		Ns_InitializeSemaphore.3 Ns_IntPrint.3 \
		Ns_LeaveCriticalSection.3 Ns_LibPath.3 Ns_List.3 Ns_ListCons.3 \
		Ns_ListCopy.3 Ns_ListDeleteDuplicates.3 Ns_ListDeleteIf.3 \
		Ns_ListDeleteLowElements.3 Ns_ListDeleteWithTest.3 \
		Ns_ListFree.3 Ns_ListLast.3 Ns_ListLength.3 Ns_ListMapcar.3 \
		Ns_ListNconc.3 Ns_ListNmapcar.3 Ns_ListNreverse.3 \
		Ns_ListPrint.3 Ns_ListSort.3 Ns_ListWeightSort.3 Ns_Location.3 \
		Ns_LockMutex.3 Ns_Log.3 Ns_LogRoll.3 Ns_LogTime.3 Ns_LogTime2.3 \
		Ns_Main.3 Ns_MakePath.3 Ns_Malloc.3 Ns_Master.3 Ns_MasterLock.3 \
		Ns_MasterUnlock.3 Ns_Match.3 Ns_Mime.3 Ns_Module.3 \
		Ns_ModuleGetSymbol.3 Ns_ModuleLoad.3 Ns_ModulePath.3 \
		Ns_ModuleSymbol.3 Ns_Mutex.3 Ns_MutexDestroy.3 Ns_MutexInit.3 \
		Ns_MutexList.3 Ns_MutexLock.3 Ns_MutexSetName.3 \
		Ns_MutexSetName2.3 Ns_MutexTryLock.3 Ns_MutexUnlock.3 \
		Ns_NextWord.3 Ns_NoCloseOnExec.3 Ns_NormalizePath.3 Ns_Nsd.3 \
		Ns_PageRoot.3 Ns_ParseHeader.3 Ns_ParseHttpTime.3 \
		Ns_ParseRequest.3 Ns_ParseUrl.3 Ns_PathIsAbsolute.3 \
		Ns_Pathname.3 Ns_Pause.3 Ns_Pool.3 Ns_PoolAlloc.3 \
		Ns_PoolBlockSize.3 Ns_PoolCalloc.3 Ns_PoolCreate.3 \
		Ns_PoolDestroy.3 Ns_PoolFlush.3 Ns_PoolFree.3 Ns_PoolRealloc.3 \
		Ns_PoolStrCopy.3 Ns_PoolStrDup.3 Ns_ProcInfo.3 Ns_PurgeFiles.3 \
		Ns_QueryToSet.3 Ns_QueueConn.3 Ns_QuoteHtml.3 Ns_RWLock.3 \
		Ns_RWLockDestroy.3 Ns_RWLockInit.3 Ns_RWLockRdLock.3 \
		Ns_RWLockUnlock.3 Ns_RWLockWrLock.3 Ns_Rand.3 \
		Ns_ReadLockRWLock.3 Ns_ReadUnlockRWLock.3 Ns_Realloc.3 \
		Ns_Reentrant.3 Ns_Register.3 Ns_RegisterAtExit.3 \
		Ns_RegisterAtPreStartup.3 Ns_RegisterAtReady.3 \
		Ns_RegisterAtServerShutdown.3 Ns_RegisterAtShutdown.3 \
		Ns_RegisterAtSignal.3 Ns_RegisterAtStartup.3 \
		Ns_RegisterCleanup.3 Ns_RegisterConnCleanup.3 \
		Ns_RegisterDriver.3 Ns_RegisterFilter.3 Ns_RegisterModule.3 \
		Ns_RegisterProcInfo.3 Ns_RegisterProxyRequest.3 \
		Ns_RegisterRequest.3 Ns_RegisterReturn.3 \
		Ns_RegisterServerShutdown.3 Ns_RegisterServerTrace.3 \
		Ns_RegisterShutdown.3 Ns_RelativeUrl.3 Ns_ReleaseSemaphore.3 \
		Ns_ReleaseTemp.3 Ns_Request.3 Ns_Resume.3 Ns_RollFile.3 \
		Ns_RollFileByDate.3 Ns_Sched.3 Ns_ScheduleDaily.3 \
		Ns_ScheduleProc.3 Ns_ScheduleProcEx.3 Ns_ScheduleWeekly.3 \
		Ns_Sema.3 Ns_SemaDestroy.3 Ns_SemaInit.3 Ns_SemaPost.3 \
		Ns_SemaWait.3 Ns_ServerSpecific.3 Ns_ServerSpecificAlloc.3 \
		Ns_ServerSpecificDestroy.3 Ns_ServerSpecificGet.3 \
		Ns_ServerSpecificSet.3 Ns_Set.3 Ns_SetConnLocationProc.3 \
		Ns_SetCopy.3 Ns_SetCreate.3 Ns_SetDelete.3 Ns_SetDeleteKey.3 \
		Ns_SetEvent.3 Ns_SetFind.3 Ns_SetFindCmp.3 Ns_SetFree.3 \
		Ns_SetGet.3 Ns_SetGetCmp.3 Ns_SetIDeleteKey.3 Ns_SetIFind.3 \
		Ns_SetIGet.3 Ns_SetIUnique.3 Ns_SetListFind.3 Ns_SetListFree.3 \
		Ns_SetLocationProc.3 Ns_SetMerge.3 Ns_SetMove.3 Ns_SetPrint.3 \
		Ns_SetPut.3 Ns_SetPutValue.3 Ns_SetRequestAuthorizeProc.3 \
		Ns_SetRequestUrl.3 Ns_SetSockErrno.3 Ns_SetSplit.3 \
		Ns_SetThreadLocalStorage.3 Ns_SetThreadServer.3 Ns_SetTrunc.3 \
		Ns_SetUnique.3 Ns_SetUniqueCmp.3 Ns_SetUpdate.3 \
		Ns_SetUrlToFileProc.3 Ns_SetUserAuthorizeProc.3 Ns_Signal.3 \
		Ns_SkipUrl.3 Ns_Sock.3 Ns_SockAccept.3 Ns_SockAsyncConnect.3 \
		Ns_SockAsyncConnect2.3 Ns_SockBind.3 Ns_SockCallback.3 \
		Ns_SockCancelCallback.3 Ns_SockCloseLater.3 Ns_SockConnect.3 \
		Ns_SockConnect2.3 Ns_SockErrno.3 Ns_SockIO.3 Ns_SockListen.3 \
		Ns_SockListenCallback.3 Ns_SockListenEx.3 Ns_SockPipe.3 \
		Ns_SockPortBound.3 Ns_SockRecv.3 Ns_SockSend.3 \
		Ns_SockSetBlocking.3 Ns_SockSetNonBlocking.3 Ns_SockStrError.3 \
		Ns_SockTimedConnect.3 Ns_SockTimedConnect2.3 Ns_SockWait.3 \
		Ns_StopServer.3 Ns_StrCaseFind.3 Ns_StrCopy.3 Ns_StrDup.3 \
		Ns_StrNStr.3 Ns_StrToLower.3 Ns_StrToUpper.3 Ns_StrTrim.3 \
		Ns_StrTrimLeft.3 Ns_StrTrimRight.3 Ns_String.3 Ns_StringPrint.3 \
		Ns_TclAllocateInterp.3 Ns_TclConn.3 Ns_TclCreateInterp.3 \
		Ns_TclDbGetHandle.3 Ns_TclDeAllocateInterp.3 \
		Ns_TclDestroyInterp.3 Ns_TclDetachedThread.3 Ns_TclEnterSet.3 \
		Ns_TclEval.3 Ns_TclFile.3 Ns_TclFreeSet.3 Ns_TclGetConn.3 \
		Ns_TclGetOpenChannel.3 Ns_TclGetOpenFd.3 Ns_TclGetSet.3 \
		Ns_TclGetSet2.3 Ns_TclGetTimeFromObj.3 Ns_TclInit.3 \
		Ns_TclInitInterps.3 Ns_TclInitModule.3 Ns_TclInterp.3 \
		Ns_TclInterpServer.3 Ns_TclLibrary.3 Ns_TclLogError.3 \
		Ns_TclLogErrorRequest.3 Ns_TclMarkForDelete.3 Ns_TclRegister.3 \
		Ns_TclRegisterAtCleanup.3 Ns_TclRegisterAtCreate.3 \
		Ns_TclRegisterAtDelete.3 Ns_TclRegisterDeferred.3 \
		Ns_TclRequest.3 Ns_TclSet.3 Ns_TclSetTimeObj.3 Ns_TclThread.3 \
		Ns_TclTimeObj.3 Ns_TempFile.3 Ns_Thread.3 Ns_Thread2.3 \
		Ns_ThreadAlloc.3 Ns_ThreadCalloc.3 Ns_ThreadCreate.3 \
		Ns_ThreadExit.3 Ns_ThreadFree.3 Ns_ThreadGetName.3 \
		Ns_ThreadGetParent.3 Ns_ThreadId.3 Ns_ThreadJoin.3 \
		Ns_ThreadList.3 Ns_ThreadMalloc.3 Ns_ThreadPool.3 \
		Ns_ThreadRealloc.3 Ns_ThreadSelf.3 Ns_ThreadSetName.3 \
		Ns_ThreadStackSize.3 Ns_ThreadStrCopy.3 Ns_ThreadStrDup.3 \
		Ns_ThreadYield.3 Ns_Time.3 Ns_TimedWaitForEvent.3 Ns_Tls.3 \
		Ns_TlsAlloc.3 Ns_TlsGet.3 Ns_TlsSet.3 Ns_UTimedWaitForEvent.3 \
		Ns_Uid.3 Ns_UnRegisterProxyRequest.3 Ns_UnRegisterRequest.3 \
		Ns_UnlockMutex.3 Ns_UnscheduleProc.3 Ns_Url.3 Ns_UrlEncode.3 \
		Ns_UrlIsDir.3 Ns_UrlIsFile.3 Ns_UrlSpecific.3 \
		Ns_UrlSpecificAlloc.3 Ns_UrlSpecificDestroy.3 \
		Ns_UrlSpecificGet.3 Ns_UrlSpecificGetExact.3 \
		Ns_UrlSpecificGetFast.3 Ns_UrlSpecificSet.3 Ns_UrlToFile.3 \
		Ns_WaitForEvent.3 Ns_WaitForProcess.3 Ns_WaitForSemaphore.3 \
		Ns_WaitForStartup.3 Ns_WaitForThread.3 Ns_WaitProcess.3 \
		Ns_WaitThread.3 Ns_WriteConn.3 Ns_WriteLockRWLock.3 \
		Ns_WriteUnlockRWLock.3 ns_asctime.3 ns_calloc.3 \
		ns_closeonexec.3 ns_ctime.3 ns_duphigh.3 ns_fork.3 ns_free.3 \
		ns_gmtime.3 ns_inet_ntoa.3 ns_localtime.3 ns_malloc.3 ns_pipe.3 \
		ns_readdir.3 ns_realloc.3 ns_serverLog.3 ns_sigmask.3 \
		ns_signal.3 ns_sigwait.3 ns_sockpair.3 ns_strcopy.3 ns_strdup.3 \
		ns_strtok.3
MANN=		crash.n env.n ns_addr.n ns_addrbyhost.n ns_adp.n ns_adp_abort.n \
		ns_adp_append.n ns_adp_argc.n ns_adp_argv.n ns_adp_bind_args.n \
		ns_adp_break.n ns_adp_debug.n ns_adp_dir.n ns_adp_dump.n \
		ns_adp_eval.n ns_adp_exception.n ns_adp_mime.n \
		ns_adp_mimetype.n ns_adp_parse.n ns_adp_puts.n \
		ns_adp_registeradp.n ns_adp_registerproc.n ns_adp_registertag.n \
		ns_adp_return.n ns_adp_safeeval.n ns_adp_stats.n \
		ns_adp_stream.n ns_adp_tell.n ns_adp_trunc.n ns_after.n ns_at.n \
		ns_atclose.n ns_atexit.n ns_atshutdown.n ns_atsignal.n \
		ns_cache.n ns_cache_flush.n ns_cache_keys.n ns_cache_names.n \
		ns_cache_size.n ns_cache_stats.n ns_cancel.n ns_chan.n \
		ns_checkurl.n ns_chmod.n ns_cleanup.n ns_column.n ns_cond.n \
		ns_config.n ns_configsection.n ns_configsections.n ns_conn.n \
		ns_conncptofp.n ns_connsendfp.n ns_cp.n ns_cpfp.n ns_crash.n \
		ns_critsec.n ns_crypt.n ns_db.n ns_dbconfigpath.n \
		ns_dberrorcode.n ns_dberrormsg.n ns_dbreturnerror.n ns_env.n \
		ns_eval.n ns_event.n ns_file.n ns_filter.n ns_fmttime.n \
		ns_ftruncate.n ns_get_multipart_formdata.n ns_getchannels.n \
		ns_getcsv.n ns_geturl.n ns_gifsize.n ns_gmtime.n ns_guesstype.n \
		ns_headers.n ns_hostbyaddr.n ns_hrefs.n ns_html.n ns_http.n \
		ns_httptime.n ns_ictl.n ns_img.n ns_info.n ns_init.n ns_job.n \
		ns_jpegsize.n ns_kill.n ns_library.n ns_link.n ns_localtime.n \
		ns_log.n ns_logctl.n ns_logroll.n ns_markfordelete.n ns_mkdir.n \
		ns_mktemp.n ns_module.n ns_modulepath.n ns_mutex.n \
		ns_normalizepath.n ns_param.n ns_parseheader.n \
		ns_parsehttptime.n ns_parsequery.n ns_pause.n \
		ns_pooldescription.n ns_proc.n ns_purgefiles.n ns_puts.n \
		ns_quotehtml.n ns_quotelisttolist.n ns_rand.n ns_register_adp.n \
		ns_register_adptag.n ns_register_filter.n ns_register_proc.n \
		ns_register_trace.n ns_rename.n ns_requestauthorize.n \
		ns_respond.n ns_resume.n ns_return.n ns_returnadminnotice.n \
		ns_returnbadrequest.n ns_returnerror.n ns_returnfile.n \
		ns_returnforbidden.n ns_returnfp.n ns_returnnotfound.n \
		ns_returnnotice.n ns_returnredirect.n ns_returnunauthorized.n \
		ns_rmdir.n ns_rollfile.n ns_rwlock.n ns_sched.n \
		ns_schedule_daily.n ns_schedule_proc.n ns_schedule_weekly.n \
		ns_section.n ns_sema.n ns_server.n ns_set.n ns_share.n \
		ns_shutdown.n ns_sleep.n ns_sock.n ns_sockaccept.n \
		ns_sockblocking.n ns_sockcallback.n ns_sockcheck.n \
		ns_socketpair.n ns_socklisten.n ns_socklistencallback.n \
		ns_socknonblocking.n ns_socknread.n ns_sockopen.n \
		ns_sockselect.n ns_stats.n ns_striphtml.n ns_symlink.n \
		ns_sync.n ns_table.n ns_thread.n ns_time.n ns_tmp.n ns_tmpnam.n \
		ns_truncate.n ns_unlink.n ns_unregister_adp.n \
		ns_unregister_proc.n ns_unschedule_proc.n ns_url2file.n \
		ns_urldecode.n ns_urlencode.n ns_uudecode.n ns_uuencode.n \
		ns_var.n ns_write.n ns_writecontent.n ns_writefp.n nsv_append.n \
		nsv_array.n nsv_exists.n nsv_get.n nsv_incr.n nsv_lappend.n \
		nsv_names.n nsv_set.n nsv_unset.n

post-install:
	@ ${MKDIR} ${AOLSERVERBASE}/servers/server1/modules/nslog
	@ ${MKDIR} ${AOLSERVERBASE}/log
	@ ${ECHO} "Welcome. You have made it. Aolserver has started." >> ${AOLSERVERBASE}/servers/server1/pages/index.html

# Other documentation
.if !defined(NOPORTDOCS)
	@ ${ECHO} "Installing docs"
	@ ${MKDIR} ${DOCSDIR}
	@ ${TAR} -C ${WRKSRC} -c -f - ChangeLog README license.terms index.html | ${TAR} -C ${DOCSDIR} -x -f -
	@ ${TAR} -C ${WRKSRC}/tests -c -f - . | ${TAR} -C ${DOCSDIR} -x -f -
.endif

# Startup file
	@ ${ECHO} "Installing ${EXAMPLESDIR}/aolserver.sh.sample startup file."
	@ ${MKDIR} ${EXAMPLESDIR}
	@ if [ ! -f ${EXAMPLESDIR}/aolserver.sh.sample ]; then \
		${INSTALL_SCRIPT} ${WRKDIR}/aolserver.sh ${EXAMPLESDIR}/aolserver.sh.sample; \
	  fi

.if defined(WITH_NSCACHE)
	@ ${ECHO} "Installing nscache"
	@ cd ${WRKDIR}/nscache-1.5 && ${GMAKE} install AOLSERVER=${AOLSERVERBASE}
.endif

.if defined(WITH_NSSHA1)
	@ ${ECHO} "Installing nssha1"
	@ cd ${WRKDIR}/nssha1-0.1 && ${GMAKE} install AOLSERVER=${AOLSERVERBASE}
.endif

.if defined(WITH_ORACLE)
	@ ${ECHO} "Installing nsoracle"
	@ cd ${WRKDIR}/nsoracle-2.7 && ${GMAKE} install AOLSERVER=${AOLSERVERBASE}
.endif

.if defined(WITH_NSPOSTGRES)
	@ ${ECHO} "Installing nspostgres"
	@ cd ${WRKDIR}/nspostgres-4.0 && ${GMAKE} install AOLSERVER=${AOLSERVERBASE} POSTGRES=${LOCALBASE} ACS=1
.endif

# post-install script
	@ ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
