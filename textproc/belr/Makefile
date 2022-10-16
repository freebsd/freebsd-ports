PORTNAME=	belr
DISTVERSION=	5.1.32
CATEGORIES=	textproc

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Language recognition library
WWW=		https://www.linphone.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox

USES=		cmake compiler:c++11-lib
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
GL_COMMIT=	03d649ca34c715dda11f842ad54d5eb38752086f
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_PREFIX_PATH=${LOCALBASE} \
		-DCMAKE_SKIP_INSTALL_RPATH=ON \
		-DENABLE_STATIC=NO \
		-DENABLE_STRICT=NO

.include <bsd.port.mk>
