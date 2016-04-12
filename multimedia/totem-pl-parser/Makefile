# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	totem-pl-parser
PORTVERSION=	3.10.6
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject-based library to parse a host of playlist formats

LIB_DEPENDS=	libgmime-2.6.so:mail/gmime26 \
		libsoup-gnome-2.4.so:devel/libsoup-gnome

USES=		gettext gmake gnome libarchive libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 gnomeprefix intltool introspection:build \
		libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-libarchive
INSTALL_TARGET=	install-strip

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	GCRYPT QUVI
OPTIONS_DEFAULT=GCRYPT QUVI
QUVI_DESC=	Flash media stream URL support
QUVI_CONFIGURE_ENABLE=	quvi
QUVI_LIB_DEPENDS=	libquvi-0.9.so:multimedia/libquvi09
GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt
GCRYPT_CONFIGURE_ENABLE=	libgcrypt

post-patch:
	@${REINPLACE_CMD} -e 's|pkg_modules libarchive"|pkg_modules"|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
