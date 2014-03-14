# Created by: ijliao
# $FreeBSD$

PORTNAME=	mpb
PORTVERSION=	1.4.2
PORTREVISION=	14
CATEGORIES=	science
MASTER_SITES=	http://ab-initio.mit.edu/mpb/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MIT Photonic-Bands

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	libfftw.so:${PORTSDIR}/math/fftw \
		libhdf5.so:${PORTSDIR}/science/hdf5 \
		libctl.so:${PORTSDIR}/science/libctl \
		libguile.so:${PORTSDIR}/lang/guile

OPTIONS_DEFINE=	ATLAS
ATLAS_DESC=	Use math/atlas instead of math/lapack

USES=		fortran
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MATLAS}
LIB_DEPENDS+=	libatlas.so:${PORTSDIR}/math/atlas
CONFIGURE_ARGS+=	--with-lapack=-lalapack
.else
LIB_DEPENDS+=	libblas.so:${PORTSDIR}/math/blas \
		liblapack.so:${PORTSDIR}/math/lapack
CONFIGURE_ARGS+=	--with-lapack=-llapack
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lhdf5 |-lhdf5 ${PTHREAD_LIBS} |g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} \
		-e '/INSTALL/s/$$(prefix)/$$(DESTDIR)$$(prefix)/' \
		-e '/INSTALL/s/$$(mandir)/$$(DESTDIR)$$(mandir)/' \
		${WRKSRC}/mpb-ctl/Makefile.in ${WRKSRC}/utils/Makefile.in

.include <bsd.port.mk>
