PORTNAME=	spglib
DISTVERSIONPREFIX=	v
DISTVERSION=	1.16.5
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library for finding and handling crystal symmetries
WWW=		https://spglib.github.io/spglib/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake
USE_GITHUB=	yes
USE_LDCONFIG=	yes

.if !exists(/usr/include/omp.h)
CMAKE_ARGS+=	-DUSE_OMP:BOOL=OFF
.endif

.include <bsd.port.mk>
