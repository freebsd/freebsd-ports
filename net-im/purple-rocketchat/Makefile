# $FreeBSD$

PORTNAME=	purple-rocketchat
PORTVERSION=	0.0.20190416
CATEGORIES=	net-im
MASTER_SITES=	https://bitbucket.org/EionRobb/purple-rocketchat/get/
DISTNAME=	826990b48f41

MAINTAINER=	mizhka@gmail.com
COMMENT=	Rocket.Chat Plugin for libpurple

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libmarkdown.a:textproc/discount
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libpurple.so:net-im/libpurple

USES=		gmake gnome pkgconfig zip
USE_GNOME=	glib20
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/EionRobb-purple-rocketchat-${DISTNAME}
PLIST_FILES=	lib/purple-2/librocketchat.so

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/purple-2
	${INSTALL_LIB} ${WRKSRC}/librocketchat.so ${STAGEDIR}${PREFIX}/lib/purple-2

.include <bsd.port.mk>
