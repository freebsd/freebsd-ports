# $FreeBSD$

PORTNAME=	symmetrica
DISTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.algorithm.uni-bayreuth.de/en/research/SYMMETRICA/
DISTFILES=	SYM2_0_tar.gz

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of routines for combinatorial mathematics

LICENSE=	PD

MAKEFILE=	makefile
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/${PORTNAME}	\
		include/${PORTNAME}/def.h \
		include/${PORTNAME}/macro.h \
		lib/libsymmetrica.a \
		lib/libsymmetrica.so \
		lib/libsymmetrica.so.0

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/test ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME} ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/libsymmetrica.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libsymmetrica.so ${STAGEDIR}${PREFIX}/lib/libsymmetrica.so.0
	${LN} -sf libsymmetrica.so.0 ${STAGEDIR}${PREFIX}/lib/libsymmetrica.so

.include <bsd.port.mk>
