PORTNAME=	aws-c-auth
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.16
CATEGORIES=	security

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	C99 library implementation of AWS client-side authentication

LICENSE=	APACHE20

LIB_DEPENDS=	libaws-c-cal.so:security/aws-c-cal \
		libaws-c-common.so:devel/aws-c-common \
		libaws-c-compression.so:devel/aws-c-compression \
		libaws-c-http.so:devel/aws-c-http \
		libaws-c-io.so:devel/aws-c-io \
		libaws-c-sdkutils.so:devel/aws-c-sdkutils \
		libs2n.so:security/s2n

USES=		cmake compiler:c11 ssl

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON \
		-DBUILD_TESTING=OFF \
		-DCMAKE_PREFIX_PATH=${LOCALBASE}

.include <bsd.port.mk>
