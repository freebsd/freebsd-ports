# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/security/gcr/Makefile 19768 2014-07-08 06:29:22Z kwm $

PORTNAME=	gcr
PORTVERSION=	3.12.2
PORTREVISION=	1
CATEGORIES=	security gnome
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Library for bits of crypto UI and parsing

BUILD_DEPENDS=	gtk-doc>0:${PORTSDIR}/textproc/gtk-doc \
		vapigen:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus \
		libtasn1.so:${PORTSDIR}/security/libtasn1 \
		libp11-kit.so:${PORTSDIR}/security/p11-kit \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt

CONFLICTS=	gnome-keyring-2.[0-9]*

USE_GNOME=	gtk30 gnomehier intlhack introspection:build
USES=		desktop-file-utils gettext gmake libtool pathfix \
		pkgconfig shared-mime-info tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.crypto.pgp.gschema.xml

.include <bsd.port.mk>
