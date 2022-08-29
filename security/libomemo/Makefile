PORTNAME=	libomemo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.1
CATEGORIES=	security

MAINTAINER=	micadeyeye@gmail.com
COMMENT=	Implements OMEMO in C

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libmxml.so:textproc/mxml

GH_ACCOUNT=	gkdr

USES=		cmake gnome pkgconfig sqlite
USE_GITHUB=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	OMEMO_WITH_TESTS
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
