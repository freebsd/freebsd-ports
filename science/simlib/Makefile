# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	simlib
PORTVERSION=	3.02
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://www.fit.vutbr.cz/~peringer/SIMLIB/source/
DISTNAME=	${PORTNAME}-${PORTVERSION}-20111030

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SIMulation LIBrary for C++ programming language

BROKEN_powerpc64=	Does not build

USES=		gmake
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

CXXFLAGS+=	-fPIC

NOT_FOR_ARCHS=		ia64 powerpc sparc64
NOT_FOR_ARCHS_REASON=	contains not working ${ARCH}-dependent assembly code

post-patch:
	@${REINPLACE_CMD} -e 's|make|gmake|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's#%%PREFIX%%#${PREFIX}#g' \
		${WRKSRC}/src/Makefile.generic
	@${REINPLACE_CMD} -e 's#g++#${CXX}#g' \
		${WRKSRC}/src/Makefile.FreeBSD-i386 \
		${WRKSRC}/examples/Makefile.FreeBSD-i386 \
		${WRKSRC}/tests/Makefile.FreeBSD-i386
	@${MV} ${WRKSRC}/src/Makefile.FreeBSD-i386 ${WRKSRC}/src/Makefile
	@${MV} ${WRKSRC}/examples/Makefile.FreeBSD-i386 ${WRKSRC}/examples/Makefile
	@${MV} ${WRKSRC}/tests/Makefile.FreeBSD-i386 ${WRKSRC}/tests/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsimlib.so

.include <bsd.port.mk>
