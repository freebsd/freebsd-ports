# New ports collection makefile for:	itk
# Date created:		Aug 17 1996
# Whom:			chuckr
#
# $FreeBSD$
#

PORTNAME=	iwidgets
PORTVERSION=	3.2
CATEGORIES=	x11-toolkits tk83
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=incrtcl
DISTNAME=	itcl3.2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	[incr Widgets] (A.K.A. "iwidgets")

LIB_DEPENDS=	itk32.1:${PORTSDIR}/x11-toolkits/itk

EXTRACT_AFTER_ARGS=| ${TAR} -xf - ./itcl3.2/iwidgets\*
NO_BUILD=	yes

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

# Install both versions of iwidgets, but only the
# latest version of man-pages:
do-install:
.for d in iwidgets3.0.0 iwidgets2.2.0
	${MKDIR} ${PREFIX}/lib/$d/scripts/ ${PREFIX}/lib/$d/demos/images/
	${INSTALL_DATA} ${WRKSRC}/$d/generic/* ${PREFIX}/lib/$d/scripts/
	${INSTALL_DATA} ${WRKSRC}/$d/*.tcl ${PREFIX}/lib/$d/
# Everything, but the html:
	${INSTALL_DATA} `${GREP} -Fl 'package require' ${WRKSRC}/$d/demos/*` \
		${WRKSRC}/$d/demos/*.* ${PREFIX}/lib/$d/demos/
	${INSTALL_DATA} ${WRKSRC}/$d/demos/images/* \
		${PREFIX}/lib/$d/demos/images/
.endfor
	${INSTALL_MAN} ${WRKSRC}/iwidgets3.0.0/doc/*.n ${PREFIX}/man/mann/

.include <bsd.port.mk>
