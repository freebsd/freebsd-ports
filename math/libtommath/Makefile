PORTNAME=	libtommath
DISTVERSION=	1.3.0
CATEGORIES=	math
MASTER_SITES=	https://github.com/libtom/libtommath/releases/download/v${DISTVERSION}/
DISTNAME=	ltm-${DISTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Comprehensive, modular, and portable mathematical routines
WWW=		https://libtom.net/

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing tar:xz
CMAKE_ARGS=	-DBUILD_TESTING:BOOL=ON \
		-DCMAKE_INSTALL_PKGCONFIGDIR:STRING=libdata/pkgconfig
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

USE_LDCONFIG=	yes

.include <bsd.port.mk>
