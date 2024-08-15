PORTNAME=	kissat
DISTVERSIONPREFIX=	rel-
DISTVERSION=	4.0.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Kissat SAT Solver
WWW=		http://fmv.jku.at/kissat/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	arminbiere

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--shared --kitten --statistics

MAKEFILE=	makefile

TEST_TARGET=	test

PLIST_FILES=	bin/kissat \
		bin/kitten \
		include/${PORTNAME}/kissat.h \
		lib/libkissat.a \
		lib/libkissat.so

do-install:
	# executables
	${INSTALL_PROGRAM} ${WRKSRC}/build/kissat ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/build/kitten ${STAGEDIR}${PREFIX}/bin
	# header
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/kissat.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	# libs
	${INSTALL_LIB} ${WRKSRC}/build/libkissat.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/build/libkissat.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
