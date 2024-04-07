PORTNAME=	libtommath
DISTVERSION=	1.3.0
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	https://github.com/libtom/libtommath/releases/download/v${DISTVERSION}/
DISTNAME=	ltm-${DISTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Comprehensive, modular, and portable mathematical routines
WWW=		https://libtom.net/

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing tar:xz

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS LTO
OPTIONS_DEFAULT=OPTIMIZED_CFLAGS LTO
OPTIMIZED_CFLAGS_CFLAGS=	-O3 -funroll-loops -fomit-frame-pointer
LTO_CMAKE_BOOL=	COMPILE_LTO

CMAKE_ARGS=	-DCMAKE_INSTALL_PKGCONFIGDIR:STRING=libdata/pkgconfig
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

USE_LDCONFIG=	yes

.include <bsd.port.mk>
