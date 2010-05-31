# ex:ts=8
# Ports collection makefile for:	gretl
# Date created:			Mar 22, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gretl
PORTVERSION=	1.8.7
PORTREVISION=	2
CATEGORIES=	math finance
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Regression, Econometrics and Time-series Library

BUILD_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot
LIB_DEPENDS=	fftw3.5:${PORTSDIR}/math/fftw3 \
		mpfr.3:${PORTSDIR}/math/mpfr
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot

USE_BZIP2=	yes
WANT_GNOME=	yes
USE_GNOME=	gnomehier gtk20 gtksourceview2 libxml2
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${GCCLIBDIR}"
CONFIGURE_ARGS=	--enable-static --enable-shared --with-gmake --without-gnome
ALL_TARGET=	# empty
USE_LDCONFIG=	yes

MAN1=		gretl.1

USE_FORTRAN=	yes
CONFIGURE_ENV+=	LAPACK_LIBS="${BLAS} ${LAPACK} -l${FORTRANRUNTIME}"
FORTRANRUNTIME=	gfortran
GCCLIBDIR=	-L`${CAT} ${WRKSRC}/LIBDIR` -L`${CAT} ${WRKSRC}/LIBDIR`/../../..

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		math/lapack appears to be broken on alpha
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

post-patch:
	@${REINPLACE_CMD} -e 's|set term png|set term dumb|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| DOMAIN| CEPHES_DOMAIN|g' \
		${WRKSRC}/cephes/iv.c
	@${REINPLACE_CMD} -e 's|@gnome_prefix@|@prefix@|g' \
		${WRKSRC}/gnome/gretl.keys.in

pre-configure:
	@${DIRNAME} `${F77} -print-libgcc-file-name` > ${WRKSRC}/LIBDIR

post-install:
	@${MKDIR} ${PREFIX}/share/applications
.for file in gretl.desktop
	${INSTALL_DATA} ${WRKSRC}/gnome/${file} ${PREFIX}/share/applications
.endfor
	@${MKDIR} ${PREFIX}/share/mime/packages
.for file in gretl.xml
	${INSTALL_DATA} ${WRKSRC}/xdg/${file} ${PREFIX}/share/mime/packages
.endfor
	@${MKDIR} ${PREFIX}/share/mime-info
.for file in gretl.keys gretl.mime
	${INSTALL_DATA} ${WRKSRC}/gnome/${file} ${PREFIX}/share/mime-info
.endfor
	@${MKDIR} ${PREFIX}/share/pixmaps
.for file in gnome-application-x-gretldata.png gnome-application-x-gretlsession.png
	${INSTALL_DATA} ${WRKSRC}/gnome/${file} ${PREFIX}/share/pixmaps
.endfor
.for file in gretl-logo.xpm gretl.xpm
	${INSTALL_DATA} ${WRKSRC}/pixmaps/${file} ${PREFIX}/share/pixmaps
.endfor
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.post.mk>
