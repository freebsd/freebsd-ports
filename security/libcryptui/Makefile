# Created by: Dave McKay <dave@mu.org>
# $FreeBSD$
#   $MCom: ports/trunk/security/libcryptui/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	libcryptui
PORTVERSION=	3.6.0
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME application for managing encryption keys (PGP, SSH)

BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
LIB_DEPENDS=	libgpgme.so:${PORTSDIR}/security/gpgme \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg

CONFLICTS=	seahorse-2.[0-9]* seahorse-3.0.[0-9]*

USE_LDCONFIG=	yes
USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	intlhack gnomeprefix gnomedocutils gtk30
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-introspection=no

GLIB_SCHEMAS=	org.gnome.seahorse.recipients.gschema.xml

OPTIONS_DEFINE=	NOTIFY

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	libnotify.so:${PORTSDIR}/devel/libnotify
.else
CONFIGURE_ARGS+=--disable-libnotify
.endif

.include <bsd.port.mk>
