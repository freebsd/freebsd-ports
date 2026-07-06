PORTNAME=	libdivsufsort
DISTVERSION=	2.0.2-1.20151027 # 2.0.2-1 was only specified in the commit comment
PORTREVISION=	1
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
GH_TAGNAME=	5f60d6f026c30fb4ac296f696b3c8b0eb71bd428

PLIST_FILES=	include/divsufsort.h \
		include/divsufsort64.h \
		lib/libdivsufsort.so \
		lib/libdivsufsort.so.3 \
		lib/libdivsufsort.so.3.0.1 \
		lib/libdivsufsort64.so \
		lib/libdivsufsort64.so.3 \
		lib/libdivsufsort64.so.3.0.1 \
		libdata/pkgconfig/libdivsufsort.pc \
		libdata/pkgconfig/libdivsufsort64.pc

CMAKE_ON=	BUILD_DIVSUFSORT64

do-test:
	@cd ${TEST_WRKSRC} && \
		${SETENV} ${TEST_ENV} ${CC} ${FILESDIR}/test.c -I${STAGEDIR}${PREFIX}/include -L${STAGEDIR}${PREFIX}/lib -ldivsufsort && \
		${ECHO} "==> running the test program:" && \
		LD_PRELOAD=${STAGEDIR}${PREFIX}/lib/libdivsufsort.so ${TEST_WRKSRC}/a.out

.include <bsd.port.mk>
