# $FreeBSD$

PORTNAME=	linphone
PORTVERSION=	3.8.5
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	SAVANNAH/linphone/3.8.x/sources

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	SIP client supporting voice/video calls and text messaging

LIB_DEPENDS=	libbellesip.so:${PORTSDIR}/net/belle-sip \
		libmediastreamer_base.so:${PORTSDIR}/net/mediastreamer \
		libortp.so:${PORTSDIR}/net/ortp \
		libmbedtls.so.9:${PORTSDIR}/security/polarssl13 \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3

CONFLICTS_INSTALL=	linphone-base-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-deplibs-link --disable-silent-rules \
		--disable-speex --disable-strict --disable-tutorials \
		--enable-external-mediastreamer --enable-external-ortp \
		--enable-lime --with-polarssl=${LOCALBASE} \
		--with-readline=${LOCALBASE}
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
USES=		gettext-tools gmake iconv libtool pathfix pkgconfig \
		readline:port
USE_GNOME=	gtk20 intltool libxml2
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	LDAP NLS NOTIFY UPNP VIDEO
OPTIONS_DEFAULT=NOTIFY UPNP VIDEO
OPTIONS_SUB=	yes

LDAP_CONFIGURE_ENABLE=	ldap
LDAP_LIB_DEPENDS=	libsasl2.so:${PORTSDIR}/security/cyrus-sasl2
LDAP_USE=		OPENLDAP=yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

NOTIFY_CONFIGURE_ENABLE=notify
NOTIFY_LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify

UPNP_CONFIGURE_ENABLE=	upnp
UPNP_LIB_DEPENDS=	libupnp.so:${PORTSDIR}/devel/upnp

VIDEO_CONFIGURE_ENABLE=	video

.if defined(WITH_DEBUG) && !defined(WITHOUT_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif

post-patch:
.for l in C fr it ja
	@${REINPLACE_CMD} '/^install-data-local:/,/^$$/d' \
		${WRKSRC}/share/$l/Makefile.in
.endfor

.include <bsd.port.mk>
