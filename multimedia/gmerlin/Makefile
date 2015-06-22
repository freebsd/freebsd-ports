# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gmerlin
PORTVERSION=	1.2.0
PORTREVISION=	9
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multimedia framework

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexif.so:${PORTSDIR}/graphics/libexif \
		libgavl.so:${PORTSDIR}/multimedia/gavl \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

USES=		gettext libtool makeinfo pathfix pkgconfig
USE_GNOME=	gtk20 libxml2
USE_XORG=	x11 xext xfixes xinerama xv
USE_GL=		gl
USE_SQLITE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_func_inotify_init=no
CONFIGURE_ARGS=	--disable-v4l --disable-v4l2 --disable-v4lconvert \
		--without-doxygen --with-cpuflags=none --disable-musicbrainz
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
INSTALL_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

INFO=		gmerlin

OPTIONS_DEFINE= 	ALSA CDDB CDIO ESOUND JACK JPEG LIBVISUAL \
			OPTIMIZED_CFLAGS PNG PULSEAUDIO QUICKTIME TIFF DOCS
OPTIONS_DEFAULT=	CDDB JACK JPEG LIBVISUAL \
			OPTIMIZED_CFLAGS PNG PULSEAUDIO QUICKTIME TIFF
OPTIONS_SUB=		yes

ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
ALSA_CONFIGURE_OFF=	--disable-alsa --disable-alsamixer
CDDB_LIB_DEPENDS=	libcddb.so:${PORTSDIR}/audio/libcddb
CDDB_CONFIGURE_OFF=	--disable-cddb
CDIO_LIB_DEPENDS=	libcdio.so:${PORTSDIR}/sysutils/libcdio
CDIO_CONFIGURE_OFF=	--disable-libcdio
ESOUND_USE=		gnome=esound
ESOUND_CONFIGURE_OFF=	--disable-esd
JACK_LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack
JACK_CONFIGURE_OFF=	--disable-jack
JPEG_USES=		jpeg
JPEG_CONFIGURE_OFF=	--disable-libjpeg
LIBVISUAL_LIB_DEPENDS=	libvisual-0.4.so:${PORTSDIR}/graphics/libvisual04
LIBVISUAL_CONFIGURE_OFF=--disable-libvisual
OPTIMIZED_CFLAGS_CFLAGS=-O3 -funroll-loops -fomit-frame-pointer -ffast-math
PNG_LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png
PNG_CONFIGURE_OFF=	--disable-libpng
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CONFIGURE_OFF=--disable-pulseaudio
QUICKTIME_LIB_DEPENDS=	libquicktime.so:${PORTSDIR}/multimedia/libquicktime
QUICKTIME_CONFIGURE_OFF=--disable-lqt
TIFF_LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff
TIFF_CONFIGURE_OFF=	--disable-libtiff

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCDIO}
BROKEN=	Fails to build with new libcdio
.endif

.if !(${OPSYS} == FreeBSD && ${OSVERSION} < 900033)
LDFLAGS+=	-Wl,--add-needed
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/LIBS/s|-ldl || ; \
		 s|-DGTK_DISABLE_DEPRECATED|| ; \
		 s|-O3.*-ffast-math||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|^texinfo_|#texinfo_|g' ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e \
		's|ln -sf $$(DESTDIR)|ln -sf |' ${WRKSRC}/icons/Makefile.in
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-ldl||g'

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
