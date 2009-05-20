# New ports collection makefile for:	Seahorse
# Date created:		08 March 2000
# Whom:			Dave McKay <dave@mu.org>
#
# $FreeBSD$
#   $MCom: ports-stable/security/seahorse/Makefile,v 1.5 2009/04/20 00:55:09 marcus Exp $
#

PORTNAME=	seahorse
PORTVERSION=	2.26.2
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME application for managing encryption keys (PGP, SSH)

BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
LIB_DEPENDS=	gpgme.17:${PORTSDIR}/security/gpgme \
    		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		gnome-keyring:${PORTSDIR}/security/gnome-keyring \
		soup-2.4.1:${PORTSDIR}/devel/libsoup

USE_XORG=	sm
USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix libglade2 gconf2 gnomedocutils
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	seahorse.schemas
MAN1=		seahorse-daemon.1

OPTIONS=	LDAP "Enable LDAP support" on \
		NOTIFY "Enable libnotify support" on \
		MDNS "Enable mDNS key sharing" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_LDAP)
USE_OPENLDAP=	yes
.else
CONFIGURE_ARGS+=--disable-ldap
.endif

.if !defined(WITHOUT_NOTIFY)
LIB_DEPENDS+=	notify.1:${PORTSDIR}/devel/libnotify
.else
CONFIGURE_ARGS+=--disable-libnotify
.endif

.if !defined(WITHOUT_MDNS)
LIB_DEPENDS+=	avahi-client:${PORTSDIR}/net/avahi-app
.else
CONFIGURE_ARGS+=--disable-sharing
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|" == "|" = "|g' \
			${WRKSRC}/configure

.include <bsd.port.post.mk>
