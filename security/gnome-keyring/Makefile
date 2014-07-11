# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/security/gnome-keyring/Makefile 19769 2014-07-08 07:47:36Z kwm $

PORTNAME=	gnome-keyring
PORTVERSION=	3.12.2
PORTREVISION=	1
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Program that keeps passwords and other secrets

BUILD_DEPENDS=	ca_root_nss>=0:${PORTSDIR}/security/ca_root_nss \
		docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl \
		gcr>=3.5.3:${PORTSDIR}/security/gcr
LIB_DEPENDS=	libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		libgcr-3.so:${PORTSDIR}/security/gcr \
		libtasn1.so:${PORTSDIR}/security/libtasn1 \
		libp11-kit.so:${PORTSDIR}/security/p11-kit \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt
RUN_DEPENDS=	ca_root_nss>=0:${PORTSDIR}/security/ca_root_nss

USE_GNOME=	gnomeprefix gtk30 intlhack libxslt:build
USES=		gettext gmake libtool pathfix pkgconfig tar:xz
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-pam-dir="${PREFIX}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
GLIB_SCHEMAS=	org.gnome.crypto.cache.gschema.xml

.include <bsd.port.mk>
