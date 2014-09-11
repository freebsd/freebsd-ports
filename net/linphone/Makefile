# $FreeBSD$

PORTNAME=	linphone
PORTVERSION=	3.7.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	SAVANNAH/linphone/3.7.x/sources

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SIP client supporting voice/video calls and text messaging

LIB_DEPENDS=	libbellesip.so:${PORTSDIR}/net/belle-sip \
		libmediastreamer_base.so:${PORTSDIR}/net/mediastreamer \
		libortp.so:${PORTSDIR}/net/ortp \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3

CONFLICTS_INSTALL=	linphone-base-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-deplibs-link --disable-strict --disable-tutorials \
		--enable-external-mediastreamer --enable-external-ortp \
		--with-readline=${LOCALBASE}
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
USES=		gmake libtool pathfix pkgconfig readline:port
USE_GNOME=	gnomehier gtk20 intltool libxml2
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	IPV6 NLS NOTIFY UPNP VIDEO
OPTIONS_DEFAULT=NOTIFY UPNP VIDEO
OPTIONS_SUB=	yes

IPV6_CONFIGURE_ENABLE=	ipv6
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

NOTIFY_CONFIGURE_ENABLE=notify
NOTIFY_LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify

UPNP_CONFIGURE_ENABLE=	upnp
UPNP_LIB_DEPENDS=	libupnp.so:${PORTSDIR}/devel/upnp

VIDEO_CONFIGURE_ENABLE=	video

.if defined(WITH_DEBUG) && !defined(WITHOUT_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif

post-patch:
	@${REINPLACE_CMD} '/linphonec_LDADD =/s/=/= $$(MEDIASTREAMER_LIBS)/' \
		${WRKSRC}/console/Makefile.in
	@${REINPLACE_CMD} '/linphone_LDADD =/s/=/= $$(MEDIASTREAMER_LIBS)/' \
		${WRKSRC}/gtk/Makefile.in
.for l in C fr it ja
	@${REINPLACE_CMD} '/^install-data-local:/,/^$$/d' \
		${WRKSRC}/share/$l/Makefile.in
.endfor

.include <bsd.port.mk>
