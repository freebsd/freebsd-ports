PORTNAME=	purple-hangouts
PORTVERSION=	20210630
CATEGORIES=	net-im

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Hangouts plugin for libpurple

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/gpl3.txt

LIB_DEPENDS=	libpurple.so:net-im/libpurple \
		libjson-glib-1.0.so:devel/json-glib \
		libprotobuf-c.so:devel/protobuf-c

USES=		gmake gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	EionRobb
GH_TAGNAME=	55b9f01 # Change accordingly with PORTVERSION
USE_GNOME=	glib20
USE_LDCONFIG=	yes

PLIST_FILES=	lib/purple-2/libhangouts.so \
		share/pixmaps/pidgin/protocols/16/hangouts.png \
		share/pixmaps/pidgin/protocols/22/hangouts.png \
		share/pixmaps/pidgin/protocols/48/hangouts.png

post-install:
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/purple-2/libhangouts.so

.include <bsd.port.mk>
