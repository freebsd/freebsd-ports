PORTNAME=	beidconnect
DISTVERSION=	2.11
CATEGORIES=	security

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Belgian eID digital signature browser extension backend
WWW=		https://github.com/Fedict/fts-beidconnect

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/boost/property_tree/ptree.hpp:devel/boost-libs
LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite

USES=		gmake localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	Fedict
GH_PROJECT=	fts-beidconnect

ALL_TARGET=	beidconnect
BUILD_WRKSRC=	${WRKSRC}/linux
INSTALL_WRKSRC=	${WRKSRC}/linux

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/chromium/native-messaging-hosts
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/mozilla/native-messaging-hosts
	${STAGEDIR}${PREFIX}/bin/beidconnect -setup ${PREFIX}/bin \
		${STAGEDIR}${PREFIX}/etc/chromium/native-messaging-hosts \
		${STAGEDIR}${PREFIX}/lib/mozilla/native-messaging-hosts

.include <bsd.port.mk>
