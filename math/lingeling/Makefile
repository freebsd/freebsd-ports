PORTNAME=	lingeling
DISTVERSIONPREFIX=	rel-
DISTVERSION=	1.0.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lingeling SAT Solver
WWW=		http://fmv.jku.at/lingeling/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	arminbiere

BINARY_ALIAS=	gcc=${CC}

EXECUTABLES=	ilingeling lglddtrace lglmbt lgluntrace lingeling plingeling treengeling

CFLAGS+=	-fPIC

PLIST_FILES=	${EXECUTABLES:S/^/bin\//} \
		include/lglib.h \
		lib/liblgl.a

do-configure:
	@cd ${WRKSRC} &&  \
		${SETENV} ${MAKE_ENV} ./configure.sh

do-build:
	@cd ${WRKSRC} &&  \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} -j${MAKE_JOBS_NUMBER}

do-install:
.for e in ${EXECUTABLES}
	${INSTALL_PROGRAM} ${WRKSRC}/${e} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/lglib.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/liblgl.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
