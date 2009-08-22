# New ports collection makefile for:    itk
# Date created:         Aug 17 1996
# Whom:                 chuckr
#
# $FreeBSD$
#

PORTNAME=	iwidgets
PORTVERSION=	4.0.1
PORTREVISION=	1
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	SF/incrtcl/%5BIncr%20Widgets%5D/${PORTVERSION}
DISTNAME=	iwidgets${PORTVERSION}

MAINTAINER=	pauls@utdallas.edu
COMMENT=	Iwidgets - [incr Widgets]

LIB_DEPENDS=	itk:${PORTSDIR}/x11-toolkits/itk

NO_BUILD=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-tcl=${LOCALBASE}/lib/tcl8.4 \
		--with-tk=${LOCALBASE}/lib/tk8.4 \
		--with-itcl=${LOCALBASE}/lib/itcl3.3
SUB_LIST=	IWIDGETS=${DISTNAME}
SUB_FILES=	pkg-message
PLIST_SUB=	IWIDGETS=${DISTNAME}

PORTDOCS=	CHANGES ChangeLog README iwidgets.ps

MANN=	iwidgets_buttonbox.n iwidgets_calendar.n iwidgets_canvasprintbox.n iwidgets_canvasprintdialog.n \
	iwidgets_checkbox.n iwidgets_combobox.n iwidgets_dateentry.n iwidgets_datefield.n iwidgets_dialog.n \
	iwidgets_dialogshell.n iwidgets_disjointlistbox.n iwidgets_entryfield.n iwidgets_extbutton.n \
	iwidgets_extfileselectionbox.n iwidgets_extfileselectiondialog.n iwidgets_feedback.n \
	iwidgets_fileselectionbox.n iwidgets_fileselectiondialog.n iwidgets_finddialog.n iwidgets_hierarchy.n \
	iwidgets_hyperhelp.n iwidgets_labeledframe.n iwidgets_labeledwidget.n iwidgets_mainwindow.n \
	iwidgets_menubar.n iwidgets_messagebox.n iwidgets_messagedialog.n iwidgets_notebook.n \
	iwidgets_optionmenu.n iwidgets_panedwindow.n iwidgets_promptdialog.n iwidgets_pushbutton.n \
	iwidgets_radiobox.n iwidgets_scopedobject.n iwidgets_scrolledcanvas.n iwidgets_scrolledframe.n \
	iwidgets_scrolledhtml.n iwidgets_scrolledlistbox.n iwidgets_scrolledtext.n iwidgets_selectionbox.n \
	iwidgets_selectiondialog.n iwidgets_shell.n iwidgets_spindate.n iwidgets_spinint.n iwidgets_spinner.n \
	iwidgets_spintime.n iwidgets_tabnotebook.n iwidgets_tabset.n iwidgets_timeentry.n iwidgets_timefield.n \
	iwidgets_toolbar.n iwidgets_watch.n

post-patch:
	${REINPLACE_CMD} -e 's,^MKINSTALLDIRS =.*,MKINSTALLDIRS=${MKDIR},' \
		-e 's,^INSTALL =.*,INSTALL=${INSTALL} -c,' \
		-e 's,^INSTALL_PROGRAM =.*,INSTALL_PROGRAM=${INSTALL_PROGRAM},' \
		-e 's,^INSTALL_DATA =.*,INSTALL_DATA=${INSTALL_DATA},' \
		-e 's,^INSTALL_SCRIPT =.*,INSTALL_SCRIPT=${INSTALL_SCRIPT},' \
		-e 's,@ITCL_VERSION@,3.3,g' ${WRKSRC}/Makefile.in

post-install:

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/iwidgets.ps ${DOCSDIR}
.for f in CHANGES ChangeLog README
	${INSTALL_MAN} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
