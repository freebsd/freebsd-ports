# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/net-im/empathy/Makefile,v 1.90 2012/08/17 19:06:45 kwm Exp $

PORTNAME=	empathy
PORTVERSION=	2.34.0
PORTREVISION=	9
CATEGORIES=	net-im gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME IM client based around telepathy

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
    		${LOCALBASE}/libexec/mission-control-5:${PORTSDIR}/net-im/telepathy-mission-control
LIB_DEPENDS=	libenchant.so:${PORTSDIR}/textproc/enchant \
		libtelepathy.so:${PORTSDIR}/net-im/libtelepathy \
		libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib \
		libtelepathy-farsight.so:${PORTSDIR}/net-im/telepathy-farsight \
		libtelepathy-logger.so:${PORTSDIR}/net-im/telepathy-logger \
		libfolks-telepathy.so:${PORTSDIR}/net-im/folks04 \
		libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libgcr.so:${PORTSDIR}/security/gnome-keyring \
		libcanberra-gtk.so:${PORTSDIR}/audio/libcanberra
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
    		${LOCALBASE}/libexec/mission-control-5:${PORTSDIR}/net-im/telepathy-mission-control

CONFLICTS=	empathy-3.[0-9]*

USES=		gettext gmake libtool pathfix pkgconfig python tar:bzip2
USE_LDCONFIG=	yes
USE_GNOME=	evolutiondataserver gnomeprefix pygtk2
GNU_CONFIGURE=	yes
USE_GSTREAMER=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
MAKE_JOBS_UNSAFE=yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-Werror \
		--with-ca-file=${LOCALBASE}/share/certs/ca-root-nss.crt \
		--enable-nautilus-sendto=no

GLIB_SCHEMAS=	org.gnome.Empathy.gschema.xml

OPTIONS_DEFINE=	JABBER MSN IRC SALUT HAZE WEBKIT MAP
OPTIONS_DEFAULT=JABBER MSN IRC WEBKIT MAP
MSN_DESC=	MSN client support
IRC_DESC=	IRC client support
SALUT_DESC=	Link-local (serverless) XMPP support
HAZE_DESC=	Libpurple protocol integration
MAP_DESC=	Graphical map support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJABBER}
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-gabble:${PORTSDIR}/net-im/telepathy-gabble
.endif

.if ${PORT_OPTIONS:MMSN}
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-butterfly:${PORTSDIR}/net-im/telepathy-butterfly
.endif

.if ${PORT_OPTIONS:MIRC}
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-idle:${PORTSDIR}/net-im/telepathy-idle
.endif

.if ${PORT_OPTIONS:MSALUT}
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-salut:${PORTSDIR}/net-im/telepathy-salut
.endif

.if ${PORT_OPTIONS:MHAZE}
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-haze:${PORTSDIR}/net-im/telepathy-haze
.endif

.if ${PORT_OPTIONS:MWEBKIT}
LIB_DEPENDS+=	libwebkitgtk-1.0.so:${PORTSDIR}/www/webkit-gtk2
CONFIGURE_ARGS+=--enable-webkit
PLIST_SUB+=	ADIUM=""
.else
CONFIGURE_ARGS+=--disable-webkit
PLIST_SUB+=	ADIUM="@comment "
.endif

.if ${PORT_OPTIONS:MMAP}
USE_GL=		gl
LIB_DEPENDS+=	libchamplain-0.8.so:${PORTSDIR}/graphics/libchamplain
CONFIGURE_ARGS+=--enable-map
PLIST_SUB+=	MAP=""
.else
CONFIGURE_ARGS+=--disable-map
PLIST_SUB+=	MAP="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e '/^empathy_av_LDADD =/s/$$/ -lm/' \
		-e '/^empathy_call_LDADD =/s/$$/ -lm/' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
