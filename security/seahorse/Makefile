# New ports collection makefile for:	Seahorse
# Date created:		08 March 2000
# Whom:			Dave McKay <dave@mu.org>
#
# $FreeBSD$
#   $MCom: ports/security/seahorse/Makefile,v 1.96 2010/04/27 22:04:55 kwm Exp $
#

PORTNAME=	seahorse
PORTVERSION=	2.30.1
PORTREVISION=	2
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME application for managing encryption keys (PGP, SSH)

BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
LIB_DEPENDS=	gpgme.18:${PORTSDIR}/security/gpgme \
    		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		gnome-keyring:${PORTSDIR}/security/gnome-keyring \
		gcrypt.17:${PORTSDIR}/security/libgcrypt \
		soup-2.4.1:${PORTSDIR}/devel/libsoup

USE_XORG=	sm
USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix gconf2 gnomedocutils
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-introspection=no

GCONF_SCHEMAS=	seahorse.schemas
MAN1=		seahorse.1 seahorse-daemon.1

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
