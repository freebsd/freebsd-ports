# New ports collection makefile for: 	bwidget
# Date created:				Jan 29, 2002
# Whom:					Alexander Kabaev <ak03@gte.com>
#
# $FreeBSD$
#

PORTNAME=		bwidget
PORTVERSION=		1.3.1
CATEGORIES=		x11-toolkits
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tcllib
DISTNAME=		BWidget-${PORTVERSION}

MAINTAINER=		ports@FreeBSD.ORG

NO_BUILD=		yes
PLIST_SUB+=		PORTVERSION=${PORTVERSION}

BWIDGET_SOURCES = \
	arrow.tcl \
	bitmap.tcl \
	button.tcl \
	buttonbox.tcl \
	color.tcl \
	combobox.tcl \
	dialog.tcl \
	dragsite.tcl \
	dropsite.tcl \
	dynhelp.tcl \
	entry.tcl \
	font.tcl \
	init.tcl \
	label.tcl \
	labelentry.tcl \
	labelframe.tcl \
	listbox.tcl \
	mainframe.tcl \
	messagedlg.tcl \
	notebook.tcl \
	pagesmgr.tcl \
	panedw.tcl \
	passwddlg.tcl \
	pkgIndex.tcl \
	progressbar.tcl \
	progressdlg.tcl \
	scrollframe.tcl \
	scrollview.tcl \
	scrollw.tcl \
	separator.tcl \
	spinbox.tcl \
	titleframe.tcl \
	tree.tcl \
	utils.tcl \
	widget.tcl \
	xpm2image.tcl

PKGLIBDIR = ${PREFIX}/lib/${PORTNAME}${PORTVERSION}
DOCDIR =    ${PREFIX}/share/doc/${PORTNAME}${PORTVERSION}

do-install:
	@${ECHO_MSG} "Installing script files in $(PKGLIBDIR)"
	@$(MKDIR) $(PKGLIBDIR)
	@for i in $(BWIDGET_SOURCES) ; do \
	    $(INSTALL_DATA) $(WRKSRC)/$$i $(PKGLIBDIR) ; \
	done;
	@${ECHO_MSG} "Installing language files in $(PKGLIBDIR)/lang"
	@$(MKDIR) $(PKGLIBDIR)/lang
	@for i in $(WRKSRC)/lang/*.rc ; do \
	    $(INSTALL_DATA) $$i $(PKGLIBDIR)/lang ; \
	done;
	@${ECHO_MSG} "Installing image files in $(PKGLIBDIR)/images"
	@$(MKDIR) $(PKGLIBDIR)/images
	@for i in $(WRKSRC)/images/*.gif $(WRKSRC)/images/*.xbm ; do \
	    $(INSTALL_DATA) $$i $(PKGLIBDIR)/images ; \
	done;
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "Installing html documentation in $(DOCDIR)"
	@$(MKDIR) $(DOCDIR)
	@for i in $(WRKSRC)/BWman/*.html $(WRKSRC)/BWman/*.htm ; do \
	    $(INSTALL_DATA) $$i $(DOCDIR) ; \
	done;
.endif

.include <bsd.port.mk>
