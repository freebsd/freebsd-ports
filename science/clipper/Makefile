# $FreeBSD$

PORTNAME=	clipper
DISTVERSION=	2.1.20180802
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	https://www2.mrc-lmb.cam.ac.uk/personal/pemsley/coot/dependencies/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Libraries for the organisation of crystallographic data

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libccp4c.so:science/libccp4 \
		libmmdb2.so:science/mmdb2 \
		libsfftw.so:math/fftw-float

USES=		fortran gmake libtool localbase:ldflags
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --disable-static \
		--enable-phs --enable-cns --enable-mmdb --enable-minimol --enable-cif --enable-ccp4 --enable-fortran
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:C/\.[0-9]+$//}

.include <bsd.port.mk>
