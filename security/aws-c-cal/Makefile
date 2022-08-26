PORTNAME=	aws-c-cal
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.19
CATEGORIES=	security

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Aws Crypto Abstraction Layer

LICENSE=	APACHE20

LIB_DEPENDS=	libaws-c-common.so:devel/aws-c-common

USES=		cmake compiler:c11 ssl
USE_GITHUB=	yes
GH_ACCOUNT=	awslabs
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON \
		-DBUILD_TESTING=OFF \
		-DCMAKE_INSTALL_LIBDIR=${LOCALBASE}/lib

.include <bsd.port.mk>
