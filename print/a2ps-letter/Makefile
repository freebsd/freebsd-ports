# New ports collection makefile for:    a2ps
# Version required:     4.9.7
# Date created:         18 August 1997
# Whom:                 Chuck Robey (chuckr@freebsd.org)
#
# $Id: Makefile,v 1.10 1997/10/11 02:57:02 chuckr Exp $
#

DISTNAME=	a2ps
PKGNAME=	a2ps-${PAPERSIZE}-4.9.8
CATEGORIES=	print
MASTER_SITES=	http://www-inf.enst.fr/~demaille/ftp/a2ps/
DISTFILES=	a2ps-4.9.8.tar.gz

MAINTAINER=	chuckr@FreeBSD.org

MANUAL_PACKAGE_BUILD=	PAPERSIZE has to be set to Letter A4
WRKSRC=		$(WRKDIR)/$(DISTNAME)-4.9.8
GNU_CONFIGURE=	yes
MAN1=		a2ps.1 ogonkify.1

PAPERSIZE?=
STRIP=
CONFIGURE_ARGS=	--with-medium=$(PAPERSIZE)


Letter::
	$(MAKE) PAPERSIZE=Letter

letter::
	$(MAKE) PAPERSIZE=Letter

Letterdj::
	$(MAKE) PAPERSIZE=Letterdj

letterdj::
	$(MAKE) PAPERSIZE=Letterdj

A4::
	$(MAKE) PAPERSIZE=A4

a4::
	$(MAKE) PAPERSIZE=A4

pre-build:
	/usr/bin/touch $(WRKSRC)/doc/*.info
	/usr/bin/touch $(WRKSRC)/doc/*.dvi

pre-configure:
.if empty(PAPERSIZE)
	@echo
	@echo "PAPERSIZE not specified."
	@echo
	@echo "Must specify PAPERSIZE as one of A4, Letter, or Letterdj, either"
	@echo "using setenv, or via Makefile targets of the same name.  Note"
	@echo "that each PAPERSIZE has a leading capital letter, and Letterdj"
	@echo "allows a slightly larger margins for DeskJets."
	@false
.elif $(PAPERSIZE)!=A4 && $(PAPERSIZE)!=Letter && $(PAPERSIZE)!=Letterdj
	@echo
	@echo "PAPERSIZE incorrect value: $(PAPERSIZE)."
	@echo
	@echo "Must specify PAPERSIZE as one of A4, Letter, or Letterdj, either"
	@echo "using setenv, or via Makefile targets of the same name.  Note"
	@echo "that each PAPERSIZE has a leading capital letter, and Letterdj"
	@echo "allows a slightly larger margins for DeskJets."
	@false
.endif
	echo $(PAPERSIZE) > $(WRKDIR)/.media

.include <bsd.port.mk>

.if exists($(WRKDIR)/.media)
PAPERSIZE=
PAPERSIZE!=	cat $(WRKDIR)/.media
.endif
