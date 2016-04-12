# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gcr
PORTVERSION=	3.18.0
CATEGORIES=	security gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for bits of crypto UI and parsing

BUILD_DEPENDS=	gtk-doc>0:textproc/gtk-doc \
		vapigen:lang/vala
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libtasn1.so:security/libtasn1 \
		libp11-kit.so:security/p11-kit \
		libgcrypt.so:security/libgcrypt

CONFLICTS=	gnome-keyring-2.[0-9]*
PORTSCOUT=	limitw:1,even

USE_GNOME=	gtk30 intlhack introspection:build
USES=		desktop-file-utils gettext gmake gnome libtool pathfix \
		pkgconfig shared-mime-info tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-valgrind
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.crypto.pgp.gschema.xml

.include <bsd.port.mk>
