# New ports collection makefile for:	vlc
# Date created:		3rd August 2001
# Whom:			Brian Somers <brian@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vlc
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://download.videolan.org/pub/videolan/vlc/${PORTVERSION}/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	An X11 video streaming client/server solution

LIB_DEPENDS=	dvdcss.2:${PORTSDIR}/multimedia/libdvdcss \
		dvdread.3:${PORTSDIR}/multimedia/libdvdread \
		mad.2:${PORTSDIR}/audio/mad \
		avcodec.0:${PORTSDIR}/multimedia/ffmpeg \
		a52.0:${PORTSDIR}/audio/liba52 \
		iconv.3:${PORTSDIR}/converters/libiconv \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		FLAC.5:${PORTSDIR}/audio/flac \
		faad.0:${PORTSDIR}/audio/faad \
		wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk2 \
		slp.1:${PORTSDIR}/net/openslp
.if defined(WITH_LIBDVBPSI)
LIB_DEPENDS+=	dvbpsi.3:${PORTSDIR}/multimedia/libdvbpsi
.endif

# After libmpeg2 release 0.3.2
#		mpeg2.0:${PORTSDIR}/multimedia/libmpeg2 \

USE_GETOPT_LONG=yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
USE_SDL=	sdl
USE_XLIB=	yes
USE_GCC=	3.2

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PATH_GTKCONFIG="${GTK_CONFIG}" \
		CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS=-L${LOCALBASE}/lib WX_CONFIG=${X11BASE}/bin/wxgtk2-2.4-config
CONFIGURE_ARGS+=--with-dvdcss=${LOCALBASE} \
		--with-dvdread=${LOCALBASE} \
		--with-mad=${LOCALBASE} \
		--with-faad=${LOCALBASE} \
		--with-a52=${LOCALBASE} \
		--enable-ffmpeg \
		--with-ffmpeg=${LOCALBASE} \
		--disable-libmpeg2 \
		--disable-libcdio \
		--disable-libcddb \
		--program-prefix="" \
		--without-libintl-prefix \
		--without-libiconv-prefix \

.if defined(WITH_LIBDVBPSI)
CONFIGURE_ARGS+=	--with-dvbpsi=${LOCALBASE}
PLIST_SUB+=		LIBDVBPSI=""
.else
CONFIGURE_ARGS+=	--disable-dvbpsi
PLIST_SUB+=		LIBDVBPSI="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/-lc_r/${PTHREAD_LIBS}/' ${WRKSRC}/configure

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
CONFIGURE_ENV+=		LIBS="-L/usr/lib -lcipher"
.endif

.if ${ARCH} == "amd64"
PLIST_SUB+=		MMX="@comment "
.else
PLIST_SUB+=		MMX=""
.endif

.include <bsd.port.post.mk>
