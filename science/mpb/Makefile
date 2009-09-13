# ex:ts=8
# Ports collection makefile for:	mpb
# Date created:			Apr 4, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mpb
PORTVERSION=	1.4.2
PORTREVISION=	9
CATEGORIES=	science
MASTER_SITES=	http://ab-initio.mit.edu/mpb/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MIT Photonic-Bands

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	fftw.2:${PORTSDIR}/math/fftw \
		hdf5.0:${PORTSDIR}/science/hdf5 \
		ctl.3:${PORTSDIR}/science/libctl \
		guile.20:${PORTSDIR}/lang/guile

USE_FORTRAN=	yes

.include <bsd.port.pre.mk>
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
CONFIGURE_ARGS+=	--with-lapack=-lalapack
.else
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
CONFIGURE_ARGS+=	--with-lapack=-llapack
.endif

MAN1=	mpb.1 mpb-data.1 mpb-split.1

post-patch:
	@${REINPLACE_CMD} -e 's|-lhdf5 |-lhdf5 ${PTHREAD_LIBS} |g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
