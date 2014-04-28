# $FreeBSD$
#    $MCom: ports/trunk/net-im/libtelepathy/Makefile 19578 2014-04-25 21:50:30Z kwm $

PORTNAME=	libtelepathy
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	net-im devel
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Flexible Communications Framework

LIB_PC_DEPENDS=	dbus-glib-1.pc:${PORTSDIR}/devel/dbus-glib

LIB_DEPENDS=	libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib

BUILD_DEPENDS+=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|g}
RUN_DEPENDS+=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|g}

USE_PYTHON_BUILD=	yes
USES=		gmake libtool:keepla pathfix pkgconfig
USE_LDCONFIG=	yes
USE_GNOME=	glib20 libxslt:build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lglib-2.0 `pkg-config --libs telepathy-glib`

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtelepathy.so.2.*
.include <bsd.port.mk>
