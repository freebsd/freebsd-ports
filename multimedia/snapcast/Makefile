PORTNAME=	snapcast
DISTVERSIONPREFIX=	v
DISTVERSION=	0.31.0-107
DISTVERSIONSUFFIX=	-g0fa5fdda
CATEGORIES=	multimedia audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multiroom client-server audio player
WWW=		https://github.com/badaix/snapcast

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/boost/asio.hpp:devel/boost-libs
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libavahi-common.so:net/avahi-app \
		libexpat.so:textproc/expat2 \
		libFLAC.so:audio/flac \
		libjack.so:audio/jack \
		libogg.so:audio/libogg \
		libopus.so:audio/opus \
		libvorbis.so:audio/libvorbis \
		libsoxr.so:audio/libsoxr

USES=		cmake compiler:c++17-lang pkgconfig python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	badaix

SHEBANG_FILES=	server/etc/plug-ins/meta_mpd.py server/etc/plug-ins/meta_mopidy.py \
		server/etc/plug-ins/meta_librespot-java.py

OPTIONS_DEFINE=		CLIENT
OPTIONS_DEFAULT=	#CLIENT
OPTIONS_SUB=		yes

CLIENT_DESC=		Build and install client in addition to server
CLIENT_CMAKE_BOOL=	BUILD_CLIENT
CLIENT_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
CLIENT_BROKEN=		Snapclient not yet supported for FreeBSD (according to CMakeLists.txt) # see https://github.com/badaix/snapcast/issues/1098

post-install: # workaround for https://github.com/badaix/snapcast/issues/1021
	@${CHMOD} +r ${STAGEDIR}${PREFIX}/share/snapserver/plug-ins/meta_mpd.py

.include <bsd.port.mk>
