# New ports collection makefile for:	octave
# Date created:		8 September 1998
# Whom:			chuckr@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	octave
PORTVERSION=	2.9.12
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.octave.org/pub/octave/bleeding-edge/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/GNU/misc/octave/bleeding-edge/\
		ftp://ftp.u-aizu.ac.jp/pub/SciEng/numanal/Octave/bleeding-edge/
PKGNAMESUFFIX=  -devel

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Developer's version of math/octave

BUILD_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot \
		${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf \
		${LOCALBASE}/lib/libglpk.a:${PORTSDIR}/math/glpk \
		gsed:${PORTSDIR}/textproc/gsed
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot
LIB_DEPENDS=	fftw3:${PORTSDIR}/math/fftw3 \
		hdf5:${PORTSDIR}/science/hdf5 \
		umfpack.1:${PORTSDIR}/math/suitesparse

LATEST_LINK=    octave-devel

USE_BZIP2=	yes
USE_PERL5_BUILD=yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:259 autoheader:259

INFO=		octave liboctave
MAN1=		octave.1 octave-bug.1 mkoctfile.1 octave-config.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
BUILD_DEPENDS+=	info:${PORTSDIR}/print/texinfo
.endif

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lf77blas -latlas
LAPACK=		-lalapack
.else
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.endif

WANT_FORTRAN=	yes
#workaround optimization bug in gcc42, not gfortran42
#USE_GCC=4.2+
BUILD_DEPENDS+=	gfortran42:${PORTSDIR}/lang/gcc42
FC=		gfortran42
F77=		gfortran42

OCTAVE_VERSION=	${PORTVERSION}
GNU_HOST=	${ARCH}-portbld-freebsd${OSREL}
PLIST_SUB=	OCTAVE_VERSION=${OCTAVE_VERSION} GNU_HOST=${GNU_HOST}
INCLUDES=	-I${LOCALBASE}/include -I${LOCALBASE}/include/metis
MAKE_ENV+=	CFLAGS="${CFLAGS} ${INCLUDES}" \
		CXXFLAGS="${CXXFLAGS} ${INCLUDES}" \
		CPPFLAGS="${CPPFLAGS} ${INCLUDES}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		CC="${CC}" \
		CXX="${CXX}"
CONFIGURE_ENV+=	GPERF="${LOCALBASE}/bin/gperf" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		CFLAGS="${CFLAGS} ${INCLUDES}" \
		CXXFLAGS="${CXXFLAGS} ${INCLUDES}" \
		CPPFLAGS="${CPPFLAGS} ${INCLUDES}" \
		F77="${FC}" \
		FFLAGS="${FFLAGS}" \
		CC="${CC}" \
		CXX="${CXX}"
CONFIGURE_ARGS=	--host=${GNU_HOST} \
		--with-blas="-L${LOCALBASE}/lib ${BLAS}" \
		--with-lapack="${LAPACK}" \
		--enable-shared

SUB_FILES=	octave
SUB_LIST=	OCTAVE_VERSION="${OCTAVE_VERSION}" GNU_HOST="${GNU_HOST}"

pre-configure:
	@cd ${WRKSRC}/scripts ; ${AUTOCONF}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/liboctave/liboctave.info ${PREFIX}/info
	${MV} ${PREFIX}/bin/${PORTNAME}-${PORTVERSION} ${PREFIX}/libexec/${PORTNAME}/${PORTVERSION}/exec/${GNU_HOST}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}-${PORTVERSION}
	${LN} -fs ${PREFIX}/bin/${PORTNAME}-${PORTVERSION} ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in faq/Octave-FAQ.ps interpreter/octave.ps liboctave/liboctave.ps \
	refcard/refcard-a4.ps refcard/refcard-legal.ps refcard/refcard-letter.ps
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
