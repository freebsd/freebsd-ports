# New ports collection makefile for:	vlc
# Date created:		3rd August 2001
# Whom:			Brian Somers <brian@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vlc
PORTVERSION=	0.6.0
CATEGORIES=	multimedia
MASTER_SITES=	http://www.videolan.org/pub/videolan/vlc/${PORTVERSION}/

MAINTAINER=	brian@FreeBSD.org
COMMENT=	An X11 video streaming client/server solution

LIB_DEPENDS=	dvdcss.2:${PORTSDIR}/multimedia/libdvdcss \
		dvdread.3:${PORTSDIR}/multimedia/libdvdread \
		mad.1:${PORTSDIR}/audio/mad \
		avcodec.0:${PORTSDIR}/multimedia/ffmpeg \
		a52.0:${PORTSDIR}/audio/liba52 \
		intl.4:${PORTSDIR}/devel/gettext \
		iconv.3:${PORTSDIR}/converters/libiconv \
		vorbis.2:${PORTSDIR}/audio/libvorbis \
		ogg.4:${PORTSDIR}/audio/libogg \
		FLAC.5:${PORTSDIR}/audio/flac \
		faad.0:${PORTSDIR}/audio/faad \
		wx_gtk.2:${PORTSDIR}/x11-toolkits/wxgtk-devel \
		slp.1:${PORTSDIR}/net/openslp

# After libmpeg2 release 0.3.2
#		mpeg2.0:${PORTSDIR}/multimedia/libmpeg2 \

USE_XLIB=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	PATH_GTKCONFIG="${GTK_CONFIG}"
CONFIGURE_ARGS+=--with-dvdcss=${LOCALBASE} \
		--with-dvdread=${LOCALBASE} \
		--with-mad=${LOCALBASE} \
		--with-faad=${LOCALBASE} \
		--disable-dvbpsi \
		--with-a52=${LOCALBASE} \
		--enable-ffmpeg \
		--with-ffmpeg=${LOCALBASE} \
		--disable-libmpeg2 \
		--without-libintl-prefix \
		--without-libiconv-prefix

# dirty
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_GNOME=	gtk12
USE_GMAKE=	yes

.include <bsd.port.mk>
