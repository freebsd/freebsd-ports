# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/multimedia/totem-pl-parser/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	totem-pl-parser
PORTVERSION=	3.4.5
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject-based library to parse a host of playlist formats

LIB_DEPENDS=	libgmime-2.6.so:${PORTSDIR}/mail/gmime26 \
		libsoup-gnome-2.4.so:${PORTSDIR}/devel/libsoup-gnome

USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	gnomeprefix glib20 libxml2 intlhack ltverhack gnomehier \
		introspection:build
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--enable-libarchive
CONFIGURE_ENV=	ARCHIVE_CFLAGS="-I/usr/include" \
		ARCHIVE_LIBS="-L/usr/lib -larchive"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	QUVI
OPTIONS_DEFAULT=QUVI
QUVI_DESC=	Flash media stream URL support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQUVI}
LIB_DEPENDS+=	libquvi.so:${PORTSDIR}/multimedia/libquvi
CONFIGURE_ARGS+=--enable-quvi
.else
CONFIGURE_ARGS+=--enable-quvi=no
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|pkg_modules libarchive"|pkg_modules"|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
