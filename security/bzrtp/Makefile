PORTNAME=	bzrtp
PORTVERSION=	1.0.6
CATEGORIES=	security
MASTER_SITES=	https://www.linphone.org/releases/sources/bzrtp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ZRTP support library (RFC 6189)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox

USES=		cmake gnome sqlite
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DENABLE_STATIC=NO -DENABLE_STRICT=NO

post-patch:
	@${REINPLACE_CMD} 's/<alloca\.h>/<stdlib.h>/' ${WRKSRC}/src/zidCache.c

.include <bsd.port.mk>
