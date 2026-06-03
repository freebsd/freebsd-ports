PORTNAME=	purple-googlechat
DISTVERSION=	g20250724
CATEGORIES=	net-im

MAINTAINER=	atanubiswas484@gmail.com
COMMENT=	Google Chat Plugin for libpurple
WWW=		https://github.com/EionRobb/purple-googlechat

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libprotobuf-c.so:devel/protobuf-c \
		libpurple.so:net-im/libpurple

USES=		gmake gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	EionRobb
GH_TAGNAME=	nightly-3d07c3a2463ca7dd47fa89b2ce9f8ffb762b320b
USE_GNOME=	glib20
USE_LDCONFIG=	yes

PLIST_FILES=	lib/purple-2/libgooglechat.so \
		share/pixmaps/pidgin/protocols/16/googlechat.png \
		share/pixmaps/pidgin/protocols/22/googlechat.png \
		share/pixmaps/pidgin/protocols/48/googlechat.png

post-install:
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/purple-2/libgooglechat.so

.include <bsd.port.mk>
