# Created by: chuckr@FreeBSD.org
# $FreeBSD$

PORTNAME=	octave
PORTVERSION=	3.6.4
PORTREVISION=	6
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.gnu.org/gnu/octave/ \
		ftp://ftp.u-aizu.ac.jp/pub/SciEng/numanal/Octave/bleeding-edge/

MAINTAINER=	maho@FreeBSD.org
COMMENT=	High-level interactive language for numerical computations

BUILD_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot \
		${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf \
		gsed:${PORTSDIR}/textproc/gsed \
		${LOCALBASE}/bin/makeinfo:${PORTSDIR}/print/texinfo
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot \
		gsed:${PORTSDIR}/textproc/gsed \
		${LOCALBASE}/bin/makeinfo:${PORTSDIR}/print/texinfo
LIB_DEPENDS=	GraphicsMagick:${PORTSDIR}/graphics/GraphicsMagick \
		arpack:${PORTSDIR}/math/arpack \
		curl:${PORTSDIR}/ftp/curl \
		fftw3:${PORTSDIR}/math/fftw3 \
		fftw3f:${PORTSDIR}/math/fftw3-float \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk \
		ftgl:${PORTSDIR}/graphics/ftgl \
		hdf5:${PORTSDIR}/science/hdf5-18 \
		pcre.3:${PORTSDIR}/devel/pcre \
		qhull.5:${PORTSDIR}/math/qhull5 \
		qrupdate:${PORTSDIR}/math/qrupdate \
		umfpack.1:${PORTSDIR}/math/suitesparse \
		glpk:${PORTSDIR}/math/glpk

USES=		charsetfix gmake perl5 pkgconfig
USE_BZIP2=	yes
USE_PERL5=	build
USE_TEX=	dvipsk:build
GNU_CONFIGURE=	yes
#USE_AUTOTOOLS=	autoconf

INFO=		octave liboctave OctaveFAQ
MAN1=		octave.1 mkoctfile.1 octave-config.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libopenblas.so)
WITH_BLAS?=	openblas
.elif exists(${LOCALBASE}/lib/libgoto2.so)
WITH_BLAS?=	gotoblas
.elif exists(${LOCALBASE}/lib/libatlas.so)
WITH_BLAS?=	atlas
.else
WITH_BLAS?=	reference
.endif

. if ${WITH_BLAS} == reference
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.elif ${WITH_BLAS} == openblas
LIB_DEPENDS+=	openblas:${PORTSDIR}/math/openblas
BLAS=		-lopenblasp
LAPACK=		-lopenblasp
.elif ${WITH_BLAS} == gotoblas
LIB_DEPENDS+=	goto2:${PORTSDIR}/math/gotoblas
BLAS=		-lgoto2p
LAPACK=		-lgoto2p
.elif ${WITH_BLAS} == atlas
LIB_DEPENDS+=	atlas:${PORTSDIR}/math/atlas
BLAS=		-lptf77blas
LAPACK=		-lalapack -lptcblas
.endif

USE_FORTRAN=	yes

OCTAVE_VERSION=	${PORTVERSION}
GNU_HOST=	${ARCH}-portbld-freebsd${OSREL}
PLIST_SUB=	OCTAVE_VERSION=${OCTAVE_VERSION} GNU_HOST=${GNU_HOST}
INCLUDES=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CFLAGS+=	${INCLUDES}
CXXFLAGS+=	${INCLUDES}
CPPFLAGS+=	${INCLUDES}
CONFIGURE_ENV+=	GPERF="${LOCALBASE}/bin/gperf" \
		CC="${CC}" \
		CXX="${CXX}" \
		MAKEINFO=${PREFIX}/bin/makeinfo
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ARGS=	--host=${GNU_HOST} \
		--with-blas="-L${LOCALBASE}/lib ${BLAS}" \
		--with-lapack="${LAPACK}" \
		--enable-shared

.if (${OSVERSION} <= 700000)
WITH_PTMALLOC=yes
.endif

.if defined(WITH_PTMALLOC)
LIB_DEPENDS+=	ptmalloc:${PORTSDIR}/devel/ptmalloc
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib -lptmalloc"
.endif

post-patch:
	${REINPLACE_CMD} 's+"makeinfo"+"${PREFIX}/bin/makeinfo"+' ${WRKSRC}/src/help.cc
	${REINPLACE_CMD} 's+-lumfpack+-lumfpack -lcholmod -lcolamd -llapack+' ${WRKSRC}/configure

post-install:
	${MKDIR} ${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/icons/octave.desktop \
	${DESKTOPDIR}/www.octave.org-octave.desktop
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in faq/OctaveFAQ.ps liboctave/liboctave.ps \
	refcard/refcard-a4.ps refcard/refcard-legal.ps \
	refcard/refcard-letter.ps interpreter/octave.ps
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif
	${RM} -f ${WRKDIR}/PLIST
.for d in ${PREFIX}/include/octave-${OCTAVE_VERSION} ${PREFIX}/share/octave/${OCTAVE_VERSION} ${PREFIX}/share/octave/site ${PREFIX}/lib/octave/${OCTAVE_VERSION}
	@${FIND} -s $d -not -type d | \
		${SED} -e 's#^${PREFIX}/##' >> ${WRKDIR}/PLIST
	@${FIND} -s $d -type d -empty | \
		${SED} -e 's,^${PREFIX}/,@exec ${MKDIR} %D/,' \
		-e 's,$$, 2>/dev/null || true,' >> ${WRKDIR}/PLIST
	@${FIND} -s $d -type d -depth | \
		${SED} -e 's,^${PREFIX}/,@dirrm ,' >> ${WRKDIR}/PLIST
.endfor
.for d in ${PREFIX}/libexec/octave/${OCTAVE_VERSION} ${PREFIX}/libexec/octave/api-v45+ ${PREFIX}/libexec/octave/api-v48+ ${PREFIX}/libexec/octave/site ${PREFIX}/lib/octave/site
	@${FIND} -s $d -type d -empty | \
		${SED} -e 's,^${PREFIX}/,@exec ${MKDIR} %D/,' \
		-e 's,$$, 2>/dev/null || true,' >> ${WRKDIR}/PLIST
	@${FIND} -s $d -type d -depth | \
		${SED} -e 's,^${PREFIX}/,@dirrm ,' >> ${WRKDIR}/PLIST
.endfor
	${ECHO_CMD} @dirrm libexec/octave >> ${WRKDIR}/PLIST
	${ECHO_CMD} @dirrm share/octave >> ${WRKDIR}/PLIST
	cd ${WRKDIR} ; ${SED} -i -e "/PLIST/ r PLIST" ${TMPPLIST}

check:
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} check)

.include <bsd.port.post.mk>
