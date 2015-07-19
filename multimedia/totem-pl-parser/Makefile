# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/multimedia/totem-pl-parser/Makefile 20031 2014-11-02 21:47:55Z kwm $

PORTNAME=	totem-pl-parser
PORTVERSION=	3.10.3
PORTREVISION=	1
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject-based library to parse a host of playlist formats

LIB_DEPENDS=	libgmime-2.6.so:${PORTSDIR}/mail/gmime26 \
		libsoup-gnome-2.4.so:${PORTSDIR}/devel/libsoup-gnome

USES=		gettext gmake libarchive libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 gnomeprefix intlhack introspection:build \
		libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-libarchive
INSTALL_TARGET=	install-strip

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	QUVI
OPTIONS_DEFAULT=QUVI
QUVI_DESC=	Flash media stream URL support
QUVI_CONFIGURE_ENABLE=	quvi
QUVI_LIB_DEPENDS=	libquvi-0.9.so:${PORTSDIR}/multimedia/libquvi09

post-patch:
	@${REINPLACE_CMD} -e 's|pkg_modules libarchive"|pkg_modules"|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
