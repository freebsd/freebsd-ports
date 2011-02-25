# New ports collection makefile for:	empathy
# Date created:		2007-10-29
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/net-im/empathy/Makefile,v 1.76 2010/11/18 18:04:55 kwm Exp $

PORTNAME=	empathy
PORTVERSION=	2.32.2
PORTREVISION=	1
CATEGORIES=	net-im gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME IM client based around telepathy

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
    		${LOCALBASE}/libexec/mission-control-5:${PORTSDIR}/net-im/telepathy-mission-control
LIB_DEPENDS=	enchant.1:${PORTSDIR}/textproc/enchant \
		telepathy.2:${PORTSDIR}/net-im/libtelepathy \
		telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib \
		telepathy-farsight.0:${PORTSDIR}/net-im/telepathy-farsight \
		telepathy-logger.1:${PORTSDIR}/net-im/telepathy-logger \
		folks-telepathy.16:${PORTSDIR}/net-im/folks \
		unique-1.0.2:${PORTSDIR}/x11-toolkits/unique \
		canberra-gtk.0:${PORTSDIR}/audio/libcanberra
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
    		${LOCALBASE}/libexec/mission-control-5:${PORTSDIR}/net-im/telepathy-mission-control

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_GNOME=	evolutiondataserver gnomehack gnomeprefix pygtk2 ltverhack
USE_GSTREAMER=	yes
USE_AUTOTOOLS=	libtool
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_PYTHON=	yes
MAKE_JOBS_UNSAFE=yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-Werror \
		--with-ca-file=${LOCALBASE}/share/certs/ca-root-nss.crt

GLIB_SCHEMAS=	org.gnome.Empathy.gschema.xml

MAN1=		empathy.1 empathy-accounts.1

OPTIONS=	JABBER	"Enable jabber (XMPP) client support" on \
		MSN	"Enable MSN client support" on \
		IRC	"Enable IRC client support" on \
		SALUT	"Enable link-local (serverless) XMPP support" off \
		HAZE	"Enable libpurple protocol integration" off \
		WEBKIT	"Enable Adium Message Style themes" on \
		NST	"Enable Nautilus SendTo plugin"	on \
		MAP	"Enable graphical map support" on

.include <bsd.port.pre.mk>

.if defined(WITH_JABBER)
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-gabble:${PORTSDIR}/net-im/telepathy-gabble
.endif

.if defined(WITH_MSN)
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-butterfly:${PORTSDIR}/net-im/telepathy-butterfly
.endif

.if defined(WITH_IRC)
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-idle:${PORTSDIR}/net-im/telepathy-idle
.endif

.if !defined(WITHOUT_SALUT)
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-salut:${PORTSDIR}/net-im/telepathy-salut
.endif

.if !defined(WITHOUT_HAZE)
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-haze:${PORTSDIR}/net-im/telepathy-haze
.endif

.if defined(WITH_WEBKIT)
LIB_DEPENDS+=	webkit-1.0.13:${PORTSDIR}/www/webkit-gtk2
CONFIGURE_ARGS+=--enable-webkit
PLIST_SUB+=	ADIUM=""
.else
CONFIGURE_ARGS+=--disable-webkit
PLIST_SUB+=	ADIUM="@comment "
.endif

.if defined(WITH_NST)
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/nautilus-sendto.pc:${PORTSDIR}/deskutils/nautilus-sendto
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/nautilus-sendto.pc:${PORTSDIR}/deskutils/nautilus-sendto
CONFIGURE_ARGS+=--enable-nautilus-sendto=yes
PLIST_SUB+=	NST=""
.else
CONFIGURE_ARGS+=--enable-nautilus-sendto=no
PLIST_SUB+=	NST="@comment "
.endif

.if !defined(WITHOUT_MAP)
LIB_DEPENDS+=	champlain-0.8.1:${PORTSDIR}/graphics/libchamplain
CONFIGURE_ARGS+=--enable-map
PLIST_SUB+=	MAP=""
.else
CONFIGURE_ARGS+=--disable-map
PLIST_SUB+=	MAP="@comment "
.endif

.include <bsd.port.post.mk>
