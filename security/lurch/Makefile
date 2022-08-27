PORTNAME=	lurch
DISTVERSION=	0.7.0
CATEGORIES=	security net-im
MASTER_SITES=	https://github.com/gkdr/lurch/releases/download/v${DISTVERSION}/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	micadeyeye@gmail.com
COMMENT=	OMEMO Encryption Library for libpurple (plugin)

LICENSE=	GPLv2

LIB_DEPENDS=	libaxc.so:security/axc \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libmxml.so:textproc/mxml \
		libomemo.so:security/libomemo \
		libpurple.so:net-im/libpurple \
		libsignal-protocol-c.so:net/libsignal-protocol-c

USES=		gettext-runtime gmake gnome pkgconfig sqlite
USE_GNOME=	glib20 libxml2

MAKE_ARGS=	USE_DYNAMIC_LIBS=1

PLIST_FILES=	lib/purple-2/lurch.so

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/purple-2/lurch.so

.include <bsd.port.mk>
