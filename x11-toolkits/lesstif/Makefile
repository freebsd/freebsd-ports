# New ports collection makefile for:	lesstif
# Date created:		December 10, 1996
# Whom:			1wardd@airmail.net
#
# $FreeBSD$
#

PORTNAME=	lesstif
PORTVERSION=	0.93.36
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://twtelecom.dl.sourceforge.net/sourceforge/lesstif/ \
		http://umn.dl.sourceforge.net/sourceforge/lesstif/ \
		http://umn.dl.sourceforge.net/sourceforge/lesstif/ \
		http://gd.tuwien.ac.at/hci/lesstif/srcdist/ \
		ftp://linux.sarang.net/mirror/development/widget/lesstif/srcdist/

MAINTAINER=	dinoex@freebsd.org

BUILD_DEPENDS=	${LOCALBASE}/bin/automake:${PORTSDIR}/devel/automake

MANUAL_PACKAGE_BUILD=	do not want to install during interactive build
WANT_AUTOCONF_VER=	253
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	aclocal.m4 test/aclocal.m4
CONFIGURE_ARGS+=	--enable-static --enable-shared --enable-production
CONFIGURE_ARGS+=	--disable-build-Xlt --disable-build-Xbae
CONFIGURE_ARGS+=	--enable-build-12 --disable-build-20
CONFIGURE_ARGS+=	--enable-build-21 --enable-default-21
CONFIGURE_ARGS+=	--disable-maintainer-mode

MAN1 =	lesstif.1 ltversion.1 mwm.1 uil.1 xmbind.1

MAN3 =	ApplicationShell.3 Composite.3 Constraint.3 Core.3 \
	LessTifInternals.3 Object.3 OverrideShell.3 Rect.3 Shell.3 \
	TopLevelShell.3 TransientShell.3 UnNamedObj.3 VendorShell.3 \
	WmShell.3 XmArrowButton.3 XmArrowButtonGadget.3 XmBulletinBoard.3 \
	XmCascadeButton.3 XmCascadeButtonGadget.3 XmClipboard.3 \
	XmComboBox.3 XmCommand.3 XmDesktop.3 XmDialogShell.3 \
	XmDialogShellExt.3 XmDisplay.3 XmDragContext.3 XmDragIcon.3 \
	XmDragOverShell.3 XmDrawingArea.3 XmDrawnButton.3 XmDropSiteManager.3 \
	XmDropTransfer.3 XmFileSelectionBox.3 XmForm.3 XmFrame.3 XmGadget.3 \
	XmGrabShell.3 XmIconGadget.3 XmLabel.3 XmLabelGadget.3 XmList.3 \
	XmMainWindow.3 XmManager.3 XmMenuShell.3 XmMessageBox.3 XmNotebook.3 \
	XmPanedWindow.3 XmPrimitive.3 XmProtocol.3 XmPushButton.3 \
	XmPushButtonGadget.3 XmRowColumn.3 XmSash.3 XmScale.3 XmScreen.3 \
	XmScrollBar.3 XmScrolledWindow.3 XmSelectionBox.3 XmSeparator.3 \
	XmSeparatorGadget.3 XmSpinBox.3 XmString.3 XmTearOffButton.3 XmText.3 \
	XmTextField.3 XmToggleButton.3 XmToggleButtonGadget.3 XmVendorShell.3 \
	XmWorld.3

MAN5 =	VirtualBindings.5 mwmrc.5

.if defined(HAVE_MOTIF) && !defined(PARALLEL_PACKAGE_BUILD)
IS_INTERACTIVE=	yes
pre-extract:
	@${ECHO} "***********************************************************"
	@${ECHO} "*                      W a r n i n g                      *"
	@${ECHO} "*    This port will overwrite your Motif installation.    *"
	@${ECHO} "***********************************************************"
	@${ECHO} -n "Is this ok? (y/n) ==> "
	@(read ans; \
	  case x"$$ans" in \
	    xy*|xY*) \
		return 0; \
		;; \
	    *) \
		${ECHO} "Okay, I won't install it then...."; \
		${ECHO} "(Don't worry about the following \"*** Error code 1's)"; \
		return 1; \
		;; \
	esac)
.endif

post-install:
	${RM} -f ${PREFIX}/lib/libXm.la
	${RM} -f ${PREFIX}/lib/libMrm.la
	${RM} -f ${PREFIX}/lib/libDtPrint.la
	${RM} -f ${PREFIX}/lib/libUil.la
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
