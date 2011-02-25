# New ports collection makefile for:   libXt
# Date Created:			25 Jan, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libXt
PORTVERSION=	1.0.9
CATEGORIES=	x11-toolkits

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Toolkit library

XORG_CAT=	lib
USE_XORG=	x11 sm xproto:both kbproto

MAN3=	MenuPopdown.3 \
	MenuPopup.3 \
	XtAddActions.3 \
	XtAddCallback.3 \
	XtAddCallbacks.3 \
	XtAddConverter.3 \
	XtAddEventHandler.3 \
	XtAddExposureToRegion.3 \
	XtAddGrab.3 \
	XtAddInput.3 \
	XtAddRawEventHandler.3 \
	XtAddTimeOut.3 \
	XtAddWorkProc.3 \
	XtAllocateGC.3 \
	XtAppAddActionHook.3 \
	XtAppAddActions.3 \
	XtAppAddBlockHook.3 \
	XtAppAddConverter.3 \
	XtAppAddInput.3 \
	XtAppAddSignal.3 \
	XtAppAddTimeOut.3 \
	XtAppAddWorkProc.3 \
	XtAppCreateShell.3 \
	XtAppError.3 \
	XtAppErrorMsg.3 \
	XtAppGetErrorDatabase.3 \
	XtAppGetErrorDatabaseText.3 \
	XtAppGetExitFlag.3 \
	XtAppGetSelectionTimeout.3 \
	XtAppInitialize.3 \
	XtAppLock.3 \
	XtAppMainLoop.3 \
	XtAppNextEvent.3 \
	XtAppPeekEvent.3 \
	XtAppPending.3 \
	XtAppProcessEvent.3 \
	XtAppReleaseCacheRefs.3 \
	XtAppSetErrorHandler.3 \
	XtAppSetErrorMsgHandler.3 \
	XtAppSetExitFlag.3 \
	XtAppSetFallbackResources.3 \
	XtAppSetSelectionTimeout.3 \
	XtAppSetTypeConverter.3 \
	XtAppSetWarningHandler.3 \
	XtAppSetWarningMsgHandler.3 \
	XtAppUnlock.3 \
	XtAppWarning.3 \
	XtAppWarningMsg.3 \
	XtAugmentTranslations.3 \
	XtBuildEventMask.3 \
	XtCallAcceptFocus.3\
	XtCallActionProc.3 \
	XtCallCallbackList.3 \
	XtCallCallbacks.3 \
	XtCallConverter.3 \
	XtCallbackExclusive.3 \
	XtCallbackNone.3 \
	XtCallbackNonexclusive.3 \
	XtCallbackPopdown.3 \
	XtCalloc.3 \
	XtCancelSelectionRequest.3 \
	XtChangeManagedSet.3 \
	XtCheckSubclass.3 \
	XtClass.3\
	XtCloseDisplay.3\
	XtConfigureWidget.3\
	XtConvert.3\
	XtConvertAndStore.3\
	XtConvertCase.3\
	XtCreateApplicationContext.3\
	XtCreateApplicationShell.3\
	XtCreateManagedWidget.3\
	XtCreatePopupShell.3\
	XtCreateSelectionRequest.3\
	XtCreateWidget.3\
	XtCreateWindow.3\
	XtDatabase.3\
	XtDestroyApplicationContext.3\
	XtDestroyWidget.3\
	XtDirectConvert.3\
	XtDisownSelection.3 \
	XtDispatchEvent.3  \
	XtDispatchEventToWidget.3\
	XtDisplay.3\
	XtDisplayInitialize.3\
	XtDisplayOfObject.3\
	XtDisplayStringConversionWarning.3\
	XtDisplayToApplicationContext.3\
	XtError.3\
	XtErrorMsg.3\
	XtFindFile.3\
	XtFree.3\
	XtGetActionKeysym.3\
	XtGetActionList.3\
	XtGetApplicationNameAndClass.3\
	XtGetApplicationResources.3\
	XtGetClassExtension.3\
	XtGetConstraintResourceList.3\
	XtGetDisplays.3\
	XtGetErrorDatabase.3\
	XtGetErrorDatabaseText.3\
	XtGetGC.3\
	XtGetKeyboardFocusWidget.3\
	XtGetKeysymTable.3\
	XtGetMultiClickTime.3 \
	XtGetResourceList.3\
	XtGetSelectionParameters.3\
	XtGetSelectionRequest.3\
	XtGetSelectionTimeout.3\
	XtGetSelectionValue.3\
	XtGetSelectionValueIncremental.3 \
	XtGetSelectionValues.3\
	XtGetSelectionValuesIncremental.3 \
	XtGetSubresources.3 \
	XtGetSubvalues.3 \
	XtGetValues.3 \
	XtGrabButton.3 \
	XtGrabKey.3 \
	XtGrabKeyboard.3 \
	XtGrabPointer.3 \
	XtHasCallbacks.3 \
	XtHooksOfDisplay.3 \
	XtInitialize.3 \
	XtInitializeWidgetClass.3 \
	XtInsertEventHandler.3 \
	XtInsertEventTypeHandler.3 \
	XtInsertRawEventHandler.3 \
	XtInstallAccelerators.3\
	XtInstallAllAccelerators.3\
	XtIsApplicationShell.3\
	XtIsComposite.3\
	XtIsConstraint.3\
	XtIsManaged.3\
	XtIsObject.3\
	XtIsOverrideShell.3\
	XtIsRealized.3\
	XtIsRectObj.3\
	XtIsSensitive.3\
	XtIsSessionShell.3\
	XtIsShell.3\
	XtIsSubclass.3\
	XtIsTopLevelShell.3\
	XtIsTransientShell.3\
	XtIsVendorShell.3\
	XtIsWMShell.3\
	XtIsWidget.3\
	XtKeysymToKeycodeList.3\
	XtLastEventProcessed.3\
	XtLastTimestampProcessed.3 \
	XtMainLoop.3 \
	XtMakeGeometryRequest.3 \
	XtMakeResizeRequest.3 \
	XtMalloc.3 \
	XtManageChild.3 \
	XtManageChildren.3 \
	XtMapWidget.3 \
	XtMergeArgLists.3 \
	XtMoveWidget.3 \
	XtName.3 \
	XtNameToWidget.3 \
	XtNew.3 \
	XtNewString.3 \
	XtNextEvent.3 \
	XtNoticeSignal.3 \
	XtNumber.3 \
	XtOffset.3 \
	XtOffsetOf.3 \
	XtOpenApplication.3 \
	XtOpenDisplay.3 \
	XtOverrideTranslations.3 \
	XtOwnSelection.3 \
	XtOwnSelectionIncremental.3 \
	XtParent.3 \
	XtParseAcceleratorTable.3 \
	XtParseTranslationTable.3 \
	XtPeekEvent.3 \
	XtPending.3 \
	XtPopdown.3 \
	XtPopup.3 \
	XtPopupSpringLoaded.3 \
	XtProcessEvent.3 \
	XtProcessLock.3 \
	XtProcessUnlock.3 \
	XtQueryGeometry.3 \
	XtRealizeWidget.3 \
	XtRealloc.3 \
	XtRegisterCaseConverter.3 \
	XtRegisterDrawable.3 \
	XtRegisterExtensionSelector.3 \
	XtRegisterGrabAction.3 \
	XtReleaseGC.3 \
	XtReleasePropertyAtom.3 \
	XtRemoveActionHook.3 \
	XtRemoveAllCallbacks.3 \
	XtRemoveBlockHook.3 \
	XtRemoveCallback.3 \
	XtRemoveCallbacks.3 \
	XtRemoveEventHandler.3\
	XtRemoveEventTypeHandler.3\
	XtRemoveGrab.3\
	XtRemoveInput.3\
	XtRemoveRawEventHandler.3\
	XtRemoveSignal.3\
	XtRemoveTimeOut.3\
	XtRemoveWorkProc.3\
	XtReservePropertyAtom.3\
	XtResizeWidget.3\
	XtResolvePathname.3\
	XtScreen.3\
	XtScreenDatabase.3\
	XtScreenOfObject.3\
	XtSendSelectionRequest.3\
	XtSessionGetToken.3\
	XtSessionReturnToken.3\
	XtSetArg.3\
	XtSetErrorHandler.3\
	XtSetErrorMsgHandler.3\
	XtSetEventDispatcher.3\
	XtSetKeyTranslator.3\
	XtSetKeyboardFocus.3\
	XtSetLanguageProc.3 \
	XtSetMappedWhenManaged.3 \
	XtSetMultiClickTime.3 \
	XtSetSelectionParameters.3 \
	XtSetSelectionTimeout.3 \
	XtSetSensitive.3 \
	XtSetSubvalues.3 \
	XtSetTypeConverter.3 \
	XtSetValues.3 \
	XtSetWMColormapWindows.3 \
	XtSetWarningHandler.3 \
	XtSetWarningMsgHandler.3\
	XtStringConversionWarning.3\
	XtSuperclass.3\
	XtToolkitInitialize.3\
	XtToolkitThreadInitialize.3\
	XtTranslateCoords.3 \
	XtTranslateKeycode.3\
	XtUngrabButton.3\
	XtUngrabKey.3\
	XtUngrabKeyboard.3\
	XtUngrabPointer.3\
	XtUninstallTranslations.3\
	XtUnmanageChild.3\
	XtUnmanageChildren.3\
	XtUnmapWidget.3\
	XtUnrealizeWidget.3\
	XtUnregisterDrawable.3\
	XtVaAppCreateShell.3\
	XtVaAppInitialize.3\
	XtVaCreateArgsList.3\
	XtVaCreateManagedWidget.3\
	XtVaCreatePopupShell.3\
	XtVaCreateWidget.3\
	XtVaGetApplicationResources.3\
	XtVaGetSubresources.3\
	XtVaGetSubvalues.3 \
	XtVaGetValues.3 \
	XtVaOpenApplication.3\
	XtVaSetSubvalues.3\
	XtVaSetValues.3\
	XtWarning.3 \
	XtWarningMsg.3\
	XtWidgetToApplicationContext.3\
	XtWindow.3 \
	XtWindowOfObject.3 \
	XtWindowToWidget.3

.include <bsd.port.mk>
