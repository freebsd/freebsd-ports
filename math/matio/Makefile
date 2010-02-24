# New ports collection makefile for:	matio
# Date created:				14 February 2010
# Whom:					rfarmer@predatorlabs.net
#
# $FreeBSD$
#

PORTNAME=	matio
PORTVERSION=	1.3.3
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	Library for reading/writing Matlab files

USE_FORTRAN=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-fPIC

PLIST_FILES= 	include/matio.h \
		include/matioConfig.h \
		lib/libmatio.a \
		lib/libmatio.la \
		lib/libmatio.so.1 \
		libdata/pkgconfig/matio.pc

post-build:
	(cd ${WRKSRC}/src && ${CC} ${CFLAGS} -shared -o libmatio.so.1 snprintf.o endian.o io.o inflate.o read_data.o mat5.o mat4.o mat.o)

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/.libs/libmatio.lai ${PREFIX}/lib/libmatio.la
	${INSTALL_DATA} ${WRKSRC}/src/.libs/libmatio.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/src/matio.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/src/matioConfig.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/matio.pc ${PREFIX}/libdata/pkgconfig
	${INSTALL_PROGRAM} ${WRKSRC}/src/libmatio.so.1 ${PREFIX}/lib

.include <bsd.port.mk>
