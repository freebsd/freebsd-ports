PORTNAME=	lurch
DISTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	net-im security
MASTER_SITES=	https://github.com/gkdr/lurch/releases/download/v${DISTVERSION}/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	michael.a.oshin@panafricanssi.org
COMMENT=	OMEMO Encryption Library for libpurple (plugin)
WWW=		https://research.ngportal.com/lurch

LICENSE=	GPLv2

LIB_DEPENDS=	libaxc.so:security/axc \
		libomemo.so:security/libomemo \
		libpurple.so:net-im/libpurple \
		libsignal-protocol-c.so:net/libsignal-protocol-c

USES=		gmake gnome pkgconfig
USE_GNOME=	glib20

MAKE_ARGS=	USE_DYNAMIC_LIBS=1
LDFLAGS+=	-Wl,--as-needed

PLIST_FILES=	lib/purple-2/lurch.so

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/purple-2/lurch.so

.include <bsd.port.mk>
