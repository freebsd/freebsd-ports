# New ports collection makefile for:	lesstif
# Date created:		December 10, 1996
# Whom:			1wardd@airmail.net
#
# $FreeBSD$
#

PORTNAME=	lesstif
PORTVERSION=	0.91.8
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://twtelecom.dl.sourceforge.net/sourceforge/lesstif/ \
		http://umn.dl.sourceforge.net/sourceforge/lesstif/ \
		http://umn.dl.sourceforge.net/sourceforge/lesstif/ \
		http://gd.tuwien.ac.at/hci/lesstif/srcdist/ \
		ftp://linux.sarang.net/mirror/development/widget/lesstif/srcdist/

MAINTAINER=	ports@freebsd.org

PORTCOMMENT=	API compatible clone of the Motif toolkit

BUILD_DEPENDS=	${LOCALBASE}/bin/automake:${PORTSDIR}/devel/automake

MANUAL_PACKAGE_BUILD=	do not want to install during interactive build
USE_AUTOCONF=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	aclocal.m4 lib/Xbae/aclocal.m4 lib/Xlt/aclocal.m4 test/aclocal.m4
CONFIGURE_ARGS+=--enable-static --enable-shared --disable-build-Xlt \
		--enable-production --disable-debug --disable-build-Xbae

MAN1 =	lesstif.1 mwm.1 xmbind.1

MAN3 =	LessTifInternals.3 \
	XmArrowButton.3 \
	XmArrowButtonGadget.3 XmBulletinBoard.3 XmCascadeButton.3 \
	XmCascadeButtonGadget.3 XmClipboard.3 XmComboBox.3 XmCommand.3 \
	XmDesktop.3 XmDialogShell.3 XmDialogShellExt.3 XmDisplay.3 \
	XmDragContext.3 XmDragIcon.3 XmDragOverShell.3 XmDrawingArea.3 \
	XmDrawnButton.3 XmDropSiteManager.3 XmDropTransfer.3 \
	XmFileSelectionBox.3 XmForm.3 XmFrame.3 XmGadget.3 XmGrabShell.3 \
	XmIconGadget.3 XmLabel.3 XmLabelGadget.3 XmList.3 XmMainWindow.3 \
	XmManager.3 XmMenuShell.3 XmMessageBox.3 XmNotebook.3 \
	XmPanedWindow.3 XmPrimitive.3 XmProtocol.3 XmPushButton.3 \
	XmPushButtonGadget.3 XmRowColumn.3 XmSash.3 XmScale.3 XmScreen.3 \
	XmScrollBar.3 XmScrolledWindow.3 XmSelectionBox.3 XmSeparator.3 \
	XmSeparatorGadget.3 XmSpinBox.3 XmTearOffButton.3 XmText.3 \
	XmTextField.3 XmToggleButton.3 XmToggleButtonGadget.3 XmVendorShell.3 \
	XmWorld.3

MAN5 = mwmrc.5

.if defined(HAVE_MOTIF) && !defined(PARALLEL_PACKAGE_BUILD)
IS_INTERACTIVE= yes
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
	${RM} -f ${PREFIX}/LessTif/TODO
	${RM} -f ${PREFIX}/LessTif/INSTALL
	${RM} -rf ${PREFIX}/LessTif/doc
	${RM} -f ${PREFIX}/lib/libXm.so.2
	${RM} -f ${PREFIX}/lib/libXm.la
	${RM} -f ${PREFIX}/lib/libMrm.so.2
	${RM} -f ${PREFIX}/lib/libMrm.la
.if defined(MOTIF2)
	${LN} -sf ${PREFIX}/LessTif/Motif2.0/include/Xm ${PREFIX}/include
	${LN} -sf ${PREFIX}/LessTif/Motif2.0/include/Mrm ${PREFIX}/include
	${LN} -sf ${PREFIX}/LessTif/Motif2.0/lib/libXm.so.1 ${PREFIX}/lib/libXm.so.1
	${LN} -sf ${PREFIX}/lib/libXm.so.1 ${PREFIX}/lib/libXm.so
	${LN} -sf ${PREFIX}/LessTif/Motif2.0/lib/libXm.a ${PREFIX}/lib/libXm.a
	${LN} -sf ${PREFIX}/LessTif/Motif2.0/lib/libMrm.so.1 ${PREFIX}/lib/libMrm.so.1
	${LN} -sf ${PREFIX}/lib/libMrm.so.1 ${PREFIX}/lib/libMrm.so
	${LN} -sf ${PREFIX}/LessTif/Motif2.0/lib/libMrm.a ${PREFIX}/lib/libMrm.a
.else
	${LN} -sf ${PREFIX}/LessTif/Motif1.2/include/Xm ${PREFIX}/include
	${LN} -sf ${PREFIX}/LessTif/Motif1.2/include/Mrm ${PREFIX}/include
	${LN} -sf ${PREFIX}/LessTif/Motif1.2/lib/libXm.so.1 ${PREFIX}/lib/libXm.so.1
	${LN} -sf ${PREFIX}/lib/libXm.so.1 ${PREFIX}/lib/libXm.so
	${LN} -sf ${PREFIX}/LessTif/Motif1.2/lib/libXm.a ${PREFIX}/lib/libXm.a
	${LN} -sf ${PREFIX}/LessTif/Motif1.2/lib/libMrm.so.1 ${PREFIX}/lib/libMrm.so.1
	${LN} -sf ${PREFIX}/lib/libMrm.so.1 ${PREFIX}/lib/libMrm.so
	${LN} -sf ${PREFIX}/LessTif/Motif1.2/lib/libMrm.a ${PREFIX}/lib/libMrm.a
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
