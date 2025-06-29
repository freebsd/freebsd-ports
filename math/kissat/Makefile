PORTNAME=	kissat
DISTVERSIONPREFIX=	rel-
DISTVERSION=	4.0.3
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Kissat SAT Solver
WWW=		https://fmv.jku.at/kissat \
		https://github.com/arminbiere/kissat

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

post-configure: # adjust compilation and link options
	@${REINPLACE_CMD} -E ' \
		s|-O -DNDEBUG|-DNDEBUG|; \
		s|^CC=.*|& ${CFLAGS}|; \
		s|^LD=.*|& ${LDFLAGS}|' \
		${WRKSRC}/build/makefile

do-install: # https://github.com/arminbiere/kissat/issues/62
	# executables
	${INSTALL_PROGRAM} ${WRKSRC}/build/kissat ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/build/kitten ${STAGEDIR}${PREFIX}/bin
	# header
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/kissat.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	# libs
	${INSTALL_LIB} ${WRKSRC}/build/libkissat.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/build/libkissat.a ${STAGEDIR}${PREFIX}/lib

# tests as of 4.0.3: All 1043 test jobs succeeded in 6.65 seconds.

.include <bsd.port.mk>
