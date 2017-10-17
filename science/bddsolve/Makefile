# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bddsolve
PORTVERSION=	1.03
PORTREVISION=	6
CATEGORIES=	science
MASTER_SITES=	http://www.win.tue.nl/~wieger/bddsolve/_downloads/
DISTNAME=	${PORTNAME}-source-${PORTVERSION}

MAINTAINER=	ed@FreeBSD.org
COMMENT=	BDD-based satisfiability and reachability solver

BROKEN_powerpc64=	Does not build

LIB_DEPENDS+=	libbdd.so:science/buddy \
		libboost_program_options.so:devel/boost-libs

USES=		zip
NO_WRKSUBDIR=	yes
CFLAGS+=	-I${LOCALBASE}/include -I${WRKSRC}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lbdd -lboost_program_options
BROKEN_powerpc=	Does not compile due to running out of virtual memory

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
