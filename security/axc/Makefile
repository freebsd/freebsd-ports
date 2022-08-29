PORTNAME=	axc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.7
CATEGORIES=	security net

MAINTAINER=	micadeyeye@gmail.com
COMMENT=	Crypto interfaces for libsignal-protocol-c

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libsignal-protocol-c.so:net/libsignal-protocol-c

USES=		gmake gnome pkgconfig sqlite
USE_GITHUB=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes
GH_ACCOUNT=	gkdr

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libaxc.so

.include <bsd.port.mk>
