# New ports collection makefile for:	octave
# Date created:		8 September 1998
# Whom:			chuckr@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	octave
PORTVERSION=	2.1.63
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.octave.org/pub/octave/bleeding-edge/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/GNU/misc/octave/bleeding-edge/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-level interactive language for numerical computations

BUILD_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot
LIB_DEPENDS=	fftw.2:${PORTSDIR}/math/fftw \
		atlas.1:${PORTSDIR}/math/atlas

USE_BZIP2=	yes
USE_PERL5_BUILD=yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on FreeBSD 4.x"
.else
BROKEN=		"Does not compile on FreeBSD >= 5.x"
.endif

.if ${PORTOBJFORMAT} == "elf"
GNU_HOST=	${ARCH}-portbld-freebsd${OSREL}
.else
GNU_HOST=	${ARCH}-portbld-freebsdaout${OSREL}
.endif
OCTAVE_VERSION=	${PORTVERSION}
PLIST_SUB=	OCTAVE_VERSION=${OCTAVE_VERSION} GNU_HOST=${GNU_HOST}

BLAS_LIBS=	"-L${LOCALBASE}/lib -lf77blas -lcblas -latlas"
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONIGURE_ARGS=	--host=${GNU_HOST} --with-fftw --with-blas=${BLAS_LIBS} \
		--with-lapack=-lalapack --enable-shared

CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		FFLAGS="${FFLAGS}"

.if ${OSVERSION} < 400004
CONFIGURE_ARGS+=	--with-f2c
.endif

.if ${OSVERSION} < 500000
CONFIGURE_ARGS+=	--disable-readline
.endif

MAN1=		octave.1 octave-bug.1 mkoctfile.1 octave-config.1

post-extract:
	@${RM} -f ${WRKSRC}/doc/interpreter/octave.info*
	@${RM} -f ${WRKSRC}/doc/liboctave/liboctave.info*
post-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g ; \
		    s,%%OCTAVE_VERSION%%,${OCTAVE_VERSION},g' \
		${FILESDIR}/octave > ${WRKDIR}/octave
	${RM} ${PREFIX}/bin/octave
	${INSTALL_SCRIPT} ${WRKDIR}/octave ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/liboctave/liboctave.info ${PREFIX}/info
	install-info --entry='* Octave: (octave).	Interactive language for numerical computations.' $(PREFIX)/info/octave.info $(PREFIX)/info/dir
	install-info --entry='* LibOctave: (liboctave).	C++ class library for Octave.' $(PREFIX)/info/liboctave.info $(PREFIX)/info/dir
.ifndef NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
.for file in faq/Octave-FAQ.ps interpreter/octave.ps liboctave/liboctave.ps \
	refcard/refcard-a4.ps refcard/refcard-legal.ps refcard/refcard-letter.ps
	$(INSTALL_DATA) ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
