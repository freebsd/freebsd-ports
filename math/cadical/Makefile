PORTNAME=	cadical
DISTVERSIONPREFIX=	rel-
DISTVERSION=	1.6.0
CATEGORIES=	math devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple CDCL satisfiability solver
WWW=		http://fmv.jku.at/cadical/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++0x gmake tar:xz

USE_GITHUB=	yes
GH_ACCOUNT=	arminbiere

GNU_CONFIGURE=	yes

CXXFLAGS+=	-fPIC

MAKEFILE=	makefile

BINARY_ALIAS=	make=${GMAKE}

EXES=		cadical mobical

TEST_TARGET=	test

PLIST_FILES=	${EXES:S/^/bin\//} \
		include/cadical.hpp \
		include/ccadical.h \
		lib/libcadical.a

do-install: # workaround for https://github.com/arminbiere/cadical/issues/49
.for e in ${EXES}
	${INSTALL_PROGRAM} ${WRKSRC}/build/${e} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/src/cadical.hpp ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/src/ccadical.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/build/libcadical.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
