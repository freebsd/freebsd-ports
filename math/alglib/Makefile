# $FreeBSD$

PORTNAME=	alglib
DISTVERSION=	3.16.0
CATEGORIES=	math science
MASTER_SITES=	http://www.alglib.net/translator/re/
EXTRACT_SUFX=	.cpp.gpl.zip

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Numerical analysis and data processing library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/gpl3.txt

USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/cpp

do-build:
	cd ${WRKSRC}/src && \
		${CXX} ${CXXFLAGS} -fPIC -Wl,-soname,lib${PORTNAME}.so.3 -shared -o lib${PORTNAME}.so.3 *.cpp

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/lib${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${STAGEDIR}${PREFIX}/include/lib${PORTNAME}
	${INSTALL_LIB} ${WRKSRC}/src/lib${PORTNAME}.so.3 ${STAGEDIR}${PREFIX}/lib
	@${LN} -s lib${PORTNAME}.so.3 ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so

.include <bsd.port.mk>
