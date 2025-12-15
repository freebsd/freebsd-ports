PORTNAME=	dino
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.1
PORTREVISION=	1
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
		libsoup-3.0.so:devel/libsoup3 \
		libsqlite3.so:databases/sqlite3 \
		libsrtp2.so:net/libsrtp2 \
		libvulkan.so:graphics/vulkan-loader

USES=		meson cpe desktop-file-utils gettext-tools gnome localbase \
		ninja pkgconfig vala:build

USE_GITHUB=	yes

OPTIONS_DEFINE=		CANBERRA GNUPG ICE OMEMO RTP UPLOAD
OPTIONS_DEFAULT=	CANBERRA GNUPG ICE OMEMO RTP UPLOAD
OPTIONS_SUB=		yes

HAS_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
LDFLAGS+=	-Wl,--export-dynamic
USE_LDCONFIG=	yes

#USE_GNOME=	cairo gdkpixbuf glib20 gnomeprefix gtk40 intlhack
USE_GNOME=	cairo gdkpixbuf glib20 gtk40 intlhack

CANBERRA_DESC=	Notifications sounds support
ICE_DESC=		ICE NAT traversal plugin
OMEMO_DESC=		OMEMO plugin
RTP_DESC=		RTP plugin
UPLOAD_DESC=		HTTP file upload plugin
ICE_LIB_DEPENDS=	libgnutls.so:security/gnutls \
			libnice.so:net-im/libnice
ICE_VARS=		ENABLED_PLUGINS+=plugin-ice
ICE_VARS_OFF=		DISABLED_PLUGINS+=plugin-ice
RTP_LIB_DEPENDS=	libgnutls.so:security/gnutls \
			libwebrtc-audio-processing.so:audio/webrtc-audio-processing
RTP_USES=		gstreamer
RTP_USE=		GSTREAMER=gtk,opus,pulse,speex,srtp,v4l2,vpx,x264
RTP_VARS=		ENABLED_PLUGINS+= plugin-rtp plugin-rtp-h264 plugin-rtp-msdk \
			plugin-rtp-vaapi plugin-rtp-vp9 plugin-rtp-webrtc-audio-processing
RTP_VARS_OFF=		DISABLED_PLUGINS+=plugin-rtp plugin-rtp-h264 plugin-rtp-msdk \
			plugin-rtp-vaapi plugin-rtp-vp9 plugin-rtp-webrtc-audio-processing
OMEMO_LIB_DEPENDS=	libqrencode.so:graphics/libqrencode \
			libomemo-c.so:security/libomemo-c
OMEMO_VARS=		ENABLED_PLUGINS+=plugin-omemo
OMEMO_VARS_OFF=		DISABLED_PLUGINS+=plugin-omemo
UPLOAD_MESON_ON=	-DSOUP_VERSION:INT=2
UPLOAD_VARS=		ENABLED_PLUGINS+=plugin-http-files
UPLOAD_VARS_OFF=	DISABLED_PLUGINS+=plugin-http-files
GNUPG_LIB_DEPENDS=	libgpgme.so:security/gpgme
GNUPG_VARS=		ENABLED_PLUGINS+=plugin-openpgp
GNUPG_VARS_OFF=		DISABLED_PLUGINS+=plugin-openpgp
CANBERRA_VARS=		ENABLED_PLUGINS+=plugin-notification-sound
CANBERRA_VARS_OFF=	DISABLED_PLUGINS+=plugin-notification-sound
CANBERRA_LIB_DEPENDS=	libcanberra.so:audio/libcanberra

OPT_MESON_ENABLED=	"${ENABLED_PLUGINS}"
OPT_MESON_DISABLED=	"${DISABLED_PLUGINS}"

pre-configure:
	@if [ -z "${PACKAGE_BUILDING}" ]; then if ! ${PKG_BIN} query \
			'%o-%Ok-%Od' databases/sqlite3 | \
			${GREP} -F -wq databases/sqlite3-UNICODE61-on; then \
		${ECHO_MSG} "/!\ Please make sure databases/sqlite3 is built\
			       with UNICODE61 option"; \
	exit 1; \
	fi; fi

.include <bsd.port.mk>
