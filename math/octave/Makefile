# New ports collection makefile for:	octave
# Version required:	2.0.9
# Date created:		28 June 1997
# Whom:			chuckr@freebsd.org
#
# $Id: Makefile,v 1.11 1997/10/15 23:20:44 max Exp $
#

DISTNAME=	octave-2.0.9
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.che.wisc.edu/pub/octave/

MAINTAINER=	chuckr@FreeBSD.ORG

RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot

MANUAL_PACKAGE_BUILD=	"installs libreadline shared library"

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	${SETENV} "INSTALL_DATA=$(INSTALL_DATA)" "INSTALL_PROGRAM=$(INSTALL_SCRIPT)"
CONFIGURE_ARGS=	--prefix=${PREFIX} --exec-prefix=${PREFIX} --with-f2c --enable-info --enable-shared --host=i386-unknown-freebsd
USE_GMAKE=	yes
MAN1=		octave.1

post-configure:
	(cd $(WRKDIR)/octave-2.0.9/scripts; ./configure)

OCTAVE-INFO= octave.info octave.info-1 octave.info-10 octave.info-11 octave.info-12 octave.info-2 octave.info-3 octave.info-4 octave.info-5 octave.info-6 octave.info-7 octave.info-8 octave.info-9
LIBOCTAVE-INFO= liboctave.info liboctave.info-1 liboctave.info-2 liboctave.info-3

post-install:
	${MV} ${PREFIX}/lib/libcruft.so ${PREFIX}/lib/libcruft.so.2.0
	${MV} ${PREFIX}/lib/liboctave.so ${PREFIX}/lib/liboctave.so.2.0
	${MV} ${PREFIX}/lib/liboctinterp.so ${PREFIX}/lib/liboctinterp.so.2.0
	${MV} ${PREFIX}/lib/libtinst.so ${PREFIX}/lib/libtinst.so.2.0
	${MV} ${PREFIX}/lib/libreadline.so ${PREFIX}/lib/libreadline.so.2.0
	${MV} ${PREFIX}/lib/libhistory.so ${PREFIX}/lib/libhistory.so.2.0
	${MV} ${PREFIX}/lib/libkpathsea.so ${PREFIX}/lib/libkpathsea.so.2.0
	${LDCONFIG} -m $(PREFIX)/lib
.ifndef NOPORTDOCS
.for file in $(OCTAVE-INFO)
	$(INSTALL_DATA) $(WRKSRC)/doc/interpreter/$(file) $(PREFIX)/info
.endfor
.for file in $(LIBOCTAVE-INFO)
	$(INSTALL_DATA) $(WRKSRC)/doc/liboctave/$(file) $(PREFIX)/info
.endfor
	$(MKDIR) $(PREFIX)/share/octave/doc
	$(INSTALL_DATA) $(WRKSRC)/doc/interpreter/octave.ps $(PREFIX)/share/octave/doc
	$(INSTALL_DATA) $(WRKSRC)/doc/liboctave/liboctave.ps $(PREFIX)/share/octave/doc
	$(INSTALL_DATA) $(WRKSRC)/doc/refcard/refcard-letter.ps $(PREFIX)/share/octave/doc
	$(INSTALL_DATA) $(WRKSRC)/doc/refcard/refcard-a4.ps $(PREFIX)/share/octave/doc
.endif

.include <bsd.port.mk>
