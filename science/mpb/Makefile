# ex:ts=8
# Ports collection makefile for:	mpb
# Date created:			Apr 4, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mpb
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://ab-initio.mit.edu/mpb/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MIT Photonic-Bands

BUILD_DEPENDS=	${LOCALBASE}/lib/libctl.a:${PORTSDIR}/science/libctl \
		bash:${PORTSDIR}/shells/bash2
LIB_DEPENDS=	atlas.1:${PORTSDIR}/math/atlas \
		fftw.2:${PORTSDIR}/math/fftw \
		hdf5.0:${PORTSDIR}/science/hdf5 \
		guile.15:${PORTSDIR}/lang/guile

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--with-lapack=-lalapack

MAN1=	mpb.1 mpb-data.1 mpb-split.1

post-patch:
	@${REINPLACE_CMD} -e 's|-lhdf5 |-lhdf5 ${PTHREAD_LIBS} |g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
