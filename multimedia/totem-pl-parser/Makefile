# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/multimedia/totem-pl-parser/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	totem-pl-parser
PORTVERSION=	3.10.2
PORTREVISION=	1
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject-based library to parse a host of playlist formats

LIB_DEPENDS=	libgmime-2.6.so:${PORTSDIR}/mail/gmime26 \
		libsoup-gnome-2.4.so:${PORTSDIR}/devel/libsoup-gnome

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 gnomehier gnomeprefix intlhack introspection:build \
		libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-libarchive
CONFIGURE_ENV=	ARCHIVE_CFLAGS="-I/usr/include" \
		ARCHIVE_LIBS="-L/usr/lib -larchive"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	QUVI
OPTIONS_DEFAULT=QUVI
QUVI_DESC=	Flash media stream URL support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQUVI}
LIB_DEPENDS+=	libquvi-0.9.so:${PORTSDIR}/multimedia/libquvi
CONFIGURE_ARGS+=--enable-quvi
.else
CONFIGURE_ARGS+=--enable-quvi=no
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|pkg_modules libarchive"|pkg_modules"|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
