# Created by: chuckr@FreeBSD.org
# $FreeBSD$

PORTNAME=	octave
PORTVERSION=	4.0.3
PORTREVISION=	7
CATEGORIES=	math
MASTER_SITES=	GNU

MAINTAINER=	maho@FreeBSD.org
COMMENT=	High-level interactive language for numerical computations

LICENSE=	GPLv3

BUILD_DEPENDS=	gnuplot:math/gnuplot \
		${LOCALBASE}/bin/gperf:devel/gperf \
		gsed:textproc/gsed \
		${LOCALBASE}/bin/makeinfo:print/texinfo
RUN_DEPENDS=	gnuplot:math/gnuplot \
		gsed:textproc/gsed \
		${LOCALBASE}/bin/makeinfo:print/texinfo
LIB_DEPENDS=	libGraphicsMagick.so:graphics/GraphicsMagick \
		libarpack.so:math/arpack \
		libcurl.so:ftp/curl \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libfltk.so:x11-toolkits/fltk \
		libftgl.so:graphics/ftgl \
		libhdf5.so:science/hdf5 \
		libpcre.so:devel/pcre \
		libqhull.so.5:math/qhull5 \
		libqrupdate.so:math/qrupdate \
		libumfpack.so:math/suitesparse \
		libglpk.so:math/glpk \
		libgl2ps.so:print/gl2ps \
		libqscintilla2.so:devel/qscintilla2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		charsetfix fortran gmake libtool perl5 pkgconfig readline tar:xz
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_TEX=	dvipsk:build
GNU_CONFIGURE=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.7+
USE_QT4=	corelib gui network opengl uic_build moc_build rcc_build linguist_build
USE_XORG=	x11 xext xfixes xft
USE_GL=		gl glu 

OCTAVE_VERSION=	${PORTVERSION}
GNU_HOST=	${ARCH}-portbld-freebsd${OSREL}
PLIST_SUB=	OCTAVE_VERSION=${OCTAVE_VERSION} GNU_HOST=${GNU_HOST}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	GPERF="${LOCALBASE}/bin/gperf" \
		JAVA_HOME=${JAVA_HOME} \
		MAKEINFO=${LOCALBASE}/bin/makeinfo \
		ac_cv_type_max_align_t=yes
CONFIGURE_ARGS=	--host=${GNU_HOST} \
		--with-blas="-L${LOCALBASE}/lib ${BLASLIB}" \
		--with-lapack="${LAPACKLIB}" \
		--enable-shared \
		--disable-jit

OPTIONS_DEFINE=	DOCS

OPTIONS_RADIO=  BLAS
OPTIONS_RADIO_BLAS=     OPENBLAS NETLIB ATLAS
OPTIONS_DEFAULT=        OPENBLAS

OPENBLAS_USES=  blaslapack:openblas
NETLIB_USES=    blaslapack:netlib
ATLAS_USES=     blaslapack:atlas

INFO=		octave liboctave

post-patch:
	${REINPLACE_CMD} 's+"makeinfo"+"${LOCALBASE}/bin/makeinfo"+' ${WRKSRC}/libinterp/corefcn/help.cc
	${REINPLACE_CMD} 's+lapack lapack_rs6k+${LAPACKLIB:C/-l//}+' ${WRKSRC}/configure
	${REINPLACE_CMD} 's+-lumfpack+-lumfpack -lsuitesparseconfig -lamd -lcholmod -lcolamd ${LAPACKLIB}+' ${WRKSRC}/configure
	${REINPLACE_CMD} 's+-lcholmod+-lumfpack -lsuitesparseconfig -lamd -lcholmod -lcolamd ${LAPACKLIB}+' ${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/icons/octave.desktop \
		${STAGEDIR}${DESKTOPDIR}/www.octave.org-octave.desktop
	(cd ${STAGEDIR}${DATADIR} && ln -s ${PORTVERSION}/imagelib  .)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in liboctave/liboctave.ps \
	refcard/refcard-a4.ps refcard/refcard-legal.ps \
	refcard/refcard-letter.ps interpreter/octave.ps
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${STAGEDIR}${DOCSDIR}
.endfor

check regression-test: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} check)

.include <bsd.port.mk>
