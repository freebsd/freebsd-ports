# ex:ts=8
# Ports collection makefile for:	mpb
# Date created:			Apr 4, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mpb
PORTVERSION=	1.4.2
CATEGORIES=	science
MASTER_SITES=	http://ab-initio.mit.edu/mpb/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MIT Photonic-Bands

BUILD_DEPENDS=	${LOCALBASE}/lib/libctl.a:${PORTSDIR}/science/libctl \
		bash:${PORTSDIR}/shells/bash2
LIB_DEPENDS=	blas.1:${PORTSDIR}/math/blas \
		lapack.3:${PORTSDIR}/math/lapack \
		atlas.1:${PORTSDIR}/math/atlas \
		fftw.2:${PORTSDIR}/math/fftw \
		hdf5.0:${PORTSDIR}/graphics/hdf5 \
		guile.15:${PORTSDIR}/lang/guile

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	mpb.1 mpb-data.1 mpb-split.1

.include <bsd.port.mk>
