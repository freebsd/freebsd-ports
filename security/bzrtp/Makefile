PORTNAME=	bzrtp
PORTVERSION=	5.1.32
CATEGORIES=	security

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	ZRTP support library (RFC 6189)

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox

USES=		cmake cpe gnome sqlite
CPE_VENDOR=	${PORTNAME}_project
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
GL_COMMIT=	ab352db967d3f2bd0037564079e5cb4df0bd3460
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_PREFIX_PATH=${LOCALBASE} \
		-DENABLE_STATIC=NO \
		-DENABLE_STRICT=NO

post-patch:
	@${REINPLACE_CMD} 's/<alloca\.h>/<stdlib.h>/' ${WRKSRC}/src/zidCache.c

.include <bsd.port.mk>
