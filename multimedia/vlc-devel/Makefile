# New ports collection makefile for:	vlc
# Date created:		3rd August 2001
# Whom:			Brian Somers <brian@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vlc
PORTVERSION=	0.6.2
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.videolan.org/pub/videolan/vlc/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X11 video streaming client/server solution

LIB_DEPENDS=	dvdcss.2:${PORTSDIR}/multimedia/libdvdcss \
		dvdread.3:${PORTSDIR}/multimedia/libdvdread \
		mad.2:${PORTSDIR}/audio/mad \
		avcodec.0:${PORTSDIR}/multimedia/ffmpeg \
		a52.0:${PORTSDIR}/audio/liba52 \
		intl.5:${PORTSDIR}/devel/gettext \
		iconv.3:${PORTSDIR}/converters/libiconv \
		vorbis.2:${PORTSDIR}/audio/libvorbis \
		ogg.4:${PORTSDIR}/audio/libogg \
		FLAC.5:${PORTSDIR}/audio/flac \
		faad.0:${PORTSDIR}/audio/faad \
		wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk2 \
		slp.1:${PORTSDIR}/net/openslp

# After libmpeg2 release 0.3.2
#		mpeg2.0:${PORTSDIR}/multimedia/libmpeg2 \

USE_GETOPT_LONG=yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
USE_SDL=	yes
USE_XLIB=	yes

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PATH_GTKCONFIG="${GTK_CONFIG}" \
		CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS=-L${LOCALBASE}/lib WX_CONFIG=${X11BASE}/bin/wxgtk2-2.4-config
CONFIGURE_ARGS+=--with-dvdcss=${LOCALBASE} \
		--with-dvdread=${LOCALBASE} \
		--with-mad=${LOCALBASE} \
		--with-faad=${LOCALBASE} \
		--disable-dvbpsi \
		--with-a52=${LOCALBASE} \
		--enable-ffmpeg \
		--with-ffmpeg=${LOCALBASE} \
		--disable-libmpeg2 \
		--program-prefix="" \
		--without-libintl-prefix \
		--without-libiconv-prefix \

post-patch:
	@${REINPLACE_CMD} -e 's/-lc_r/${PTHREAD_LIBS}/' ${WRKSRC}/configure

.include <bsd.port.mk>
