# New ports collection makefile for:	LinAlg
# Date created:				August 25, 1999
# Whom:					Oleg Kiselyov <oleg@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	linalg
PORTVERSION=	4.3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	will

MAINTAINER=	oleg@pobox.com

WRKSRC=		${WRKDIR}/LinAlg
ALL_TARGET=	lib
INSTALL_TARGET=	lib
USE_GMAKE=	yes

post-patch:
	@( cd ${WRKSRC}; ${SED} -e 's/%%CXXFLAGS%%/${CXXFLAGS}/g' \
	    -e 's/%%CXX%%/${CXX}/g' c++ > c++.sed; mv c++.sed c++; ${CHMOD} +x c++ )

post-install:
	$(INSTALL_DATA) ${WRKSRC}/libla.a ${PREFIX}/lib
	${MKDIR} ${PREFIX}/include/LinAlg
	$(INSTALL_DATA) ${WRKSRC}/LinAlg.h ${PREFIX}/include/LinAlg
	$(INSTALL_DATA) ${WRKSRC}/LAStreams.h ${PREFIX}/include/LinAlg
	$(INSTALL_DATA) ${WRKSRC}/builtin.h ${PREFIX}/include/LinAlg
	$(INSTALL_DATA) ${WRKSRC}/math_num.h ${PREFIX}/include/LinAlg
	$(INSTALL_DATA) ${WRKSRC}/minmax.h ${PREFIX}/include/LinAlg
	$(INSTALL_DATA) ${WRKSRC}/myenv.h ${PREFIX}/include/LinAlg
	$(INSTALL_DATA) ${WRKSRC}/std.h ${PREFIX}/include/LinAlg
	$(INSTALL_DATA) ${WRKSRC}/svd.h ${PREFIX}/include/LinAlg
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/LinAlg
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/LinAlg
.endif

.include <bsd.port.mk>
