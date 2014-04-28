# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-experimental/trunk/multimedia/totem-pl-parser/Makefile 19273 2014-03-24 15:09:18Z gusi $

PORTNAME=	totem-pl-parser
PORTVERSION=	3.10.2
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject-based library to parse a host of playlist formats

LIB_DEPENDS=	libgmime-2.6.so:${PORTSDIR}/mail/gmime26 \
		libsoup-gnome-2.4.so:${PORTSDIR}/devel/libsoup-gnome

USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:xz
USE_GNOME=	glib20 gnomehier gnomeprefix intlhack introspection:build \
		libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
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
LIB_DEPENDS+=	libquvi-0.9.so:${PORTSDIR}/multimedia/libquvi
CONFIGURE_ARGS+=--enable-quvi
.else
CONFIGURE_ARGS+=--enable-quvi=no
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|pkg_modules libarchive"|pkg_modules"|g' \
		${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtotem-plparser*.so.18

.include <bsd.port.mk>
