PORTNAME=		gpac
DISTVERSIONPREFIX=	v
DISTVERSION=		2.4.0
CATEGORIES=		multimedia

MAINTAINER=		olivier@FreeBSD.org
COMMENT=		Framework for processing and streaming content
WWW=			https://gpac.io/

LICENSE=		LGPL21

USES=			gmake pkgconfig ssl

USE_GITHUB=		yes
GH_ACCOUNT=		gpac

CFLAGS+=		-I${WRKSRC}/include -I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix="${PREFIX}" --cc="${CC}" \
			--X11-path="${LOCALBASE}" \
			--extra-cflags="${CFLAGS}" --extra-ldflags="${LDFLAGS}"
MAKE_ENV+=		VERSION=${DISTVERSION}
USE_LDCONFIG=		yes
OPTIONS_DEFINE=		A52 CACA FAAD FFMPEG FREETYPE JPEG MAD NGHTTP2 OGG \
			OPENGL PNG SDL2 THEORA VORBIS X11 XVID
OPTIONS_DEFAULT=	JPEG PNG
OPTIONS_SUB=		yes

A52_LIB_DEPENDS=	liba52.so:audio/liba52
A52_CONFIGURE_OFF=	--use-a52=no
CACA_LIB_DEPENDS=	libcaca.so:graphics/libcaca
CACA_CONFIGURE_OFF=	--use-libcaca=no
FAAD_LIB_DEPENDS=	libfaad.so:audio/faad
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_OFF=	--use-ffmpeg=no
FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
FREETYPE_CONFIGURE_OFF=	--use-freetype=no
JPEG_USES=		jpeg
JPEG_CONFIGURE_ON=	--use-jpeg=system --use-openjpeg=no
JPEG_CONFIGURE_OFF=	--use-jpeg=no
MAD_LIB_DEPENDS=	libmad.so:audio/libmad
MAD_CONFIGURE_OFF=	--use-mad=no
NGHTTP2_DESC=		nghttp2 support
NGHTTP2_LIB_DEPENDS=	libnghttp2.so:www/libnghttp2
NGHTTP2_CONFIGURE_OFF=	--use-nghttp2=no
OGG_LIB_DEPENDS=	libogg.so:audio/libogg
OGG_CONFIGURE_OFF=	--use-ogg=no
OPENGL_USES=		gl
OPENGL_USE=		GL=gl,glu
PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_OFF=	--use-png=no
SDL2_DESC=		SDL2 support
SDL2_USES=		sdl
SDL2_USE=		SDL=sdl2
THEORA_LIB_DEPENDS=	libtheora.so:multimedia/libtheora
THEORA_CONFIGURE_OFF=	--use-theora=no
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis
VORBIS_CONFIGURE_OFF=	--use-vorbis=no
X11_USES=		xorg desktop-file-utils
X11_USE=		XORG=x11,xv,xext
X11_CONFIGURE_OFF=	--disable-x11 --disable-x11-shm --disable-x11-xv
XVID_LIB_DEPENDS=	libxvidcore.so:multimedia/xvid
XVID_CONFIGURE_OFF=	--use-xvid=no

CFLAGS_powerpc64le=	-fPIC

.include <bsd.port.mk>
