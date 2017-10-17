# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-keyring
PORTVERSION=	3.18.3
PORTREVISION=	4
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Program that keeps passwords and other secrets

BUILD_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		docbook-xsl>=0:textproc/docbook-xsl \
		gcr>=3.5.3:security/gcr
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libgcr-3.so:security/gcr \
		libtasn1.so:security/libtasn1 \
		libp11-kit.so:security/p11-kit \
		libgcrypt.so:security/libgcrypt
RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		pinentry-gnome3:security/pinentry-gnome3

PORTSCOUT=	limitw:1,even

USE_GNOME=	gtk30 intlhack libxslt:build
USES=		compiler:c11 cpe gettext gmake gnome libtool pathfix \
		pkgconfig tar:xz
CPE_VENDOR=	gnome
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-pam-dir="${PREFIX}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
GLIB_SCHEMAS=	org.gnome.crypto.cache.gschema.xml

SUB_FILES=	pkg-message

.include <bsd.port.mk>
