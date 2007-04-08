# New ports collection makefile for:	Seahorse
# Date created:		08 March 2000
# Whom:			Dave McKay <dave@mu.org>
#
# $FreeBSD$
#   $MCom: ports/security/seahorse/Makefile,v 1.31 2007/03/15 16:34:55 marcus Exp $
#

PORTNAME=	seahorse
PORTVERSION=	1.0.1
CATEGORIES=	security gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A front end for GnuPG

BUILD_DEPENDS=	gpgv:${PORTSDIR}/security/gnupg1
RUN_DEPENDS=	gpgv:${PORTSDIR}/security/gnupg1
LIB_DEPENDS=	gpgme.17:${PORTSDIR}/security/gpgme \
    		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GECKO=	firefox xulrunner firefox-devel<->firefox
USE_GNOME=	gnomehack intlhack gnomeprefix libgnomeui
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--with-gecko=${GECKO}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	seahorse.schemas
MAN1=		seahorse-agent.1 seahorse-daemon.1 seahorse-tool.1

OPTIONS=	NAUTILUS "Enable the Nautilus component" on \
		LDAP "Enable LDAP support" on \
		HKP "Enable HKP keyserver interface" on \
		GEDIT "Enable GEdit plug-in support" on \
		NOTIFY "Enable libnotify support" on \
		APPLET "Enable clipboard encryption applet" on \
		KEYRING "Enable GNOME Keyring support" on \
		MDNS "Enable mDNS key sharing" on \
		EPIPHANY "Enable Epiphany plug-in support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GEDIT)
BUILD_DEPENDS+=	gedit:${PORTSDIR}/editors/gedit
RUN_DEPENDS+=	gedit:${PORTSDIR}/editors/gedit
PLIST_SUB+=	GEDIT=""
GCONF_SCHEMAS+=	seahorse-gedit.schemas
.else
PLIST_SUB+=	GEDIT="@comment "
CONFIGURE_ARGS+=--disable-gedit
.endif

.if !defined(WITHOUT_NAUTILUS)
USE_GNOME+=	nautilus2
PLIST_SUB+=	NAUTILUS=""
.else
PLIST_SUB+=	NAUTILUS="@comment "
CONFIGURE_ARGS+=--disable-nautilus
.endif

.if !defined(WITHOUT_LDAP)
USE_OPENLDAP=	yes
.else
CONFIGURE_ARGS+=--disable-ldap
.endif

.if !defined(WITHOUT_HKP)
LIB_DEPENDS+=	soup-2.2.8:${PORTSDIR}/devel/libsoup
.else
CONFIGURE_ARGS+=--disable-hkp
.endif

.if !defined(WITHOUT_NOTIFY)
LIB_DEPENDS+=	notify.1:${PORTSDIR}/devel/libnotify
.else
CONFIGURE_ARGS+=--disable-libnotify
.endif

.if !defined(WITHOUT_EPIPHANY)
BUILD_DEPENDS+=	epiphany:${PORTSDIR}/www/epiphany
RUN_DEPENDS+=	epiphany:${PORTSDIR}/www/epiphany
PLIST_SUB+=	EPHY="" EPHY_VERSION="2.18"
.else
CONFIGURE_ARGS+=--disable-epiphany
PLIST_SUB+=	EPHY="@comment "
.endif

.if !defined(WITHOUT_APPLET)
USE_GNOME+=	gnomepanel
PLIST_SUB+=	APPLET=""
.else
CONFIGURE_ARGS+=--disable-applet
PLIST_SUB+=	APPLET="@comment "
.endif

.if !defined(WITHOUT_KEYRING)
LIB_DEPENDS+=	gnome-keyring:${PORTSDIR}/security/gnome-keyring
.else
CONFIGURE_ARGS+=--disable-gnome-keyring
.endif

.if !defined(WITHOUT_MDNS)
LIB_DEPENDS+=	avahi-client:${PORTSDIR}/net/avahi
.else
CONFIGURE_ARGS+=--disable-sharing
.endif

post-install:
	-@update-desktop-database

.include "${PORTSDIR}/www/mozilla/bsd.gecko.mk"
.include <bsd.port.post.mk>
