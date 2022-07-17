PORTNAME=	kplib
DISTVERSION=	1.0.5
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for finding optimal Generalized Monkhorst-Pack k-points grid

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_ACCOUNT=	muellergroup
GL_COMMIT=	9f96d56d32f67a019066025e044dcd9e3b3316ea

PLIST_FILES=	include/kPointLattice.h \
		include/kPointLatticeGenerator.h \
		include/msmath.h \
		lib/libkpoints.a \
		lib/libkpoints.so

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/msmath.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/src/kPointLattice.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/src/kPointLatticeGenerator.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${BUILD_WRKSRC}/libkpoints.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${BUILD_WRKSRC}/libkpoints.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
