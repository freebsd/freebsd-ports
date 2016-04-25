# Created by: ijliao
# $FreeBSD$

PORTNAME=	mpb
PORTVERSION=	1.5
PORTREVISION=	3
CATEGORIES=	science
MASTER_SITES=	http://ab-initio.mit.edu/mpb/

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	MIT Photonic-Bands

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libfftw.so:math/fftw \
		libhdf5.so:science/hdf5 \
		libctl.so:science/libctl \
		libguile-2.0.so:lang/guile2

OPTIONS_DEFINE=	ATLAS NLOPT
ATLAS_DESC=	Use math/atlas instead of math/lapack
NLOPT_DESC=	Use math/nlopt (check also in science/libctl)

USES=		fortran libtool pkgconfig
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NLOPT_LIB_DEPENDS=	libnlopt.so:math/nlopt

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MATLAS}
LIB_DEPENDS+=	libatlas.so:math/atlas
CONFIGURE_ARGS+=	--with-lapack=-lalapack
.else
LIB_DEPENDS+=	libblas.so:math/blas \
		liblapack.so:math/lapack
CONFIGURE_ARGS+=	--with-lapack=-llapack
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lhdf5 |-lhdf5 -lpthread |g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} \
		-e '/INSTALL/s/$$(prefix)/$$(DESTDIR)$$(prefix)/' \
		-e '/INSTALL/s/$$(mandir)/$$(DESTDIR)$$(mandir)/' \
		${WRKSRC}/mpb/Makefile.in ${WRKSRC}/utils/Makefile.in

.include <bsd.port.mk>
