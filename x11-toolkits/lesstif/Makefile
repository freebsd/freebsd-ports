# New ports collection makefile for:	lesstif
# Version required:	0.87.1
# Date created:		December 10, 1996
# Whom:			1wardd@airmail.net
#
# $Id: Makefile,v 1.28 1998/12/01 09:35:13 obrien Exp $
#

DISTNAME=	lesstif-0.87.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.lesstif.org/pub/hungry/lesstif/srcdist/  \
		ftp://ftp.hungry.com/pub/hungry/lesstif/srcdist/ \
		ftp://ftp.fu-berlin.de/unix/X11/gui/lesstif/srcdist/ \
		ftp://ftp.win.or.jp/pub/X11/misc/lesstif/srcdist/

MAINTAINER=	ports@FreeBSD.org

#	see below for shared lib version information

MANUAL_PACKAGE_BUILD=	do not want to install during interactive build
GNU_CONFIGURE=  yes
# comment this and remove the strip statement in post-install for debugging
CONFIGURE_ARGS=	--disable-debug
# I don't want to change the shared lib major version number right now.
CONFIGURE_ARGS+=	--enable-back-compat  --enable-static --enable-shared
USE_X_PREFIX=	yes

MAN1=	mwm.1 xmbind.1 lesstif.1
MAN3=	XmClipboard.3 LessTifInternals.3 \
	XmArrowButton.3 XmArrowButtonGadget.3 XmBulletinBoard.3 \
	XmCascadeButton.3 XmCascadeButtonGadget.3 \
	XmComboBox.3 XmCommand.3 XmDesktop.3 \
	XmDialogShell.3 XmDialogShellExt.3 XmDisplay.3 \
	XmDragContext.3 XmDragIcon.3 XmDragOverShell.3 \
	XmDrawingArea.3 XmDrawnButton.3 XmDropSiteManager.3 \
	XmDropTransfer.3 XmFileSelectionBox.3 XmForm.3 \
	XmFrame.3 XmGadget.3 XmGrabShell.3 \
	XmIconGadget.3 XmLabel.3 \
	XmLabelGadget.3 XmList.3 \
	XmMainWindow.3 XmManager.3 XmMenuShell.3 \
	XmMessageBox.3 XmNotebook.3 XmPanedWindow.3 \
	XmPrimitive.3 XmProtocol.3 XmPushButton.3 \
	XmPushButtonGadget.3 XmRowColumn.3 \
	XmSash.3 XmScale.3 XmScreen.3 \
	XmScrollBar.3 XmScrolledWindow.3 XmSelectionBox.3 \
	XmSeparator.3 XmSeparatorGadget.3 \
	XmSpinBox.3 XmTearOffButton.3 XmText.3 \
	XmTextField.3 XmToggleButton.3 \
	XmToggleButtonGadget.3 XmVendorShellExt.3 XmWorld.3 \
	ApplicationShell.3 Composite.3 Constraint.3 Core.3 Object.3 \
	OverrideShell.3 Rect.3 Shell.3 TopLevelShell.3 \
	TransientShell.3 UnNamedObj.3 WmShell.3 XtConfigureObject.3 \
	XtDestroyWidget.3 XtManageChild.3 XtUnmanageChild.3
MAN5=	mwmrc.5

.if defined(HAVE_MOTIF)
IS_INTERACTIVE=	yes
pre-extract:
	@${ECHO} "***********************************************************"
	@${ECHO} "*                      W a r n i n g                      *"
	@${ECHO} "* This port will overwrite your Motif installation.       *"
	@${ECHO} "***********************************************************"
	@${ECHO} -n "Is this ok? (y/n) ==> "
	@(read ans; \
	  case x"$$ans" in \
	    xy*|xY*) \
	        return 0; \
	        ;; \
	    *) \
	        ${ECHO} "Okay, I won't install it then...."; \
	        ${ECHO} "(Don't worry about the following \"*** Error code 1\"s)"; \
	        return 1; \
	        ;; \
	  esac)
.endif

post-install:
	${MKDIR} ${PREFIX}/lib/X11/mwm ${PREFIX}/lib/X11/app-defaults
	${INSTALL_DATA} ${WRKSRC}/clients/Motif-1.2/mwm/system.mwmrc \
		${PREFIX}/lib/X11/mwm
	${INSTALL_DATA} ${WRKSRC}/clients/Motif-1.2/mwm/alt.map ${PREFIX}/lib/X11/mwm
	${INSTALL_DATA} ${WRKSRC}/clients/Motif-1.2/mwm/Mwm \
		${PREFIX}/lib/X11/app-defaults/Mwm
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>

#	Shared lib versions
#	dist version		BSD shared lib version
#	------------		----------------------
#	0.78			0.0
#	0.79			0.1
#	0.80			0.1
#       0.83			1.2
