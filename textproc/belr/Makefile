PORTNAME=	belr
PORTVERSION=	5.1.32
CATEGORIES=	textproc
MASTER_SITES=	https://gitlab.linphone.org/BC/public/${PORTNAME}/-/archive/${PORTVERSION}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Language recognition library
WWW=		https://www.linphone.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox

USES=		cmake compiler:c++11-lib
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_PREFIX_PATH=${LOCALBASE} \
		-DCMAKE_SKIP_INSTALL_RPATH=ON \
		-DENABLE_STATIC=NO \
		-DENABLE_STRICT=NO

.include <bsd.port.mk>
