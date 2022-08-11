PORTNAME=	aws-c-auth
PORTVERSION=	0.6.10
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	C99 library implementation of AWS client-side authentication

LICENSE=	APACHE20

LIB_DEPENDS=	libaws-c-common.so:devel/aws-c-common \
		libaws-c-cal.so:security/aws-c-cal \
		libaws-c-io.so:devel/aws-c-io \
		libaws-c-compression.so:devel/aws-c-compression \
		libaws-c-http.so:devel/aws-c-http \
		libaws-c-sdkutils.so:devel/aws-c-sdkutils \
		libs2n.so:security/s2n

USES=		cmake compiler:c11 ssl

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs

CMAKE_ARGS+=	-DBUILD_TESTING=OFF -DBUILD_SHARED_LIBS=ON \
		-DCMAKE_PREFIX_PATH=${LOCALBASE}

USE_LDCONFIG=	yes

.include <bsd.port.mk>
