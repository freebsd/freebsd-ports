# New ports collection makefile for:	ekiga3
# Date created:		2009-09-27
# Whom:			Charlie & <root@ws.ipfw.ru>
#
# $FreeBSD$
#

PORTNAME=	ekiga3
PORTVERSION=	3.2.6
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	http://www.ekiga.org/admin/downloads/latest/sources/ekiga_${PORTVERSION}/
DISTNAME=	ekiga-${PORTVERSION}

MAINTAINER=	melifaro@ipfw.ru
COMMENT=	VoIP and video conferencing application

LIB_DEPENDS=	sigc-2:${PORTSDIR}/devel/libsigc++20 \
		opal-3.6.[6-9]:${PORTSDIR}/net/opal3
BUILD_DEPENDS=	intltoolize:${PORTSDIR}/textproc/intltool \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${LOCALBASE}/bin/scrollkeeper-config:${PORTSDIR}/textproc/rarian

CONFLICTS=	ekiga-2.*

USE_PERL5=	yes
USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_XORG=	xv
USE_GNOME=	gtk20 gnomehack
DIST_SUBDIR=	gnome2
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		ekiga.1

OPTIONS=	LDAP		"Enable LDAP support" off \
		KDE4		"Enable KDE4 support (experimental)" off \
		H323		"Enable H.323 protocol support" off \
		VIDEO		"Enable video support" on \
		NOTIFY		"Enable libnotify support" on \
		EVOLUTION	"Enable evolution data server support" off \
		GCONF		"Enable GCONF usage" on \
		DBUS		"Enable DBUS usage" off \
		AVAHI		"Enable avahi mDNS" on \
		GNOMEHELP	"Build Ekiga help files" off \
		GCONFEDITOR	"Install gconf-editor" off

.include <bsd.port.options.mk>

.if defined(WITH_KDE4)
.	if !defined(WITH_DBUS)
BROKEN=		Please set WITH_DBUS or remove WITH_KDE4!
.	endif
USE_KDE4=		kdehier kdelibs
USE_QT_VER=		4
CONFIGURE_ARGS+=	--enable-kde
.else
CONFIGURE_ARGS+=	--disable-kde
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_KDE4)
CONFIGURE_ENV+=		KDE_CFLAGS="-I${KDE4_PREFIX}/include -I${QT_INCDIR} -I${LOCALBASE}/include"
K4_INC=			${KDE4_PREFIX:C/\//\\\//g}
.endif

.if defined(WITH_VIDEO)
BUILD_DEPENDS+=		${LOCALBASE}/include/linux/videodev.h:${PORTSDIR}/multimedia/v4l_compat
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=	yes
LIB_DEPENDS+=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2
CONFIGURE_ARGS+=	--enable-ldap --with-ldap-dir="${LOCALBASE}" --with-libsasl2-dir="${LOCALBASE}"
.else
CONFIGURE_ARGS+=	--disable-ldap
.endif

.if defined(WITH_H323)
CONFIGURE_ARGS+=	--enable-h323
.else
CONFIGURE_ARGS+=	--disable-h323
.endif

.if defined(WITH_NOTIFY)
LIB_DEPENDS+=		notify.1:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=	--enable-notify
.else
CONFIGURE_ARGS+=	--disable-notify
.endif

.if defined(WITH_DBUS)
LIB_DEPENDS+=		dbus-1.3:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+=	--enable-dbus --enable-dbus-service
PLIST_SUB+=		DBUS=""
.else
CONFIGURE_ARGS+=	--disable-dbus --disable-dbus-service
PLIST_SUB+=		DBUS="@comment "
.endif

.if defined(WITH_GCONF)
USE_GNOME+=		gconf2
CONFIGURE_ARGS+=	--enable-gconf
GCONF_SCHEMAS=		ekiga.schemas
PLIST_SUB+=		NO_GCONF="@comment "
.else
CONFIGURE_ARGS+=	--disable-gconf
PLIST_SUB+=		NO_GCONF=""
.endif

.if defined(WITH_EVOLUTION)
USE_GNOME+=		evolutiondataserver
CONFIGURE_ARGS+=	--enable-eds
.else
CONFIGURE_ARGS+=	--disable-eds
.endif

.if defined(WITH_AVAHI)
CONFIGURE_ARGS+=	--enable-avahi
BUILD_DEPENDS+=		${LOCALBASE}/libdata/pkgconfig/avahi-client.pc:${PORTSDIR}/net/avahi-app
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif

.if defined(WITH_GCONFEDITOR)
RUN_DEPENDS+=		${LOCALBASE}/bin/gconf-editor:${PORTSDIR}/sysutils/gconf-editor
.endif

.if defined(WITH_GNOMEHELP)
PLIST_SUB+=		GNOMEHELP=""
USE_GNOME+=		gnomedocutils
.else
CONFIGURE_ARGS+=	--disable-gdu
PLIST_SUB+=		GNOMEHELP="@comment "
.endif

.if ${OSVERSION} < 700042
BROKEN=			does not build on 6.x
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/V4L="enabled"/V4L="disabled"/' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's?^\(KDE_CFLAGS.*\)$$?\1 -I'"${KDE4_PREFIX}/include?" ${WRKSRC}/lib/engine/components/kde/Makefile.in

post-configure:
	@${REINPLACE_CMD} -e 's?^\(CPPFLAGS\) =\(.*\)$$?\1 = '"-I${LOCALBASE}/include"' \2?' ${WRKSRC}/lib/engine/addressbook/Makefile

.include <bsd.port.post.mk>
