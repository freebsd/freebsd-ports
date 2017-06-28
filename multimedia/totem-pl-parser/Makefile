# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	totem-pl-parser
PORTVERSION=	3.10.8
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject-based library to parse a host of playlist formats

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libgmime-2.6.so:mail/gmime26 \
		libsoup-2.4.so:devel/libsoup \
		libgpg-error.so:security/libgpg-error \
		libgcrypt.so:security/libgcrypt

USES=		gettext gmake gnome libarchive libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 gnomeprefix intltool introspection:build libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-libarchive
INSTALL_TARGET=	install-strip

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	QUVI
OPTIONS_DEFAULT=QUVI
QUVI_DESC=	Flash media stream URL support
QUVI_CONFIGURE_ENABLE=	quvi
QUVI_LIB_DEPENDS=	libquvi-0.9.so:multimedia/libquvi09

post-patch:
	@${REINPLACE_CMD} -e 's|gmime-3.0|disabled-gmime-3.0|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
