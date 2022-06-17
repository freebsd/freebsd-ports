PORTNAME=	alglib
DISTVERSION=	3.19.0
CATEGORIES=	math science
MASTER_SITES=	https://www.alglib.net/translator/re/
EXTRACT_SUFX=	.cpp.gpl.zip

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Numerical analysis and data processing library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/gpl3.txt

USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-cpp

do-build:
	cd ${WRKSRC}/src && \
		${CXX} ${CXXFLAGS} -fPIC -Wl,-soname,lib${PORTNAME}.so.3 -shared -o lib${PORTNAME}.so.3 *.cpp

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/lib${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${STAGEDIR}${PREFIX}/include/lib${PORTNAME}
	${INSTALL_LIB} ${WRKSRC}/src/lib${PORTNAME}.so.3 ${STAGEDIR}${PREFIX}/lib
	@${LN} -s lib${PORTNAME}.so.3 ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so

do-test:
	@cd ${WRKSRC} && \
		cd tests && \
		${CXX} ${CXXFLAGS} test_c.cpp -I ${STAGEDIR}${LOCALBASE}/include/libalglib ${STAGEDIR}${LOCALBASE}/lib/lib${PORTNAME}.so && \
		LD_PRELOAD=${STAGEDIR}${LOCALBASE}/lib/lib${PORTNAME}.so ./a.out

.include <bsd.port.mk>
