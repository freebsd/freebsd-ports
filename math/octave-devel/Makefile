# New ports collection makefile for:	octave
# Version required:	2.0.13
# Date created:		8 September 1998
# Whom:			chuckr@freebsd.org
#
# $Id: Makefile,v 1.17 1998/09/09 05:46:15 asami Exp $
#

DISTNAME=	octave-2.0.13
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.che.wisc.edu/pub/octave/

MAINTAINER=	chuckr@FreeBSD.ORG

BROKEN_ELF=	build

RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot

OCTAVE_VERSION=	2.0.13
PLIST_SUB=	OCTAVE_VERSION=${OCTAVE_VERSION}
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	${SETENV} "INSTALL_DATA=$(INSTALL_DATA)" "INSTALL_PROGRAM=$(INSTALL_SCRIPT)"
CONFIGURE_ARGS=	--prefix=${PREFIX} --exec-prefix=${PREFIX} --with-f2c --disable-shared --host=i386-unknown-freebsd
USE_GMAKE=	yes
MAN1=		octave.1

LIBOCTAVE-INFO= liboctave.info liboctave.info-1 liboctave.info-2 liboctave.info-3

post-build:
	/usr/bin/strip $(WRKSRC)/src/octave

post-install:
.ifndef NOPORTDOCS
	install-info --defentry='* Octave: (octave).	Interactive language for numerical computations.' $(WRKSRC)/doc/interpreter/octave.info $(PREFIX)/info/dir
	install-info --defentry='* LibOctave: (liboctave).	C++ class library for Octave.' $(WRKSRC)/doc/liboctave/liboctave.info $(PREFIX)/info/dir
	$(MKDIR) $(PREFIX)/share/octave/doc
.for file in $(LIBOCTAVE-INFO)
	$(INSTALL_DATA) $(WRKSRC)/doc/liboctave/$(file) $(PREFIX)/info
.endfor
	$(INSTALL_DATA) $(WRKSRC)/doc/interpreter/octave.ps $(PREFIX)/share/octave/doc
	$(INSTALL_DATA) $(WRKSRC)/doc/liboctave/liboctave.ps $(PREFIX)/share/octave/doc
	$(INSTALL_DATA) $(WRKSRC)/doc/refcard/refcard-letter.ps $(PREFIX)/share/octave/doc
	$(INSTALL_DATA) $(WRKSRC)/doc/refcard/refcard-legal.ps $(PREFIX)/share/octave/doc
	$(INSTALL_DATA) $(WRKSRC)/doc/refcard/refcard-a4.ps $(PREFIX)/share/octave/doc
	$(INSTALL_DATA) $(WRKSRC)/doc/faq/Octave-FAQ.ps $(PREFIX)/share/octave/doc
	$(RM) -rf $(PREFIX)/libexec/octave/2.0.13/oct/i386-unknown-freebsd?
	$(RM) -rf $(PREFIX)/libexec/octave/2.0.13/exec/i386-unknown-freebsd?
	$(RM) -rf $(PREFIX)/libexec/octave/site/oct/i386-unknown-freebsd?
	$(RM) -rf $(PREFIX)/libexec/octave/site/exec/i386-unknown-freebsd?
.endif

.include <bsd.port.mk>
