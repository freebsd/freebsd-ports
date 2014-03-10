# Created by: chuckr@FreeBSD.org
# $FreeBSD$

PORTNAME=	octave
PORTVERSION=	3.8.0
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	octave

MAINTAINER=	maho@FreeBSD.org
COMMENT=	High-level interactive language for numerical computations

LICENSE=	GPLv3

BUILD_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot \
		${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf \
		gsed:${PORTSDIR}/textproc/gsed \
		${LOCALBASE}/bin/makeinfo:${PORTSDIR}/print/texinfo
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot \
		gsed:${PORTSDIR}/textproc/gsed \
		${LOCALBASE}/bin/makeinfo:${PORTSDIR}/print/texinfo
LIB_DEPENDS=	GraphicsMagick.14:${PORTSDIR}/graphics/GraphicsMagick13 \
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
		glpk:${PORTSDIR}/math/glpk \
		gl2ps:${PORTSDIR}/print/gl2ps

USES=		charsetfix fortran gmake perl5 pkgconfig
USE_BZIP2=	yes
USE_PERL5=	build
USE_TEX=	dvipsk:build
GNU_CONFIGURE=	yes
#USE_AUTOTOOLS=	autoconf
USE_JAVA=	yes
JAVA_VERSION=	1.7+
CONFIGURE_ENV+=	JAVA_HOME=${JAVA_HOME}
USE_QT4=	gui network

INFO=		octave liboctave

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
		--enable-shared \
		--disable-jit

.if (${OSVERSION} <= 700000)
WITH_PTMALLOC=yes
.endif

.if defined(WITH_PTMALLOC)
LIB_DEPENDS+=	ptmalloc:${PORTSDIR}/devel/ptmalloc
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib -lptmalloc"
.endif

post-patch:
	${REINPLACE_CMD} 's+"makeinfo"+"${PREFIX}/bin/makeinfo"+' ${WRKSRC}/libinterp/corefcn/help.cc
	${REINPLACE_CMD} 's+-lumfpack+-lumfpack -lsuitesparseconfig -lamd -lcholmod -lcolamd ${LAPACK}+' ${WRKSRC}/configure
	${REINPLACE_CMD} 's+-lcholmod+-lumfpack -lsuitesparseconfig -lamd -lcholmod -lcolamd ${LAPACK}+' ${WRKSRC}/configure

post-install:
	${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/icons/octave.desktop \
	${STAGEDIR}${DESKTOPDIR}/www.octave.org-octave.desktop
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in liboctave/liboctave.ps \
	refcard/refcard-a4.ps refcard/refcard-legal.ps \
	refcard/refcard-letter.ps interpreter/octave.ps
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${STAGEDIR}${DOCSDIR}
.endfor
.endif
	${RM} -f ${WRKDIR}/PLIST
.for d in ${PREFIX}/include/octave-${OCTAVE_VERSION} ${PREFIX}/share/octave/${OCTAVE_VERSION} ${PREFIX}/share/octave/site ${PREFIX}/lib/octave/${OCTAVE_VERSION} ${PREFIX}/libexec/octave/${OCTAVE_VERSION}
	@${FIND} -s ${STAGEDIR}$d -not -type d | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${WRKDIR}/PLIST
	@${FIND} -s ${STAGEDIR}$d -type d -empty | \
		${SED} -e 's,^${STAGEDIR}${PREFIX}/,@exec ${MKDIR} %D/,' \
		-e 's,$$, 2>/dev/null || true,' >> ${WRKDIR}/PLIST
	@${FIND} -s ${STAGEDIR}$d -type d -depth | \
		${SED} -e 's,^${STAGEDIR}${PREFIX}/,@dirrm ,' >> ${WRKDIR}/PLIST
.endfor
.for d in ${PREFIX}/libexec/octave/api-v49+ ${PREFIX}/libexec/octave/site ${PREFIX}/lib/octave/site
	@${FIND} -s ${STAGEDIR}$d -type d -empty | \
		${SED} -e 's,^${STAGEDIR}${PREFIX}/,@exec ${MKDIR} %D/,' \
		-e 's,$$, 2>/dev/null || true,' >> ${WRKDIR}/PLIST
	@${FIND} -s ${STAGEDIR}$d -type d -depth | \
		${SED} -e 's,^${STAGEDIR}${PREFIX}/,@dirrm ,' >> ${WRKDIR}/PLIST
.endfor
	${ECHO_CMD} @dirrm libexec/octave >> ${WRKDIR}/PLIST
	${ECHO_CMD} @dirrm share/octave >> ${WRKDIR}/PLIST
	cd ${WRKDIR} ; ${SED} -i.bak -e "/PLIST/ r PLIST" ${TMPPLIST}

check regression-test: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} check)

.include <bsd.port.post.mk>
