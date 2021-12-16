PORTNAME=	purple-rocketchat
PORTVERSION=	0.20211002
CATEGORIES=	net-im

MAINTAINER=	mizhka@freebsd.org
COMMENT=	Rocket.Chat Plugin for libpurple

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libmarkdown.a:textproc/discount
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libpurple.so:net-im/libpurple

USES=		dos2unix gmake gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	EionRobb
GH_TAGNAME=	5c08ad0eacd39914d27b692d7eb42a94a991fb4c
USE_GNOME=	glib20
USE_LDCONFIG=	yes

MAKE_ARGS+=	"SOURCE_DATE_EPOCH=1633136402"

.include <bsd.port.mk>
