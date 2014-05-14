# Created by: Marc van Woerkom <3d@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libdvdread
PORTVERSION=	4.9.9
CATEGORIES=	multimedia
MASTER_SITES=	http://dvdnav.mplayerhq.hu/releases/ \
		http://contribs.martymac.org/FreeBSD-ports/distfiles/ \
		LOCAL/martymac

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	MPlayer version of the libdvdread project

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=	tar:xz gmake pkgconfig:build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DVDCSS
.if !defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT=	DVDCSS
.endif
DVDCSS_LIB_DEPENDS=	libdvdcss.so:${PORTSDIR}/multimedia/libdvdcss

# DVDCSS version hardcoded in src/dvd_input.c (dlopen'ed)
DVDCSS_LIBVERSION=	3

post-patch:
	@${REINPLACE_CMD} 's|^pkgconfigdir =.*|pkgconfigdir = ${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -E -e 's|(libdvdcss.so)\.2|\1.${DVDCSS_LIBVERSION}|' \
		${WRKSRC}/src/dvd_input.c

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libdvdread.so.5

.include <bsd.port.mk>
