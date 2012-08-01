# New ports collection makefile for:	libdvdread
# Date created:				24 Jun 2001
# Whom:					Marc van Woerkom <3d@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	libdvdread
PORTVERSION=	4.2.0
PORTREVISION=	2
CATEGORIES=	multimedia
# Svn repository URL : svn://svn.mplayerhq.hu/dvdnav/trunk/libdvdread
MASTER_SITES=	http://dvdnav.mplayerhq.hu/releases/ \
		http://contribs.martymac.org/FreeBSD-ports/distfiles/ \
		LOCAL/martymac

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	MPlayer version of the libdvdread project

LICENSE=	GPLv2

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure2
CONFIGURE_ARGS=	--prefix="${PREFIX}" \
		--libdir="${PREFIX}/lib" \
		--libdatadir="${PREFIX}/libdata/pkgconfig" \
		--shlibdir="${PREFIX}/lib" \
		--incdir="${PREFIX}/include/dvdread" \
		--disable-opts \
		--cc="${CC}"
USE_GMAKE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DVDCSS DEBUG
.if !defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT=	DVDCSS
.endif

# DVDCSS version hardcoded in src/dvd_input.c (dlopen'ed)
DVDCSS_LIBVERSION=	3

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDVDCSS}
LIB_DEPENDS+=	dvdcss:${PORTSDIR}/multimedia/libdvdcss
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug --disable-strip
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl ||g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -E -e 's|(libdvdcss.so)\.2|\1.${DVDCSS_LIBVERSION}|' \
		${WRKSRC}/src/dvd_input.c

.include <bsd.port.post.mk>
