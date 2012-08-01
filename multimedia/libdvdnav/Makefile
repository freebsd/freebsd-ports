# New ports collection makefile for:    libdvdnav
# Date created:         21 May 2002
# Whom:                 MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	libdvdnav
PORTVERSION=	4.2.0
PORTREVISION=	1
CATEGORIES=	multimedia
# Svn repository URL : svn://svn.mplayerhq.hu/dvdnav/trunk/libdvdnav
MASTER_SITES=	http://dvdnav.mplayerhq.hu/releases/ \
		http://contribs.martymac.org/FreeBSD-ports/distfiles/ \
		LOCAL/martymac

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	MPlayer version of the libdvdnav project

LICENSE=	GPLv2

LIB_DEPENDS=	dvdread:${PORTSDIR}/multimedia/libdvdread

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure2
CONFIGURE_ARGS=	--prefix="${PREFIX}" \
		--libdir="${PREFIX}/lib" \
		--libdatadir="${PREFIX}/libdata/pkgconfig" \
		--shlibdir="${PREFIX}/lib" \
		--incdir="${PREFIX}/include/dvdnav" \
		--disable-opts \
		--cc="${CC}"
USE_GMAKE=	yes
CONFLICTS=	libdvdnav-mplayer-[0-9]*
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DEBUG

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug --disable-strip
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^threadlib="-lpthread"|threadlib="${PTHREAD_LIBS}"|g' \
		${WRKSRC}/configure2

.include <bsd.port.post.mk>
