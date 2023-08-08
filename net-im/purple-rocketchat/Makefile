PORTNAME=	purple-rocketchat
PORTVERSION=	0.20220915
PORTREVISION=	1
CATEGORIES=	net-im

MAINTAINER=	mizhka@freebsd.org
COMMENT=	Rocket.Chat Plugin for libpurple
WWW=		https://github.com/EionRobb/purple-rocketchat

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libmarkdown.a:textproc/discount
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libpurple.so:net-im/libpurple

USES=		dos2unix gmake gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	EionRobb
GH_TAGNAME=	a8a887c0c34402293bcf782f1cb76a0046f4a0a0
USE_GNOME=	glib20
USE_LDCONFIG=	yes

MAKE_ARGS+=	"SOURCE_DATE_EPOCH=1633136402"

.include <bsd.port.mk>
