# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/net-im/telepathy-farstream/Makefile 18966 2013-12-20 12:11:23Z kwm $

PORTNAME=	telepathy-farstream
PORTVERSION=	0.6.0
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Farstream Connection Manager for Telepathy Framework

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib \
		libfarstream-0.2.so:${PORTSDIR}/net-im/farstream

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	glib20 libxslt:build ltverhack introspection:build
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|\(^pkgconfigdir =\).*|\1 ${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/telepathy-farstream/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so*

.include <bsd.port.mk>
