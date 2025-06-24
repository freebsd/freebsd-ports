PORTNAME=	libcryptui
PORTVERSION=	3.12.2
PORTREVISION=	7
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME application for managing encryption keys (PGP, SSH)
WWW=		https://gitlab.gnome.org/GNOME/libcryptui

DEPRECATED=	abandoned project
EXPIRATION_DATE=2025-06-30
BROKEN=		does not build with gpgme 2.x

BUILD_DEPENDS=	seahorse>=3.0.0:security/seahorse \
		gpg:security/gnupg
LIB_DEPENDS=	libgpgme.so:security/gpgme \
		libdbus-glib-1.so:devel/dbus-glib \
		libgnome-keyring.so:security/libgnome-keyring
RUN_DEPENDS=	seahorse>=3.0.0:security/seahorse \
		gpg:security/gnupg

USES=		gettext gmake gnome libtool pathfix pkgconfig tar:xz xorg
USE_GNOME=	intlhack gnomeprefix gtk30 introspection:build
USE_XORG=	sm ice
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.seahorse.recipients.gschema.xml

OPTIONS_DEFINE=	NOTIFY

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	libnotify.so:devel/libnotify
.else
CONFIGURE_ARGS+=--disable-libnotify
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|"1.2 1.4 2.0"|"1.2 1.4 2.0 2.1 2.2 2.3 2.4"|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
