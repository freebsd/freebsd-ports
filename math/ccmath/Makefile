PORTNAME=	ccmath
PORTVERSION=	2.2.1
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	SUNSITE/libs

MAINTAINER=	db@FreeBSD.org
COMMENT=	Mathematics library with many different functions

LICENSE=	LGPL20

USE_LDCONFIG=	yes
PLIST_FILES=	include/ccmath.h lib/libccm.a lib/libccm.so lib/libccm.so.1

PORTDOCS=	*
SRC_DIRS=	cfit complex fft geom intg matrix roots sfunc simu sort statf \
		tseries util xarm

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

COPT=		-fPIC

post-extract:
	@${CP} ${WRKSRC}/matrix/supp/solv.c ${WRKSRC}/matrix
	@${CP} ${WRKSRC}/simu/supp/*.c ${WRKSRC}/simu
	@${CP} ${WRKSRC}/xarm/supp/big-end/*.c ${WRKSRC}/xarm
	@${RM} ${WRKSRC}/matrix/*.s
	@${RM} ${WRKSRC}/simu/*.s

do-build:
.for d in ${SRC_DIRS}
	(cd ${WRKSRC}/${d}; ${CC} ${CFLAGS} ${COPT} -c *.c)
	${MV} ${WRKSRC}/${d}/*.o ${WRKSRC}/tmp
.endfor
	(cd ${WRKSRC}/matrix; ${CC} ${COPT} -c qrb*.c)
	${MV} ${WRKSRC}/matrix/*.o ${WRKSRC}/tmp
	(cd ${WRKSRC}/tmp; \
		${AR} r libccm.a *.o; \
		${RANLIB} libccm.a; \
		${CC} -shared -Wl,-soname=libccm.so.1 -o libccm.so.1 *.o)

do-install:
	${INSTALL_DATA} ${WRKSRC}/ccmath.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/tmp/libccm.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/tmp/libccm.so.1 ${STAGEDIR}${PREFIX}/lib
	@${LN} -s libccm.so.1 ${STAGEDIR}${PREFIX}/lib/libccm.so
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/ccmath
	${INSTALL_DATA} ${WRKSRC}/manual/* ${STAGEDIR}${PREFIX}/share/doc/ccmath

.include <bsd.port.post.mk>
