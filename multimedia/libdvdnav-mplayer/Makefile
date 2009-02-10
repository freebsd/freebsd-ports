# New ports collection makefile for: libdvdnav-mplayer
# Date created:                      11 August 2008
# Whom:                              Ganael Laplanche <ganael.laplanche@martymac.com>
#
# $FreeBSD$
#

PORTNAME=	libdvdnav-mplayer
PORTVERSION=	4.1.3
CATEGORIES=	multimedia
MASTER_SITES=	http://www1.mplayerhq.hu/MPlayer/releases/dvdnav/ \
		http://www2.mplayerhq.hu/MPlayer/releases/dvdnav/ \
		http://www3.mplayerhq.hu/MPlayer/releases/dvdnav/ \
		http://www4.mplayerhq.hu/MPlayer/releases/dvdnav/ \
		http://www5.mplayerhq.hu/MPlayer/releases/dvdnav/ \
		ftp://ftp1.mplayerhq.hu/MPlayer/releases/dvdnav/ \
		ftp://ftp2.mplayerhq.hu/MPlayer/releases/dvdnav/
DISTNAME=	libdvdnav-${PORTVERSION}

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	MPlayer version of the libdvdnav project

LIB_DEPENDS=	dvdread.4:${PORTSDIR}/multimedia/libdvdread

USE_BZIP2=	yes
CFLAGS+=	"-I${LOCALBASE}/include"
LDFLAGS+=	"-L${LOCALBASE}/lib"
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure2
CONFIGURE_ARGS=	--prefix="${PREFIX}" \
		--libdir="${PREFIX}/lib" \
		--libdatadir="${PREFIX}/libdata/pkgconfig" \
		--shlibdir="${PREFIX}/lib" \
		--incdir="${PREFIX}/include/dvdnav" \
		--disable-opts \
		--disable-debug \
		--extra-cflags="${CFLAGS}" \
		--extra-ldflags="${LDFLAGS}"
USE_GMAKE=	yes
CONFLICTS=	libdvdnav-[0-9]*
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl ||g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|^threadlib="-lpthread"|threadlib="${PTHREAD_LIBS}"|g' \
		${WRKSRC}/configure2

.include <bsd.port.mk>
