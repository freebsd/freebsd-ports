# New ports collection makefile for:	Seahorse
# Date created:		08 March 2000
# Whom:			Dave McKay <dave@mu.org>
#
# $FreeBSD$
#   $MCom: ports/security/seahorse/Makefile,v 1.61 2008/03/14 14:13:03 mezz Exp $
#

PORTNAME=	seahorse
PORTVERSION=	2.22.3
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME application for managing encryption keys (PGP, SSH)

BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
LIB_DEPENDS=	gpgme.17:${PORTSDIR}/security/gpgme \
    		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		gnome-keyring:${PORTSDIR}/security/gnome-keyring

USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
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

OPTIONS=	LDAP "Enable LDAP support" on \
		HKP "Enable HKP keyserver interface" on \
		NOTIFY "Enable libnotify support" on \
		APPLET "Enable clipboard encryption applet" on \
		MDNS "Enable mDNS key sharing" on \
		GEDIT "Enable GEdit plug-in support" on \
		NAUTILUS "Enable the Nautilus component" on \
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
LIB_DEPENDS+=	soup-2.4.1:${PORTSDIR}/devel/libsoup
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
PLIST_SUB+=	EPHY="" EPHY_VERSION="2.22"
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

.if !defined(WITHOUT_MDNS)
LIB_DEPENDS+=	avahi-client:${PORTSDIR}/net/avahi-app
.else
CONFIGURE_ARGS+=--disable-sharing
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|" == "|" = "|g' \
			${WRKSRC}/configure

post-install:
	-@update-desktop-database

.include "${PORTSDIR}/www/mozilla/bsd.gecko.mk"
.include <bsd.port.post.mk>
