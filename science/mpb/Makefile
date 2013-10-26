# Created by: ijliao
# $FreeBSD$

PORTNAME=	mpb
PORTVERSION=	1.4.2
PORTREVISION=	13
CATEGORIES=	science
MASTER_SITES=	http://ab-initio.mit.edu/mpb/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MIT Photonic-Bands

LICENSE=	GPLv2

MAKE_JOBS_UNSAFE= yes

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	fftw:${PORTSDIR}/math/fftw \
		hdf5:${PORTSDIR}/science/hdf5 \
		ctl:${PORTSDIR}/science/libctl \
		guile:${PORTSDIR}/lang/guile

USE_FORTRAN=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if exists(${LOCALBASE}/lib/libatlas.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas:${PORTSDIR}/math/atlas
CONFIGURE_ARGS+=	--with-lapack=-lalapack
.else
LIB_DEPENDS+=	blas:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack:${PORTSDIR}/math/lapack
CONFIGURE_ARGS+=	--with-lapack=-llapack
.endif

MAN1=	mpb.1 mpb-data.1 mpb-split.1

post-patch:
	@${REINPLACE_CMD} -e 's|-lhdf5 |-lhdf5 ${PTHREAD_LIBS} |g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
