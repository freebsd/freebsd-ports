# $FreeBSD$

PORTNAME=	cmocka
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://cmocka.org/files/1.1/ \
		LOCAL/dteske

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	Unit testing framework for C with support for mock objects

LICENSE=	APACHE20

USES=		cmake tar:xz
USE_LDCONFIG=	yes

PLIST_FILES=	include/cmocka.h \
		include/cmocka_pbc.h \
		lib/cmake/cmocka/cmocka-config-version.cmake \
		lib/cmake/cmocka/cmocka-config.cmake \
		lib/libcmocka.so \
		lib/libcmocka.so.0 \
		lib/libcmocka.so.0.4.1 \
		libdata/pkgconfig/cmocka.pc

OPTIONS_DEFINE=	STATIC

STATIC_CMAKE_BOOL=	WITH_STATIC_LIB
STATIC_PLIST_FILES=	lib/libcmocka.a

.include <bsd.port.mk>
