# New ports collection makefile for:	libdvdread
# Date created:				24 Jun 2001
# Whom:					Marc van Woerkom <3d@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	libdvdread
PORTVERSION=	4.1.3
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www1.mplayerhq.hu/MPlayer/releases/dvdnav/ \
		http://www2.mplayerhq.hu/MPlayer/releases/dvdnav/ \
		http://www3.mplayerhq.hu/MPlayer/releases/dvdnav/ \
		http://www4.mplayerhq.hu/MPlayer/releases/dvdnav/ \
		http://www5.mplayerhq.hu/MPlayer/releases/dvdnav/ \
		ftp://ftp1.mplayerhq.hu/MPlayer/releases/dvdnav/ \
		ftp://ftp2.mplayerhq.hu/MPlayer/releases/dvdnav/

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	MPlayer version of the libdvdread project

.if !defined(PACKAGE_BUILDING)
LIB_DEPENDS=	dvdcss.${DVDCSS_LIBVERSION}:${PORTSDIR}/multimedia/libdvdcss
.endif

USE_BZIP2=	yes
CFLAGS+=	"-I${LOCALBASE}/include"
LDFLAGS+=	"-L${LOCALBASE}/lib"
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure2
CONFIGURE_ARGS=	--prefix="${PREFIX}" \
		--libdir="${PREFIX}/lib" \
		--libdatadir="${PREFIX}/libdata/pkgconfig" \
		--shlibdir="${PREFIX}/lib" \
		--incdir="${PREFIX}/include/dvdread" \
		--disable-opts \
		--disable-debug \
		--extra-cflags="${CFLAGS}" \
		--extra-ldflags="${LDFLAGS}"
USE_GMAKE=	yes
USE_LDCONFIG=	yes

# DVDCSS version hardcoded in src/dvd_input.c (dlopen'ed)
DVDCSS_LIBVERSION=	3

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl ||g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -E -e 's|(libdvdcss.so)\.2|\1.${DVDCSS_LIBVERSION}|' \
		${WRKSRC}/src/dvd_input.c

.include <bsd.port.mk>
