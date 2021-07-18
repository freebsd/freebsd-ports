PORTNAME=	libgav1
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.3
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Main profile (0) & High profile (1) compliant AV1 decoder

LICENSE=	APACHE20

LIB_DEPENDS=	libabsl_synchronization.so:devel/abseil

USES=		cmake compiler:c++17-lang localbase:ldflags
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	jbeich # mirror
CMAKE_ON=	BUILD_SHARED_LIBS
LDFLAGS+=	-Wl,--as-needed # avoid overlinking (abseil deps)

.include <bsd.port.mk>
