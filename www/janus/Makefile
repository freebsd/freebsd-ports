PORTNAME=	janus
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.2
PORTREVISION=	0
CATEGORIES=	www

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	WebRTC gateway
WWW=		https://github.com/meetecho/janus-gateway

LICENSE=	GPLv3

BUILD_DEPENDS=	gengetopt>0:devel/gengetopt
LIB_DEPENDS=	libconfig.so:devel/libconfig \
		libcurl.so:ftp/curl \
		libjansson.so:devel/jansson \
		libmicrohttpd.so:www/libmicrohttpd \
		libnice.so:net-im/libnice \
		libogg.so:audio/libogg \
		libopus.so:audio/opus \
		libsofia-sip-ua.so:net/sofia-sip \
		libsrtp2.so:net/libsrtp2 \
		libusrsctp.so:net/libusrsctp \
		libwebsockets.so:net/libwebsockets

USES=			autoreconf cpe gmake gnome libtool localbase pkgconfig \
			ssl
USE_GNOME=		glib20
USE_GITHUB=		yes
GH_ACCOUNT=		meetecho
GH_PROJECT=		janus-gateway
CPE_VENDOR=		meetecho
USE_RC_SUBR=		janus
CONFIGURE_ARGS+=	--disable-mqtt \
			--disable-rabbitmq \
			--enable-data-channels \
			--enable-json-logger \
			--libdir=${PREFIX}/libexec
INSTALL_TARGET=		install-strip
CFLAGS+=		-I${OPENSSLINC} -I${LOCALBASE}/include/nice
LDFLAGS+=		-L${OPENSSLLIB} -lcrypto -lssl -L${LOCALBASE} -lnice
GNU_CONFIGURE=		yes
USE_LDCONFIG=		yes
SUB_FILES=		pkg-message
PLIST_SUB+= 		SOVERSION=2.0.7

OPTIONS_SUB=				yes
OPTIONS_DEFINE=				JAVASCRIPT LUA MQTT NANOMSG \
					POSTPROCESSING RABBITMQ
JAVASCRIPT_DESC=			JavaScript scripting language support
MQTT_DESC=				MQTT integration
NANOMSG_DESC=				Nanomsg integration
RABBITMQ_DESC=				RabbitMQ integration
POSTPROCESSING_DESC=			Post processing integration
JAVASCRIPT_LIB_DEPENDS=			libduktape.so:lang/duktape-lib
MQTT_LIB_DEPENDS=			libpaho-mqtt3c.so:net/libpaho-mqtt3
NANOMSG_LIB_DEPENDS=			libnanomsg.so:net/nanomsg
RABBITMQ_LIB_DEPENDS=			librabbitmq.so:net/rabbitmq-c
JAVASCRIPT_CONFIGURE_ENABLE=		plugin-duktape
NANOMSG_CONFIGURE_ENABLE=		nanomsg
RABBITMQ_CONFIGURE_ENABLE=		rabbitmq
LUA_CONFIGURE_ENABLE=			plugin-lua
LUA_USES=				lua
LUA_CONFIGURE_ENV=			LUA_CFLAGS="-I${LUA_INCDIR}" \
					LUA_LIBS="-L${LUA_LIBDIR} -llua-${LUA_VER}"
POSTPROCESSING_CONFIGURE_ENABLE=	post-processing
POSTPROCESSING_LIB_DEPENDS=		libavcodec.so:multimedia/ffmpeg

.include <bsd.port.mk>
