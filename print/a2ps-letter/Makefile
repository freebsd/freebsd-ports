# New ports collection makefile for:    a2ps
# Version required:     4.9.9
# Date created:         18 August 1997
# Whom:                 Chuck Robey (chuckr@freebsd.org)
#
# $Id: Makefile,v 1.11 1997/11/10 11:23:14 asami Exp $
#

DISTNAME=	a2ps-4.9.9
PKGNAME=	a2ps-${PAPERSIZE}-4.9.9
CATEGORIES=	print
MASTER_SITES=	http://www-inf.enst.fr/~demaille/ftp/a2ps/

MAINTAINER=	chuckr@FreeBSD.org

MANUAL_PACKAGE_BUILD=	PAPERSIZE has to be set to Letter A4
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
	${TOUCH} $(WRKSRC)/doc/*.info
	${TOUCH} $(WRKSRC)/doc/*.dvi

pre-configure:
.if empty(PAPERSIZE)
	@${ECHO}
	@${ECHO} "PAPERSIZE not specified."
	@${ECHO}
	@${ECHO} "Must specify PAPERSIZE as one of A4, Letter, or Letterdj, either"
	@${ECHO} "using setenv, or via Makefile targets of the same name.  Note"
	@${ECHO} "that each PAPERSIZE has a leading capital letter, and Letterdj"
	@${ECHO} "allows a slightly larger margins for DeskJets."
	@false
.elif $(PAPERSIZE)!=A4 && $(PAPERSIZE)!=Letter && $(PAPERSIZE)!=Letterdj
	@${ECHO}
	@${ECHO} "PAPERSIZE incorrect value: $(PAPERSIZE)."
	@${ECHO}
	@${ECHO} "Must specify PAPERSIZE as one of A4, Letter, or Letterdj, either"
	@${ECHO} "using setenv, or via Makefile targets of the same name.  Note"
	@${ECHO} "that each PAPERSIZE has a leading capital letter, and Letterdj"
	@${ECHO} "allows a slightly larger margins for DeskJets."
	@false
.endif
	${ECHO} $(PAPERSIZE) > $(WRKDIR)/.media

.include <bsd.port.mk>

.if exists($(WRKDIR)/.media)
PAPERSIZE=
PAPERSIZE!=	${CAT} $(WRKDIR)/.media
.endif
