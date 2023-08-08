PORTNAME=	kplib
DISTVERSION=	1.1.1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for finding optimal Generalized Monkhorst-Pack k-points grid
WWW=		https://gitlab.com/muellergroup/kplib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_ACCOUNT=	muellergroup
GL_TAGNAME=	7ad807da6753b4677927ad8efd485bee13d6f761

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
