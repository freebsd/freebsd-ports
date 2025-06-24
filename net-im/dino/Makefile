PORTNAME=	dino
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.5
PORTREVISION=	2
CATEGORIES=	net-im

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Modern XMPP Chat Client using GTK/Vala
WWW=		https://dino.im

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libadwaita-1.so:x11-toolkits/libadwaita \
		libassuan.so:security/libassuan \
		libgcrypt.so:security/libgcrypt \
		libgee-0.8.so:devel/libgee \
		libgpg-error.so:security/libgpg-error \
		libgraphene-1.0.so:graphics/graphene \
		libgspell-1.so:textproc/gspell \
		libharfbuzz.so:print/harfbuzz \
		libicuuc.so:devel/icu \
		libsoup-2.4.so:devel/libsoup \
		libsqlite3.so:databases/sqlite3 \
		libsrtp2.so:net/libsrtp2 \
		libvulkan.so:graphics/vulkan-loader

USES=		cmake cpe desktop-file-utils gettext-tools gnome localbase \
		ninja pkgconfig vala:build

USE_GITHUB=	yes

OPTIONS_DEFINE=		CANBERRA GNUPG ICE OMEMO RTP UPLOAD
OPTIONS_DEFAULT=	CANBERRA GNUPG ICE OMEMO RTP UPLOAD
OPTIONS_SUB=		yes

HAS_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
LDFLAGS+=	-Wl,--export-dynamic
USE_LDCONFIG=	yes

USE_GNOME=	cairo gdkpixbuf glib20 gnomeprefix gtk40 intlhack

CANBERRA_DESC=	Notifications sounds support
ICE_DESC=		ICE NAT traversal plugin
OMEMO_DESC=		OMEMO plugin
RTP_DESC=		RTP plugin
UPLOAD_DESC=		HTTP file upload plugin
ICE_LIB_DEPENDS=	libgnutls.so:security/gnutls \
			libnice.so:net-im/libnice
ICE_VARS=		ENABLED_PLUGINS+=ice
ICE_VARS_OFF=		DISABLED_PLUGINS+=ice
RTP_LIB_DEPENDS=	libgnutls.so:security/gnutls \
			libwebrtc_audio_processing.so:audio/webrtc-audio-processing0
RTP_USES=		gstreamer
RTP_USE=		GSTREAMER=gtk,opus,pulse,speex,srtp,v4l2,vpx,x264
RTP_VARS=		ENABLED_PLUGINS+=rtp
RTP_CMAKE_BOOL=		RTP_ENABLE_H264 RTP_ENABLE_VP9 RTP_ENABLE_H264 RTP_ENABLE_VAAPI
RTP_VARS_OFF=		DISABLED_PLUGINS+=rtp
OMEMO_GH_TUPLE=		signalapp:libsignal-protocol-c:v2.3.3:signalapp/plugins/signal-protocol/libsignal-protocol-c
OMEMO_LIB_DEPENDS=	libqrencode.so:graphics/libqrencode
OMEMO_VARS=		ENABLED_PLUGINS+=omemo
OMEMO_CMAKE_BOOL=	BUILD_LIBSIGNAL_IN_TREE
OMEMO_VARS_OFF=		DISABLED_PLUGINS+=omemo
UPLOAD_CMAKE_ON=	-DSOUP_VERSION:INT=2
UPLOAD_VARS=		ENABLED_PLUGINS+=http-files
UPLOAD_VARS_OFF=	DISABLED_PLUGINS+=http-files
GNUPG_LIB_DEPENDS=	libgpgme.so:security/gpgme
GNUPG_VARS=		ENABLED_PLUGINS+=openpgp
GNUPG_VARS_OFF=		DISABLED_PLUGINS+=openpgp
CANBERRA_VARS=		ENABLED_PLUGINS+=notification-sound
CANBERRA_VARS_OFF=	DISABLED_PLUGINS+=notification-sound
CANBERRA_LIB_DEPENDS=	libcanberra.so:audio/libcanberra

CMAKE_ARGS+=	-DENABLED_PLUGINS="${ENABLED_PLUGINS:S/ /;/gW}"
CMAKE_ARGS+=	-DDISABLED_PLUGINS="${DISABLED_PLUGINS:S/ /;/gW}"

pre-configure:
	@if [ -z "${PACKAGE_BUILDING}" ]; then if ! ${PKG_BIN} query \
			'%o-%Ok-%Od' databases/sqlite3 | \
			${GREP} -F -wq databases/sqlite3-UNICODE61-on; then \
		${ECHO_MSG} "/!\ Please make sure databases/sqlite3 is built\
			       with UNICODE61 option"; \
	exit 1; \
	fi; fi

.include <bsd.port.mk>
