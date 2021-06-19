# Created by: alex

PORTNAME=	xine
DISTVERSION=	1.2.11
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-lib/${PORTVERSION}
PKGNAMEPREFIX=	lib
DISTNAME=	${PORTNAME}-lib-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libraries for xine multimedia player

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libFLAC.so:audio/flac \
		liba52.so:audio/liba52 \
		libvorbis.so:audio/libvorbis \
		libspeex.so:audio/speex \
		libmng.so:graphics/libmng \
		libpng.so:graphics/png \
		libdvdread.so:multimedia/libdvdread \
		libfreetype.so:print/freetype2 \
		libfame.so:multimedia/libfame \
		libcdio_paranoia.so:sysutils/libcdio-paranoia \
		libmodplug.so:audio/libmodplug \
		libvcdinfo.so:multimedia/vcdimager \
		libtheora.so:multimedia/libtheora \
		libmad.so:audio/libmad \
		libdca.so:multimedia/libdca \
		libavcodec.so:multimedia/ffmpeg \
		libfaad.so:audio/faad \
		libvdpau.so:multimedia/libvdpau \
		libvpx.so:multimedia/libvpx \
		libiso9660.so:sysutils/libcdio \
		libogg.so:audio/libogg \
		libdvdnav.so:multimedia/libdvdnav

USES=		compiler cpe gl gmake gnome iconv libtool:keepla jpeg \
		localbase pathfix perl5 pkgconfig tar:xz xorg
LLD_UNSAFE=	yes
CPE_PRODUCT=	xine-lib
CPE_VENDOR=	xine
GNU_CONFIGURE=	yes
USE_XORG=	x11 xcb xv xinerama xext sm ice
USE_GL=		gl glu
USE_PERL5=	build
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-libflac \
		--enable-musepack \
		--enable-real-codecs \
		--without-esound

MAKE_ENV=	V=1
MAKE_ARGS=	pkgdatadir="${DATADIR}" \
		datadir="${DATADIR}" \
		libdir="${PREFIX}/lib"

CFLAGS_i386=	-fomit-frame-pointer

DOCSDIR=	${PREFIX}/share/doc/xine-lib
# Please sync with XINE_PLUGINSDIR in multimedia/xine
# and multimedia/vdr-plugin-xineliboutput
PLUGINSDIR=	lib/xine/plugins/2.9
PLIST_SUB=	PLUGINSDIR="${PLUGINSDIR}"

OPTIONS_DEFINE=		AALIB ALSA AOM CACA DAV1D DOCS DMX_IMAGE DVB \
			IMAGEMAGICK IPV6 JACK LIBBLURAY NFS NLS PIXBUF PULSEAUDIO \
			SDL SFTP SMB SNDIO V4L VAAPI WAVPACK WAYLAND XVMC
OPTIONS_DEFAULT=	DVB OPENSSL PIXBUF VAAPI
OPTIONS_DEFINE_i386=	W32DLL
OPTIONS_DEFAULT_i386=	W32DLL
OPTIONS_GROUP=		TLS
OPTIONS_GROUP_TLS=	GNUTLS OPENSSL
OPTIONS_SUB=		yes

AOM_DESC=		Enable libaom AV1 decoder support
DAV1D_DESC=		Enable dav1d AV1 decoder support
DMX_IMAGE_DESC=		DMX image plugin
DVB_DESC=		DVB plugin
NFS_DESC=		Enable NFS support using libnfs
SDL_DESC=		Enable support for SDL 1 video output
SFTP_DESC=		Enable SFTP support using libssh2
TLS_DESC=		Enable TLS support for https and ftps
W32DLL_DESC=		Win32 codec support
WAYLAND_DESC=		Enable Wayland support

AALIB_LIB_DEPENDS=		libaa.so:graphics/aalib
AALIB_CONFIGURE_ENABLE=		aalib
ALSA_LIB_DEPENDS=		libasound.so:audio/alsa-lib
ALSA_CONFIGURE_WITH=		alsa
AOM_LIB_DEPENDS=		libaom.so:multimedia/aom
AOM_CONFIGURE_WITH=		libaom
CACA_LIB_DEPENDS=		libcaca.so:graphics/libcaca
CACA_CONFIGURE_WITH=		caca
DAV1D_LIB_DEPENDS=		libdav1d.so:multimedia/dav1d
DAV1D_CONFIGURE_WITH=		dav1d
DVB_BUILD_DEPENDS=		v4l_compat>=1.0.20100321:multimedia/v4l_compat
DVB_CONFIGURE_ENABLE=		dvb
GNUTLS_LIB_DEPENDS=		libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_ON=		--enable-tls
IMAGEMAGICK_LIB_DEPENDS=	libMagickWand-${IMAGEMAGICK_DEFAULT}.so:graphics/ImageMagick${IMAGEMAGICK_DEFAULT}
IMAGEMAGICK_CONFIGURE_WITH=	imagemagick
IMAGEMAGICK_IMPLIES=		DMX_IMAGE
IPV6_CONFIGURE_ENABLE=		ipv6
JACK_LIB_DEPENDS=		libjack.so:audio/jack
JACK_CONFIGURE_WITH=		jack
LIBBLURAY_LIB_DEPENDS=		libbluray.so:multimedia/libbluray
LIBBLURAY_CONFIGURE_ENABLE=	bluray
NLS_USES=			gettext
NLS_CONFIGURE_ENABLE=		nls
NFS_LIB_DEPENDS=		libnfs.so:net/libnfs
NFS_CONFIGURE_ENABLE=		nfs
OPENSSL_CONFIGURE_ON=		--enable-tls
OPENSSL_CONFIGURE_ENV=		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl" \
				OPENSSL_CFLAGS="-I${OPENSSLINC}"
OPENSSL_USES=			ssl
PIXBUF_CONFIGURE_ENABLE=	gdkpixbuf
PIXBUF_IMPLIES=			DMX_IMAGE
PIXBUF_USE=			GNOME=gdkpixbuf2,glib20
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_WITH=	pulseaudio
SDL_CONFIGURE_WITH=		sdl
SDL_USES=			sdl
SDL_USE=			SDL=sdl
SFTP_LIB_DEPENDS=		libssh2.so:security/libssh2
SFTP_CONFIGURE_ENABLE=		sftp
SMB_USES=			samba:lib
SMB_CONFIGURE_ENV=		LIBSMBCLIENT_LIBS="-L${SAMBALIBS} -lsmbclient" \
				LIBSMBCLIENT_CFLAGS="-I${SAMBAINCLUDES}"
SMB_CONFIGURE_ENABLE=		samba
SNDIO_LIB_DEPENDS=		libsndio.so:audio/sndio
SNDIO_CONFIGURE_ENABLE=		sndio
VAAPI_LIB_DEPENDS=		libva.so:multimedia/libva \
				libva-glx.so:multimedia/libva-glx
VAAPI_CONFIGURE_ENABLE=		vaapi
V4L_BUILD_DEPENDS=		v4l_compat>=1.0.20100321:multimedia/v4l_compat
V4L_LIB_DEPENDS=		libv4l2.so:multimedia/libv4l
V4L_CONFIGURE_ENABLE=		libv4l v4l v4l2
W32DLL_CONFIGURE_ENABLE=	w32dll
W32DLL_PLIST_FILES=		${PLUGINSDIR}/xineplug_decode_w32dll.so
WAVPACK_LIB_DEPENDS=		libwavpack.so:audio/wavpack
WAVPACK_CONFIGURE_WITH=		wavpack
WAYLAND_LIB_DEPENDS=		libwayland-egl.so:graphics/wayland \
				libwayland-client.so:graphics/wayland
WAYLAND_CONFIGURE_ENABLE=	wayland

.if defined(WITH_NVIDIA304_GL) || exists(${LOCALBASE}/lib/libXvMCNVIDIA.so.1)
XVMC_CONFIGURE_WITH=		xvmc-lib=XvMCNVIDIA
XVMC_LIB_DEPENDS=		libXvMCNVIDIA.so:x11/nvidia-driver-304
.else
XVMC_CONFIGURE_WITH=		xvmc-lib=XvMCW
XVMC_LIB_DEPENDS=		libXvMC.so:x11/libXvMC
.endif
XVMC_CONFIGURE_ENABLE=		xvmc

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64
BUILD_DEPENDS+=	as:devel/binutils
.elif ${ARCH} == powerpc
BUILD_DEPENDS+=	as:devel/binutils
CFLAGS+=	-fno-integrated-as
.endif

.if !${PORT_OPTIONS:MGNUTLS} && !${PORT_OPTIONS:MOPENSSL}
CONFIGURE_ARGS+=	--disable-tls
.endif

pre-configure-GNUTLS-off:
	@${REINPLACE_CMD} -e 's|have_gnutls=yes|have_gnutls=no|' \
		${WRKSRC}/configure

post-patch:
.if ${COMPILER_TYPE} == "clang"
	@${REINPLACE_CMD} -e 's|-fno-rename-registers||' \
		${WRKSRC}/src/libw32dll/Makefile.in
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${PLUGINSDIR}/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${PLUGINSDIR}/post/*.so

.include <bsd.port.post.mk>
