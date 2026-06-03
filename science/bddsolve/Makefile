PORTNAME=	bddsolve
PORTVERSION=	1.04
PORTREVISION=	20
CATEGORIES=	science
MASTER_SITES=	http://www.win.tue.nl/~wieger/bddsolve/_downloads/
DISTNAME=	${PORTNAME}-source-${PORTVERSION}

MAINTAINER=	ed@FreeBSD.org
COMMENT=	BDD-based satisfiability and reachability solver
WWW=		https://www.win.tue.nl/~wieger/bddsolve/

LIB_DEPENDS+=	libbdd.so:science/buddy \
		libboost_program_options.so:devel/boost-libs

USES=		compiler:c++11-lang zip
NO_WRKSUBDIR=	yes
CFLAGS+=	-I${LOCALBASE}/include -I${WRKSRC}/include -DBOOST_BIND_GLOBAL_PLACEHOLDERS -DBOOST_TIMER_ENABLE_DEPRECATED
LDFLAGS+=	-L${LOCALBASE}/lib -lbdd -lboost_program_options

OPTIONS_DEFINE=	EXAMPLES

do-build:
	${SETENV} ${MAKE_ENV} ${CXX} ${CXXFLAGS} ${LDFLAGS} \
		-o ${WRKSRC}/bddsolve ${WRKSRC}/src/bddsolve.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bddsolve ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/reach.b ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/sat.b ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
