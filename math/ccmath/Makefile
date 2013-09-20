# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	ccmath
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	libs

MAINTAINER=	db@FreeBSD.org
COMMENT=	A mathematics library with many different functions

USE_LDCONFIG=	yes

PORTDOCS=	*
PLIST_FILES=	include/ccmath.h lib/libccm.a lib/libccm.so lib/libccm.so.1
SRC_DIRS=	cfit complex fft geom intg matrix roots sfunc simu sort statf \
		tseries util xarm

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
COPT=		-fPIC
.endif

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
	(cd ${WRKSRC}/tmp; ${AR} r libccm.a *.o; ${CC} -shared -o libccm.so *.o)

do-install:
	${INSTALL_DATA} ${WRKSRC}/ccmath.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/tmp/libccm.a ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/tmp/libccm.so ${PREFIX}/lib
	${LN} -s ${PREFIX}/lib/libccm.so ${PREFIX}/lib/libccm.so.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ccmath
	${INSTALL_DATA} ${WRKSRC}/manual/* ${PREFIX}/share/doc/ccmath
.endif

.include <bsd.port.post.mk>
