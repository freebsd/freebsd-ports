PORTNAME=	purple-googlechat
DISTVERSION=	g20211018
CATEGORIES=	net-im

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Google Chat Plugin for libpurple

LICENSE=	GPLv3+

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libprotobuf-c.so:devel/protobuf-c \
		libpurple.so:net-im/libpurple

USES=		gmake gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	EionRobb
GH_TAGNAME=	56ba7f7
USE_GNOME=	glib20
USE_LDCONFIG=	yes

PLIST_FILES=	lib/purple-2/libgooglechat.so \
		share/pixmaps/pidgin/protocols/16/googlechat.png \
		share/pixmaps/pidgin/protocols/22/googlechat.png \
		share/pixmaps/pidgin/protocols/48/googlechat.png

post-install:
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/purple-2/libgooglechat.so

.include <bsd.port.mk>
