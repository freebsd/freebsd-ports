# New ports collection makefile for:	lesstif
# Date created:		December 10, 1996
# Whom:			1wardd@airmail.net
#
# $FreeBSD$
#

PORTNAME=	lesstif
PORTVERSION=	0.95.2
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	API compatible clone of the Motif toolkit

LIB_DEPENDS=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		freetype.9:${PORTSDIR}/print/freetype2

CONFLICTS?=	open-motif-*
USE_BZIP2=	yes
USE_AUTOTOOLS=	automake:19:env autoconf:262 libtool:22
USE_XORG=	sm ice xt xp xext x11 xextproto xrender xft
USE_LDCONFIG=	yes
LIBTOOLFILES=	aclocal.m4 test/aclocal.m4
CONFIGURE_ARGS+=	--enable-static --enable-shared --enable-production
CONFIGURE_ARGS+=	--disable-maintainer-mode
CFLAGS+=	-I${LOCALBASE}/include

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

.if defined(HAVE_MOTIF) && !defined(PACKAGE_BUILDING) && !defined(BATCH) && !defined(WANT_LESSTIF)
MANUAL_PACKAGE_BUILD=	do not want to install during interactive build
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

post-patch:
	${REINPLACE_CMD} \
		-e 's|LT_HAVE_FREETYPE|FINDXFT_HAVE_FREETYPE|g' \
		-e 's|LT_HAVE_XRENDER|FINDXFT_HAVE_XRENDER|g' \
		${WRKSRC}/acinclude.m4

post-install:
	@${INSTALL_DATA} ${WRKSRC}/scripts/autoconf/ac_find_motif.m4 \
		${PREFIX}/share/aclocal
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
