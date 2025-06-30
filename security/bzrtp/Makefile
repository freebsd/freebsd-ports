PORTNAME=	bzrtp
DISTVERSION=	5.4.24
CATEGORIES=	security

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	ZRTP support library (RFC 6189)
WWW=		https://www.linphone.org

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/lib/libbctoolbox.a:net/bctoolbox \
		${LOCALBASE}/lib/libbcunit.a:devel/bcunit

USES=		cmake cpe gnome sqlite
CPE_VENDOR=	${PORTNAME}_project
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DENABLE_STRICT=NO

post-patch:
	@${REINPLACE_CMD} 's/<alloca\.h>/<stdlib.h>/' ${WRKSRC}/src/zidCache.c

.include <bsd.port.mk>
