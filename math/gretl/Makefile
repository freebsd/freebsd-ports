# ex:ts=8
# Ports collection makefile for:	gretl
# Date created:			Mar 22, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gretl
PORTVERSION=	1.6.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnu Regression, Econometrics and Time-series Library

BUILD_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot
LIB_DEPENDS=	mpfr.1:${PORTSDIR}/math/mpfr
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot

USE_BZIP2=	yes
WANT_GNOME=	yes
USE_GNOME=	gnometarget gtk20 libxml2
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:15 autoconf:259
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -DGNUPLOT_PNG" \
		LDFLAGS="-L${LOCALBASE}/lib ${GCCLIBDIR}"
CONFIGURE_ARGS+=	--enable-static --enable-shared --with-gmake
ALL_TARGET=	# empty

MAN1=		gretl.1 gretl-config.1

WANT_FORTRAN=	yes #dummy but future use
BUILD_DEPENDS+=	gfortran42:${PORTSDIR}/lang/gcc42
FC=		gfortran42
F77=		gfortran42
CONFIGURE_ENV+=	FC="${FC}" F77="${F77}" FFLAGS="${FFLAGS}" LAPACK_LIBS="${BLAS} ${LAPACK} -l${FORTRANRUNTIME}"
FORTRANRUNTIME=	gfortran
GCCLIBDIR=	-L`${CAT} ${WRKSRC}/LIBDIR` -L`${CAT} ${WRKSRC}/LIBDIR`/../../..

.include <bsd.port.pre.mk>

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

pre-configure:
	@${DIRNAME} `${F77} -print-libgcc-file-name` > ${WRKSRC}/LIBDIR

.if ${ARCH} == "alpha"
BROKEN=		math/lapack appears to be broken on alpha
.endif

.if ${HAVE_GNOME:Mlibgnomeui}!=""
PKGNAMESUFFIX=	-gnome
USE_GNOME+=	gnomeprefix gtksourceview libgnomeui
GCONF_SCHEMAS=	gretl.schemas
DATADIR=	${PREFIX}/share/gnome/${PORTNAME}
.else
CONFIGURE_ARGS+=	--without-gnome --without-gtksourceview
.endif

.include <bsd.port.post.mk>
