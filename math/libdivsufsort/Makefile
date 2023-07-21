PORTNAME=	libdivsufsort
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.1-14
DISTVERSIONSUFFIX=	-g5f60d6f
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight suffix-sorting library
WWW=		https://github.com/y-256/libdivsufsort

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake pathfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	y-256

PLIST_FILES=	include/divsufsort.h \
		lib/libdivsufsort.so \
		lib/libdivsufsort.so.3 \
		lib/libdivsufsort.so.3.0.1 \
		libdata/pkgconfig/libdivsufsort.pc

do-test:
	@cd ${TEST_WRKSRC} && \
		${SETENV} ${TEST_ENV} ${CC} ${FILESDIR}/test.c -I${STAGEDIR}${PREFIX}/include -L${STAGEDIR}${PREFIX}/lib -ldivsufsort && \
		${ECHO} "==> running the test program:" && \
		LD_PRELOAD=${STAGEDIR}${PREFIX}/lib/libdivsufsort.so ${TEST_WRKSRC}/a.out

.include <bsd.port.mk>
