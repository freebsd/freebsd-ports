# $FreeBSD$

PORTNAME=	libilbc
DISTVERSION=	1.1.1
CATEGORIES=	net

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Internet Low Bit Rate codec (RFC3951)

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	ilbc-r[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	dekkers
GH_COMMIT=	b5f9b10
GH_TAGNAME=	${GH_COMMIT}

USES=		cmake
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e 's|lib/$${CMAKE_LIBRARY_ARCHITECTURE}/pkgconfig|libdata/pkgconfig|' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
