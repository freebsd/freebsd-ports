# New ports collection makefile for:	octave
# Date created:		8 September 1998
# Whom:			chuckr@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	octave
PORTVERSION=	2.1.39
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.che.wisc.edu/pub/octave/bleeding-edge/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/GNU/misc/octave/bleeding-edge/

MAINTAINER=	chuckr@FreeBSD.org

USE_BZIP2=	yes
BUILD_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot
LIB_DEPENDS=    fftw.2:${PORTSDIR}/math/fftw

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
GNU_HOST=	${ARCH}-portbld-freebsd${OSREL}
.else
GNU_HOST=	${ARCH}-portbld-freebsdaout${OSREL}
.endif
OCTAVE_VERSION=	2.1.30
PLIST_SUB=	OCTAVE_VERSION=${OCTAVE_VERSION} GNU_HOST=${GNU_HOST}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-shared --with-fftw --host=${GNU_HOST}

.if ${OSVERSION} < 400004
CONFIGURE_ARGS+=	--with-f2c
.endif

MAN1=		octave.1 octave-bug.1

LIBOCTAVE-INFO= liboctave.info liboctave.info-1 liboctave.info-2 liboctave.info-3

post-install:
.ifndef NOPORTDOCS
	$(MKDIR) $(PREFIX)/share/octave/doc
.for file in $(LIBOCTAVE-INFO)
	$(INSTALL_DATA) $(WRKSRC)/doc/liboctave/$(file) $(PREFIX)/info
.endfor
	install-info --entry='* Octave: (octave).	Interactive language for numerical computations.' $(PREFIX)/info/octave.info $(PREFIX)/info/dir
	install-info --entry='* LibOctave: (liboctave).	C++ class library for Octave.' $(PREFIX)/info/liboctave.info $(PREFIX)/info/dir
	$(INSTALL_DATA) $(WRKSRC)/doc/interpreter/octave.ps $(PREFIX)/share/octave/doc
	$(INSTALL_DATA) $(WRKSRC)/doc/liboctave/liboctave.ps $(PREFIX)/share/octave/doc
	$(INSTALL_DATA) $(WRKSRC)/doc/refcard/refcard-letter.ps $(PREFIX)/share/octave/doc
	$(INSTALL_DATA) $(WRKSRC)/doc/refcard/refcard-legal.ps $(PREFIX)/share/octave/doc
	$(INSTALL_DATA) $(WRKSRC)/doc/refcard/refcard-a4.ps $(PREFIX)/share/octave/doc
	$(INSTALL_DATA) $(WRKSRC)/doc/faq/Octave-FAQ.ps $(PREFIX)/share/octave/doc
.endif

.include <bsd.port.post.mk>
