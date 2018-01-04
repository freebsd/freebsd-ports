# $FreeBSD$

PORTNAME=	libefp
DISTVERSION=	1.5.0
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Effective fragment potential method in quantum chemistry

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:outsource
USE_GITHUB=	yes
GH_ACCOUNT=	ilyak
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON
CMAKE_ARGS+=	-DENABLE_XHOST:BOOL=OFF
CMAKE_ARGS+=	-DFRAGLIB_DEEP:BOOL=OFF # configuration in dependencies fails without this

.include <bsd.port.mk>
