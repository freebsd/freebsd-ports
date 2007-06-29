# New ports collection makefile for:	octave
# Date created:		8 September 1998
# Whom:			chuckr@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	octave
PORTVERSION=	2.1.73
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.octave.org/pub/octave/bleeding-edge/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/GNU/misc/octave/bleeding-edge/ \
		http://neacm.fe.up.pt/pub/octave/bleeding-edge/ \
		ftp://ftp.lublin.pl/site/octave/bleeding-edge/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-level interactive language for numerical computations

BUILD_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot
LIB_DEPENDS=	fftw.2:${PORTSDIR}/math/fftw

USE_BZIP2=	yes
USE_PERL5_BUILD=yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/octave-${OCTAVE_VERSION}

INFO=		octave liboctave
MAN1=		octave.1 octave-bug.1 mkoctfile.1 octave-config.1

OCTAVE_VERSION=	${PORTVERSION}
GNU_HOST=	${ARCH}-portbld-freebsd${OSREL}
PLIST_SUB=	OCTAVE_VERSION=${OCTAVE_VERSION} GNU_HOST=${GNU_HOST}

WANT_FORTRAN=yes #dummy but future use
BUILD_DEPENDS+= gfortran42:${PORTSDIR}/lang/gcc42
FC=     gfortran42
F77=    gfortran42

CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		F77="${F77}" \
		FFLAGS="${FFLAGS}"
CONFIGURE_ARGS=	--host=${GNU_HOST} \
		--enable-shared

SUB_FILES=	octave
SUB_LIST=	OCTAVE_VERSION="${OCTAVE_VERSION}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on FreeBSD 4.x
.endif

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=		yes
.endif

.if defined(WITH_ATLAS)
LIB_DEPENDS+=		atlas.2:${PORTSDIR}/math/atlas
CONFIGURE_ARGS+=	--with-blas="-L${LOCALBASE}/lib -lf77blas -lcblas -latlas" \
			--with-lapack=-lalapack
.else
LIB_DEPENDS+=		blas.2:${PORTSDIR}/math/blas
CONFIGURE_ARGS+=	--with-blas="-L${LOCALBASE}/lib -lblas"
.endif

post-install:
	${MV} ${PREFIX}/bin/octave-${OCTAVE_VERSION} ${PREFIX}/libexec/octave/${OCTAVE_VERSION}
	${INSTALL_SCRIPT} ${WRKDIR}/octave ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/octave ${PREFIX}/bin/octave-${OCTAVE_VERSION}
	${INSTALL_DATA} ${WRKSRC}/doc/liboctave/liboctave.info ${PREFIX}/info
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in faq/Octave-FAQ.ps interpreter/octave.ps liboctave/liboctave.ps \
	refcard/refcard-a4.ps refcard/refcard-legal.ps refcard/refcard-letter.ps
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
