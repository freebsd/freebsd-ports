# New ports collection makefile for:	octave
# Date created:		8 September 1998
# Whom:			chuckr@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	octave
PORTVERSION=	3.0.1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.octave.org/pub/octave/ \
		ftp://ftp.u-aizu.ac.jp/pub/SciEng/numanal/Octave/bleeding-edge/

MAINTAINER=	maho@FreeBSD.org
COMMENT=	High-level interactive language for numerical computations

BUILD_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot \
		${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf \
		gsed:${PORTSDIR}/textproc/gsed \
		dvips:${PORTSDIR}/print/dvipsk-tetex
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot \
		gsed:${PORTSDIR}/textproc/gsed
LIB_DEPENDS=	fftw3:${PORTSDIR}/math/fftw3 \
		glpk.14:${PORTSDIR}/math/glpk \
		hdf5:${PORTSDIR}/science/hdf5 \
		umfpack.1:${PORTSDIR}/math/suitesparse \
		qhull:${PORTSDIR}/math/qhull

LATEST_LINK=    octave-devel

USE_BZIP2=	yes
USE_PERL5_BUILD=yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:261 autoheader:261

INFO=		octave liboctave
MAN1=		octave.1 octave-bug.1 mkoctfile.1 octave-config.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
BUILD_DEPENDS+=	info:${PORTSDIR}/print/texinfo
BROKEN=		Fails to install
.endif

USE_BLAS?=	reference

.if exists(${LOCALBASE}/lib/libgoto.so)
USE_BLAS=	gotoblas
.elif exists(${LOCALBASE}/lib/libatlas_r.so)
USE_BLAS=	atlas
.endif

. if ${USE_BLAS} == reference
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.elif ${USE_BLAS} == gotoblas
LIB_DEPENDS+=	goto:${PORTSDIR}/math/gotoblas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lgotop
LAPACK=		-lgotop -llapack
.elif ${USE_BLAS} == atlas
LIB_DEPENDS+=	atlas:${PORTSDIR}/math/atlas
BLAS=		-lptf77blas -lptcblas -latlas_r
LAPACK=		-lalapack_r
.endif

USE_FORTRAN=	yes

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
		CXX="${CXX}" \
		TERMIOS_H="termios.h"
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
	${MKDIR} ${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/octave.desktop \
	${DESKTOPDIR}/www.octave.org-octave.desktop
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in faq/Octave-FAQ.ps liboctave/liboctave.ps \
	refcard/refcard-a4.ps refcard/refcard-legal.ps refcard/refcard-letter.ps
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
