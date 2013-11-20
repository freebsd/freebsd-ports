# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/net-im/folks/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	folks
PORTVERSION=	0.8.0
CATEGORIES=	net-im
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	library to aggregates people from multiple sources

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	libgee.so.2:${PORTSDIR}/devel/libgee06 \
		libgcr-3.so:${PORTSDIR}/security/gcr \
		libzeitgeist-1.0.so:${PORTSDIR}/sysutils/libzeitgeist \
		libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib

CONFLICTS=	folks-0.4.[0-9]*

USE_XZ=		yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	evolutiondataserver3 gnomehier intlhack \
		introspection:build ltverhack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tracker-backend
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.freedesktop.folks.gschema.xml

PLIST_SUB=	LIBVER=25 VERSION=37

OPTIONS_DEFINE=	SOCIALWEB
OPTIONS_DEFAULT=SOCIALWEB
SOCIALWEB_DESC=	Social web backend

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSOCIALWEB}
LIB_DEPENDS+=	libsocialweb.so:${PORTSDIR}/www/libsocialweb
CONFIGURE_ARGS+=--enable-libsocialweb-backend=yes
PLIST_SUB+=	SOCIAL=""
.else
CONFIGURE_ARGS+=--enable-libsocialweb-backend=no
PLIST_SUB+=	SOCIAL="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^build_old_libs=yes|build_old_libs=no|g' \
		${WRKDIR}/gnome-libtool

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfolks*.so.*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/folks/*/backends/*/*.so

.include <bsd.port.mk>
