# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/net-im/empathy/Makefile,v 1.90 2012/08/17 19:06:45 kwm Exp $

PORTNAME=	empathy
PORTVERSION=	2.34.0
PORTREVISION=	4
CATEGORIES=	net-im gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME IM client based around telepathy

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
    		${LOCALBASE}/libexec/mission-control-5:${PORTSDIR}/net-im/telepathy-mission-control
LIB_DEPENDS=	enchant:${PORTSDIR}/textproc/enchant \
		telepathy:${PORTSDIR}/net-im/libtelepathy \
		telepathy-glib:${PORTSDIR}/net-im/telepathy-glib \
		telepathy-farsight:${PORTSDIR}/net-im/telepathy-farsight \
		telepathy-logger:${PORTSDIR}/net-im/telepathy-logger \
		folks-telepathy:${PORTSDIR}/net-im/folks04 \
		unique-1.0:${PORTSDIR}/x11-toolkits/unique \
		notify:${PORTSDIR}/devel/libnotify \
		gcr:${PORTSDIR}/security/gnome-keyring \
		canberra-gtk:${PORTSDIR}/audio/libcanberra
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
    		${LOCALBASE}/libexec/mission-control-5:${PORTSDIR}/net-im/telepathy-mission-control

CONFLICTS=	empathy-3.[0-9]*

USE_BZIP2=	yes
USES=		gettext gmake pkgconfig
USE_LDCONFIG=	yes
USE_GNOME=	evolutiondataserver gnomehack gnomeprefix pygtk2 ltverhack
USE_GSTREAMER=	yes
USE_AUTOTOOLS=	libtool
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_PYTHON=	yes
MAKE_JOBS_UNSAFE=yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-Werror \
		--with-ca-file=${LOCALBASE}/share/certs/ca-root-nss.crt

GLIB_SCHEMAS=	org.gnome.Empathy.gschema.xml

MAN1=		empathy.1 empathy-accounts.1

OPTIONS_DEFINE=	JABBER MSN IRC SALUT HAZE WEBKIT NST MAP
OPTIONS_DEFAULT=JABBER MSN IRC WEBKIT NST MAP
MSN_DESC=	MSN client support
IRC_DESC=	IRC client support
SALUT_DESC=	Link-local (serverless) XMPP support
HAZE_DESC=	Libpurple protocol integration
NST_DESC=	Nautilus SendTo plugin
MAP_DESC=	Graphical map support

NO_STAGE=	yes
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
LIB_DEPENDS+=	webkitgtk-1.0:${PORTSDIR}/www/webkit-gtk2
CONFIGURE_ARGS+=--enable-webkit
PLIST_SUB+=	ADIUM=""
.else
CONFIGURE_ARGS+=--disable-webkit
PLIST_SUB+=	ADIUM="@comment "
.endif

.if ${PORT_OPTIONS:MNST}
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/nautilus-sendto.pc:${PORTSDIR}/deskutils/nautilus-sendto
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/nautilus-sendto.pc:${PORTSDIR}/deskutils/nautilus-sendto
CONFIGURE_ARGS+=--enable-nautilus-sendto=yes
PLIST_SUB+=	NST=""
.else
CONFIGURE_ARGS+=--enable-nautilus-sendto=no
PLIST_SUB+=	NST="@comment "
.endif

.if ${PORT_OPTIONS:MMAP}
USE_GL=		gl
LIB_DEPENDS+=	champlain-0.8:${PORTSDIR}/graphics/libchamplain
CONFIGURE_ARGS+=--enable-map
PLIST_SUB+=	MAP=""
.else
CONFIGURE_ARGS+=--disable-map
PLIST_SUB+=	MAP="@comment "
.endif

.include <bsd.port.mk>
