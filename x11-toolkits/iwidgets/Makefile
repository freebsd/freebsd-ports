# New ports collection makefile for:	itk
# Date created:		Aug 17 1996
# Whom:			chuckr
#
# $FreeBSD$
#

PORTNAME=	iwidgets
PORTVERSION=	3.0.0
CATEGORIES=	x11-toolkits tk82
MASTER_SITES=	ftp://ftp.tcltk.com/pub/itcl/
DISTNAME=	itcl3.0.1

MAINTAINER=	dmlb@ragnet.demon.co.uk

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82 \
		itcl30.1:${PORTSDIR}/lang/itcl \
		itk30.1:${PORTSDIR}/x11-toolkits/itk

WRKSRC=		${WRKDIR}/itcl3.0.1/iwidgets3.0.0/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${PREFIX}/lib/tcl8.2 --with-itcl=${PREFIX}/lib/itcl3.0 --with-tk=${PREFIX}/lib/tk8.2 --with-itk=${PREFIX}/lib/itk3.0
CONFIGURE_ENV=	PORTSDIR=${PORTSDIR}

MANN=		buttonbox.n calendar.n canvasprintbox.n canvasprintdialog.n \
		checkbox.n combobox.n dateentry.n datefield.n dialog.n \
		dialogshell.n disjointlistbox.n entryfield.n \
		extfileselectionbox.n extfileselectiondialog.n feedback.n \
		fileselectionbox.n fileselectiondialog.n finddialog.n \
		hierarchy.n hyperhelp.n labeledframe.n labeledwidget.n \
		mainwindow.n menubar.n messagebox.n messagedialog.n \
		notebook.n optionmenu.n panedwindow.n promptdialog.n \
		pushbutton.n radiobox.n scopedobject.n scrolledcanvas.n \
		scrolledframe.n scrolledhtml.n shell.n scrolledlistbox.n \
		scrolledtext.n selectionbox.n selectiondialog.n spindate.n \
		spinint.n spinner.n spintime.n tabnotebook.n tabset.n \
		timeentry.n timefield.n toolbar.n watch.n

.include <bsd.port.mk>
