# Created by: Eugene Grosbein <eugen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pidgin-icyque
DISTVERSION=	g20190523
CATEGORIES=	net-im

MAINTAINER=	eugen@FreeBSD.org
COMMENT=	Pidgin plugin for ICQ/WIM protocol

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pidgin:net-im/pidgin
RUN_DEPENDS=	pidgin:net-im/pidgin
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libpurple.so:net-im/libpurple

USES=		gnome gmake localbase:ldflags pkgconfig

PLIST_FILES=	lib/purple-2/libicyque.so

USE_GITHUB=	yes
GH_ACCOUNT=	EionRobb
GH_PROJECT=	icyque
GH_TAGNAME=	a10e28e

USE_GNOME=	glib20
USE_LDCONFIG=	yes

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/purple-2/libicyque.so

.include <bsd.port.mk>
