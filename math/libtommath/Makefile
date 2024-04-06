PORTNAME=	libtommath
DISTVERSION=	1.3.0
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	https://github.com/libtom/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	ltm-${DISTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Comprehensive, modular, and portable mathematical routines
WWW=		https://libtom.net/

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing tar:xz
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

CMAKE_ON=	BUILD_SHARED_LIBS
# Remove this in next release and use USES= pathfix instead
CMAKE_ARGS=	-DCMAKE_INSTALL_PKGCONFIGDIR:STRING=libdata/pkgconfig

OPTIONS_DEFINE=		LTO OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	LTO OPTIMIZED_CFLAGS

LTO_CMAKE_BOOL=	COMPILE_LTO

OPTIMIZED_CFLAGS_CFLAGS=	-O3 -funroll-loops -fomit-frame-pointer

.include <bsd.port.mk>
