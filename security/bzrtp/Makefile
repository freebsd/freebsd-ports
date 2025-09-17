PORTNAME=	bzrtp
DISTVERSION=	5.4.28
CATEGORIES=	security

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	ZRTP support library (RFC 6189)
WWW=		https://www.linphone.org

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox \
		libbcunit.so:devel/bcunit

USES=		cmake cpe gnome sqlite
CPE_VENDOR=	${PORTNAME}_project
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

post-patch:
	@${REINPLACE_CMD} 's/<alloca\.h>/<stdlib.h>/' ${WRKSRC}/src/zidCache.c

.include <bsd.port.mk>
