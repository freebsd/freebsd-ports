PORTNAME=	edflib
DISTVERSION=	1.20
CATEGORIES=	misc # medicine
MASTER_SITES=	https://www.teuniz.net/edflib/
DISTNAME=	${PORTNAME}_${DISTVERSION:S/.//}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library to read/write EDF+/BDF+ (medical data series) files

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_LDCONFIG=	yes

MAKE_ARGS=	CC=${CC} CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/sine_generator \
		bin/sweep_generator \
		bin/test_edflib \
		bin/test_generator \
		include/edflib.h \
		lib/libedflib.so

post-build: # https://gitlab.com/Teuniz/EDFlib/-/issues/6
	@cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} -shared -fPIC -o lib${PORTNAME}.so ${PORTNAME}.c

do-install:
	${INSTALL_LIB} ${WRKSRC}/lib${PORTNAME}.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.h ${STAGEDIR}${PREFIX}/include
.for p in sine_generator sweep_generator test_edflib test_generator
	${INSTALL_PROGRAM} ${WRKSRC}/${p} ${STAGEDIR}${PREFIX}/bin
.endfor

do-test:
	# build
	@cd ${WRKSRC}/unittest && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS}
	# run
	@cd ${WRKSRC} && \
		${WRKSRC}/unittest/edflib_test && \
		${ECHO} "Tests passed"

.include <bsd.port.mk>
