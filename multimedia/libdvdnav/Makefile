# Created by: MANTANI Nobutaka <nobutaka@nobutaka.com>
# $FreeBSD$

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

LIB_DEPENDS=	libdvdread.so:${PORTSDIR}/multimedia/libdvdread

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
USES=	gmake
CONFLICTS=	libdvdnav-mplayer-[0-9]*
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DEBUG
DEBUG_CONFIGURE_ON=	--enable-debug --disable-strip
DEBUG_CONFIGURE_OFF=	--disable-debug --enable-strip

post-patch:
	@${REINPLACE_CMD} -e 's|^threadlib="-lpthread"|threadlib="${PTHREAD_LIBS}"|g' \
		${WRKSRC}/configure2

.include <bsd.port.mk>
