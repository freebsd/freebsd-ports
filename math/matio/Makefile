# New ports collection makefile for:	matio
# Date created:				14 February 2010
# Whom:					rfarmer@predatorlabs.net
#
# $FreeBSD$
#

PORTNAME=	matio
PORTVERSION=	1.3.4
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	Library for reading/writing Matlab files

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-fPIC

OPTIONS=	FORTRAN "Build Fortran bindings" OFF

.include <bsd.port.options.mk>

PLIST_FILES= 	include/matio.h \
		include/matioConfig.h \
		lib/libmatio.a \
		lib/libmatio.la \
		lib/libmatio.so.1 \
		libdata/pkgconfig/matio.pc

.if !defined(WITHOUT_FORTRAN)
USE_FORTRAN=	yes

FFLAGS+=	-fPIC

CONFIGURE_ARGS+=	--enable-fortran
CONFIGURE_ENV+=	FCFLAGS="${FFLAGS}"

PLIST_FILES+=	include/matio.mod
.endif

post-build:
.if defined(WITHOUT_FORTRAN)
	(cd ${WRKSRC}/src && ${CC} ${CFLAGS} -shared -o libmatio.so.1 snprintf.o \
	endian.o io.o inflate.o read_data.o mat5.o mat4.o mat.o)
.else
	(cd ${WRKSRC}/src && ${CC} ${CFLAGS} -shared -o libmatio.so.1 snprintf.o \
	endian.o io.o inflate.o read_data.o mat5.o mat4.o mat.o matio_internal.o \
	matio.o)
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/.libs/libmatio.lai ${PREFIX}/lib/libmatio.la
	${INSTALL_DATA} ${WRKSRC}/src/.libs/libmatio.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/src/matio.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/src/matioConfig.h ${PREFIX}/include
	${INSTALL_PROGRAM} ${WRKSRC}/src/libmatio.so.1 ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/matio.pc ${PREFIX}/libdata/pkgconfig
.if !defined(WITHOUT_FORTRAN)
	${INSTALL_DATA} ${WRKSRC}/src/matio.mod ${PREFIX}/include
.endif

.include <bsd.port.mk>
