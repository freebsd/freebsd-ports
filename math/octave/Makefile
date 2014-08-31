# Created by: chuckr@FreeBSD.org
# $FreeBSD$

PORTNAME=	octave
PORTVERSION=	3.8.1
PORTREVISION=	5
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	octave

MAINTAINER=	maho@FreeBSD.org
COMMENT=	High-level interactive language for numerical computations

LICENSE=	GPLv3

BUILD_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot \
		${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf \
		gsed:${PORTSDIR}/textproc/gsed \
		${LOCALBASE}/bin/makeinfo:${PORTSDIR}/print/texinfo
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot \
		gsed:${PORTSDIR}/textproc/gsed \
		${LOCALBASE}/bin/makeinfo:${PORTSDIR}/print/texinfo
LIB_DEPENDS=	libGraphicsMagick.so:${PORTSDIR}/graphics/GraphicsMagick \
		libarpack.so:${PORTSDIR}/math/arpack \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libfftw3.so:${PORTSDIR}/math/fftw3 \
		libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		libfltk.so:${PORTSDIR}/x11-toolkits/fltk \
		libftgl.so:${PORTSDIR}/graphics/ftgl \
		libhdf5.so:${PORTSDIR}/science/hdf5 \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libqhull.so.5:${PORTSDIR}/math/qhull5 \
		libqrupdate.so:${PORTSDIR}/math/qrupdate \
		libumfpack.so:${PORTSDIR}/math/suitesparse \
		libglpk.so:${PORTSDIR}/math/glpk \
		libgl2ps.so:${PORTSDIR}/print/gl2ps \
		libqscintilla2.so:${PORTSDIR}/devel/qscintilla2

USES=		charsetfix fortran gmake libtool perl5 pkgconfig tar:bzip2
USE_PERL5=	build
USE_TEX=	dvipsk:build
GNU_CONFIGURE=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.7+
USE_QT4=	gui network uic_build moc_build rcc_build linguist_build

OCTAVE_VERSION=	${PORTVERSION}
GNU_HOST=	${ARCH}-portbld-freebsd${OSREL}
PLIST_SUB=	OCTAVE_VERSION=${OCTAVE_VERSION} GNU_HOST=${GNU_HOST}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	GPERF="${LOCALBASE}/bin/gperf" \
		JAVA_HOME=${JAVA_HOME} \
		MAKEINFO=${LOCALBASE}/bin/makeinfo
CONFIGURE_ARGS=	--host=${GNU_HOST} \
		--with-blas="-L${LOCALBASE}/lib ${BLAS}" \
		--with-lapack="${LAPACK}" \
		--enable-shared \
		--disable-jit

OPTIONS_DEFINE=	DOCS

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
LIB_DEPENDS+=	libblas.so.2:${PORTSDIR}/math/blas \
		liblapack.so.4:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.elif ${WITH_BLAS} == openblas
LIB_DEPENDS+=	libopenblas.so:${PORTSDIR}/math/openblas
BLAS=		-lopenblasp
LAPACK=		-lopenblasp
.elif ${WITH_BLAS} == gotoblas
LIB_DEPENDS+=	libgoto2.so:${PORTSDIR}/math/gotoblas
BLAS=		-lgoto2p
LAPACK=		-lgoto2p
.elif ${WITH_BLAS} == atlas
LIB_DEPENDS+=	libatlas.so:${PORTSDIR}/math/atlas
BLAS=		-lptf77blas
LAPACK=		-lalapack -lptcblas
.endif

post-patch:
	${REINPLACE_CMD} 's+"makeinfo"+"${LOCALBASE}/bin/makeinfo"+' ${WRKSRC}/libinterp/corefcn/help.cc
	${REINPLACE_CMD} 's+-lumfpack+-lumfpack -lsuitesparseconfig -lamd -lcholmod -lcolamd ${LAPACK}+' ${WRKSRC}/configure
	${REINPLACE_CMD} 's+-lcholmod+-lumfpack -lsuitesparseconfig -lamd -lcholmod -lcolamd ${LAPACK}+' ${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/icons/octave.desktop \
		${STAGEDIR}${DESKTOPDIR}/www.octave.org-octave.desktop
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in liboctave/liboctave.ps \
	refcard/refcard-a4.ps refcard/refcard-legal.ps \
	refcard/refcard-letter.ps interpreter/octave.ps
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${STAGEDIR}${DOCSDIR}
.endfor
	${RM} -f ${WRKDIR}/PLIST
.for d in ${PREFIX}/include/octave-${OCTAVE_VERSION} ${PREFIX}/share/octave/${OCTAVE_VERSION} ${PREFIX}/share/octave/site ${PREFIX}/lib/octave/${OCTAVE_VERSION} ${PREFIX}/libexec/octave/${OCTAVE_VERSION}
	@${FIND} -s ${STAGEDIR}$d -not -type d -not -name '*.la' | \
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
