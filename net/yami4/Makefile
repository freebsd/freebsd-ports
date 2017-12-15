# $FreeBSD$

PORTNAME=	yami4
PORTVERSION=	1.10.0
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.inspirel.com/yami4/files/
DISTNAME=	yami4-gpl-1.10.0

MAINTAINER=	prog@msobczak.com
COMMENT=	Messaging library for distributed systems

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/gpl-3.0.txt

MAKE_ARGS=	OPTIONS="${CXXFLAGS}"
CXXFLAGS+=	-D_GLIBCXX_USE_C99 # XXX ports/193528

do-build :
	${DO_MAKE_BUILD} -C ${WRKSRC}/src/core
	${DO_MAKE_BUILD} -C ${WRKSRC}/src/cpp

do-install :
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/yami4
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/yami4/core
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/yami4/cpp
	(cd ${WRKSRC}/doc/core && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/doc/yami4/core)
	(cd ${WRKSRC}/doc/cpp && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/doc/yami4/cpp)
	(cd ${WRKSRC}/include && ${COPYTREE_SHARE} yami4-core ${STAGEDIR}${PREFIX}/include)
	(cd ${WRKSRC}/include && ${COPYTREE_SHARE} yami4-cpp ${STAGEDIR}${PREFIX}/include)
	(cd ${WRKSRC}/lib && ${INSTALL_DATA} *.a ${STAGEDIR}${PREFIX}/lib)

.include <bsd.port.mk>
