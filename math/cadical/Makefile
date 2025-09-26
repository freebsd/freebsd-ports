PORTNAME=	cadical
DISTVERSIONPREFIX=	rel-
DISTVERSION=	2.1.3
CATEGORIES=	math devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple CDCL satisfiability solver
WWW=		https://fmv.jku.at/cadical/ \
		https://github.com/arminbiere/cadical

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++0x gmake tar:xz

USE_GITHUB=	yes
GH_ACCOUNT=	arminbiere

GNU_CONFIGURE=	yes

MAKEFILE=	makefile

BINARY_ALIAS=	make=${GMAKE}

EXES=		cadical mobical

TEST_TARGET=	test

PLIST_FILES=	${EXES:S/^/bin\//} \
		include/cadical.hpp \
		include/ccadical.h \
		lib/libcadical.a \
		lib/libcadical.so \
		lib/libcadical.so.${DISTVERSION}

post-build: # build shared library
	@${ECHO} "==> Building the shared library"
	cd ${WRKSRC}/src && ${CXX} \
		-shared -Wl,-soname=lib${PORTNAME}.so.$(DISTVERSION) -fPIC \
		-DNDEBUG \
		${CXXFLAGS} ${LDFLAGS} \
		`${ECHO} *.cpp | ${SED} -e "s/cadical\.cpp//; s/mobical\.cpp//"` \
		-I ${WRKSRC}/build \
		-o ${WRKSRC}/build/lib${PORTNAME}.so.${DISTVERSION}

do-install: # workaround for https://github.com/arminbiere/cadical/issues/49
.for e in ${EXES}
	${INSTALL_PROGRAM} ${WRKSRC}/build/${e} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/src/cadical.hpp ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/src/ccadical.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/build/libcadical.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/build/libcadical.so.${DISTVERSION} ${STAGEDIR}${PREFIX}/lib
	cd ${STAGEDIR}${PREFIX}/lib && ${LN} -s libcadical.so.${DISTVERSION} libcadical.so

.include <bsd.port.mk>
