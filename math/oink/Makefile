PORTNAME=	oink
DISTVERSION=	g20210710
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern parity game solvers written in C++

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs

USES=		cmake:testing
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	trolando
GH_TAGNAME=	3327c54

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
