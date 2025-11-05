PORTNAME=	tenacity
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4-alpha1
CATEGORIES=	multimedia

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Tenacity is an easy-to-use multi-track audio editor and recorder
WWW=		https://tenacityaudio.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	expat>0:textproc/expat2 \
		ffmpeg>0:multimedia/ffmpeg \
		flac>0:audio/flac \
		glib>0:devel/glib20 \
		lame>0:audio/lame \
		libid3tag>0:audio/libid3tag \
		libmatroska>0:multimedia/libmatroska \
		libsndfile>0:audio/libsndfile \
		libsoxr>0:audio/libsoxr \
		libzip>0:archivers/libzip \
		lilv>0:audio/lilv \
		lv2>0:audio/lv2 \
		mpg123>0:audio/mpg123 \
		nasm>=0:devel/nasm \
		opus>0:audio/opus \
		opusfile>0:audio/opusfile \
		portaudio>0:audio/portaudio \
		portmidi>0:audio/portmidi \
		rapidjson>0:devel/rapidjson \
		soundtouch>0:audio/soundtouch \
		suil>0:audio/suil \
		twolame>0:audio/twolame \
		vamp-plugin-sdk>0:audio/vamp-plugin-sdk \
		wavpack>0:audio/wavpack \
		wx32-gtk3>0:x11-toolkits/wxgtk32 \
		zam-plugins-lv2>0:audio/zam-plugins-lv2

LIB_DEPENDS=	libatk-1.0.so:accessibility/at-spi2-core \
		libexpat.so:textproc/expat2 \
		libharfbuzz.so:print/harfbuzz \
		liblilv-0.so:audio/lilv \
		libportaudio.so:audio/portaudio \
		libsndfile.so:audio/libsndfile \
		libSoundTouch.so:audio/soundtouch \
		libsoxr.so:audio/libsoxr \
		libsuil-0.so:audio/suil \
		libvamp-hostsdk.so:audio/vamp-plugin-sdk \
		libwx_baseu-3.2.so:x11-toolkits/wxgtk32 \
		libwx_baseu_net-3.2.so:x11-toolkits/wxgtk32 \
		libwx_gtk3u_core-3.2.so:x11-toolkits/wxgtk32 \
		libwx_gtk3u_html-3.2.so:x11-toolkits/wxgtk32 \
		libwx_gtk3u_qa-3.2.so:x11-toolkits/wxgtk32

USES=		cmake desktop-file-utils gettext-runtime gnome localbase \
		pkgconfig sqlite

USE_GITHUB=	yes
GH_ACCOUNT=	tenacityteam
GH_TUPLE=	Martinfx:libnyquist:a76cd38:libnyquist/lib-src/libnyquist

USE_GNOME=	cairo gdkpixbuf glib20 gtk30 pango

CMAKE_OFF=	LIBNYQUIST_BUILD_EXAMPLE

OPTIONS_DEFINE_amd64=	AVX AVX2 AVX512

AVX_DESC=	Enable AVX (x86_64 only)
AVX2_DESC=	Enable AVX2 (x86_64 only)
AVX512_DESC=	Enable AVX512 (x86_64 only)

AVX_CMAKE_BOOL=		AVX
AVX2_CMAKE_BOOL=	AVX2
AVX512_CMAKE_BOOL=	AVX512

.include <bsd.port.options.mk>

.if ${ARCH} == i386
CFLAGS+=	-msse2
CXXFLAGS+=	-msse2 # fixes error: always_inline function '_mm_unpacklo_ps' requires target feature 'sse', but would be inlined into function 'pffft_zreorder' that is compiled without support for 'sse'
.endif

.include <bsd.port.mk>
