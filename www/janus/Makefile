PORTNAME=	janus
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.4
CATEGORIES=	www

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	WebRTC gateway

LICENSE=	GPLv3

BUILD_DEPENDS=	gengetopt>0:devel/gengetopt
LIB_DEPENDS=	libsrtp2.so:net/libsrtp2 \
		libusrsctp.so:net/libusrsctp \
		libjansson.so:devel/jansson \
		libnice.so:net-im/libnice \
		libmicrohttpd.so:www/libmicrohttpd \
		libwebsockets.so:net/libwebsockets \
		libcurl.so:ftp/curl \
		libopus.so:audio/opus \
		libsofia-sip-ua.so:net/sofia-sip \
		libogg.so:audio/libogg \
		libjansson.so:devel/jansson \
		libnice.so:net-im/libnice \
		libmicrohttpd.so:www/libmicrohttpd \
		libwebsockets.so:net/libwebsockets \
		libconfig.so:devel/libconfig

USES=		libtool pkgconfig autoreconf cpe gmake localbase gnome ssl
USE_GNOME=	glib20
USE_GITHUB=	yes
GH_ACCOUNT=	meetecho
GH_PROJECT=	janus-gateway
CPE_VENDOR=	meetecho
USE_RC_SUBR=	janus
CONFIGURE_ARGS+=	--disable-mqtt \
		--disable-rabbitmq \
		--enable-json-logger \
		--enable-data-channels
INSTALL_TARGET=install-strip
CFLAGS+=	-I${OPENSSLINC} -I${LOCALBASE}/include/nice
LDFLAGS+=	-L${OPENSSLLIB} -lcrypto -lssl -L${LOCALBASE} -lnice
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
SUB_FILES=	pkg-message

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	JAVASCRIPT LUA NANOMSG RABBITMQ POSTPROCESSING
JAVASCRIPT_DESC=	JavaScript scripting language support
#MQTT_DESC=	MQTT integration
NANOMSG_DESC=	Nanomsg integration
RABBITMQ_DESC=	RabbitMQ integration
POSTPROCESSING_DESC=	Post processing integration
JAVASCRIPT_LIB_DEPENDS=	libduktape.so:lang/duktape-lib
NANOMSG_LIB_DEPENDS=	libnanomsg.so:net/nanomsg
RABBITMQ_LIB_DEPENDS=	librabbitmq.so:net/rabbitmq-c
JAVASCRIPT_CONFIGURE_ENABLE=	plugin-duktape
NANOMSG_CONFIGURE_ENABLE=	nanomsg
RABBITMQ_CONFIGURE_ENABLE=	rabbitmq
LUA_CONFIGURE_ENABLE=	plugin-lua
LUA_USES=	lua
LUA_CONFIGURE_ENV=	LUA_CFLAGS="-I${LUA_INCDIR}" LUA_LIBS="-L${LUA_LIBDIR} -llua-${LUA_VER}"
POSTPROCESSING_CONFIGURE_ENABLE=	post-processing
POSTPROCESSING_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

.include <bsd.port.mk>
