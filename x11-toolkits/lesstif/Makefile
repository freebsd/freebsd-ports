# New ports collection makefile for:	lesstif
# Date created:		December 10, 1996
# Whom:			1wardd@airmail.net
#
# $FreeBSD$
#

PORTNAME=	lesstif
PORTVERSION=	0.94.2
PORTEPOCH=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lesstif

MAINTAINER=	ports@freebsd.org
COMMENT=	API compatible clone of the Motif toolkit

LIB_DEPENDS=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

CONFLICTS?=	open-motif-*
MANUAL_PACKAGE_BUILD=	do not want to install during interactive build
WANT_AUTOMAKE_VER=	19
USE_AUTOCONF_VER=	259
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
USE_INC_LIBTOOL_VER=	15
LIBTOOLFILES=	aclocal.m4 test/aclocal.m4
CONFIGURE_ARGS+=	--enable-static --enable-shared --enable-production
CONFIGURE_ARGS+=	--disable-maintainer-mode
CFLAGS+=	-I${X11BASE}/include

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

.if defined(HAVE_MOTIF) && !defined(PARALLEL_PACKAGE_BUILD) && !defined(WANT_LESSTIF)
IS_INTERACTIVE=	yes
pre-extract:
	@${ECHO_CMD} "***********************************************************"
	@${ECHO_CMD} "*                      W a r n i n g                      *"
	@${ECHO_CMD} "*    This port will overwrite your Motif installation.    *"
	@${ECHO_CMD} "***********************************************************"
	@${ECHO_CMD} -n "Is this ok? (y/n) ==> "
	@(read ans; \
	  case x"$$ans" in \
	    xy*|xY*) \
		return 0; \
		;; \
	    *) \
		${ECHO_CMD} "Okay, I won't install it then...."; \
		${ECHO_CMD} "(Don't worry about the following \"*** Error code 1's)"; \
		return 1; \
		;; \
	esac)
.endif

post-install:
	${RM} -f ${PREFIX}/lib/libXm.la
	${RM} -f ${PREFIX}/lib/libMrm.la
	${RM} -f ${PREFIX}/lib/libDtPrint.la
	${RM} -f ${PREFIX}/lib/libUil.la
	${INSTALL_DATA} ${WRKSRC}/scripts/autoconf/ac_find_motif.m4 \
		${LOCALBASE}/share/aclocal
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
PLIST_SUB+=	FREEBSD5=""
.else
PLIST_SUB+=	FREEBSD5="@comment "
.endif

.include <bsd.port.post.mk>
