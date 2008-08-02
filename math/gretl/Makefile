# ex:ts=8
# Ports collection makefile for:	gretl
# Date created:			Mar 22, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gretl
PORTVERSION=	1.7.6
CATEGORIES=	math finance
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnu Regression, Econometrics and Time-series Library

BUILD_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot
LIB_DEPENDS=	fftw3.4:${PORTSDIR}/math/fftw3 \
		mpfr.2:${PORTSDIR}/math/mpfr
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot

USE_BZIP2=	yes
WANT_GNOME=	yes
USE_GNOME=	gnometarget gtk20 libxml2
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15 autoconf:261
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -DGNUPLOT_PNG" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnuregex ${GCCLIBDIR}"
CONFIGURE_ARGS=	--enable-static --enable-shared --with-gmake
ALL_TARGET=	# empty
USE_LDCONFIG=	yes

MAN1=		gretl.1 gretl-config.1

USE_FORTRAN=	yes
CONFIGURE_ENV+=	FC="${FC}" F77="${F77}" FFLAGS="${FFLAGS}" LAPACK_LIBS="${BLAS} ${LAPACK} -l${FORTRANRUNTIME}"
FORTRANRUNTIME=	gfortran
GCCLIBDIR=	-L`${CAT} ${WRKSRC}/LIBDIR` -L`${CAT} ${WRKSRC}/LIBDIR`/../../..

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		math/lapack appears to be broken on alpha
.endif

.if ${HAVE_GNOME:Mlibgnomeui}!=""
PKGNAMESUFFIX=	-gnome
USE_GNOME+=	gnomeprefix gtksourceview2 libgnomeui
.else
CONFIGURE_ARGS+=	--without-gnome --without-gtksourceview
.endif

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif

.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lf77blas -latlas
LAPACK=		-lalapack -lcblas
.else
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.endif

.if ${OSVERSION} > 502010
GNU_REGEX_H=	gnu/regex.h
.else
GNU_REGEX_H=	gnuregex.h
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|<regex.h>|<${GNU_REGEX_H}>|g' \
		${WRKSRC}/gui2/gtksourceview/gtksourceregex.c

pre-configure:
	@${DIRNAME} `${F77} -print-libgcc-file-name` > ${WRKSRC}/LIBDIR

.include <bsd.port.post.mk>
