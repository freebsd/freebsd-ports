# Created by: Dave McKay <dave@mu.org>
# $FreeBSD$
#   $MCom: ports/security/seahorse/Makefile,v 1.109 2012/09/01 23:02:12 mezz Exp $

PORTNAME=	seahorse
PORTVERSION=	2.32.0
PORTREVISION=	11
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME application for managing encryption keys (PGP, SSH)

BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
LIB_DEPENDS=	libgpgme.so:${PORTSDIR}/security/gpgme \
    		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libgcr.so:${PORTSDIR}/security/gnome-keyring \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup

CONFLICTS=	libcryptui-3.[0-9]* seahorse-3.[0-9]*

USE_XORG=	sm
USE_LDCONFIG=	yes
USES=		pathfix gettext gmake libtool:keepla pkgconfig tar:bzip2
USE_GNOME=	intlhack gnomeprefix gconf2 gnomedocutils
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-introspection=no
INSTALL_TARGET=	install-strip

GCONF_SCHEMAS=	seahorse.schemas

OPTIONS_DEFINE=	LDAP NOTIFY MDNS
OPTIONS_DEFAULT=LDAP NOTIFY MDNS
MDNS_DESC=	mDNS key sharing

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
.else
CONFIGURE_ARGS+=--disable-ldap
.endif

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	libnotify.so:${PORTSDIR}/devel/libnotify
.else
CONFIGURE_ARGS+=--disable-libnotify
.endif

.if ${PORT_OPTIONS:MMDNS}
LIB_DEPENDS+=	libavahi-client.so:${PORTSDIR}/net/avahi-app
.else
CONFIGURE_ARGS+=--disable-sharing
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|" == "|" = "|g' \
			${WRKSRC}/configure

.include <bsd.port.mk>
