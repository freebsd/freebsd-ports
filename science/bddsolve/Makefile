# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bddsolve
PORTVERSION=	1.03
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://www.win.tue.nl/~wieger/bddsolve/_downloads/
DISTNAME=	${PORTNAME}-source-${PORTVERSION}

MAINTAINER=	ed@FreeBSD.org
COMMENT=	BDD-based satisfiability and reachability solver

LIB_DEPENDS+=	libbdd.so:${PORTSDIR}/science/buddy \
		libboost_program_options.so:${PORTSDIR}/devel/boost-libs

USES=		zip
NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc: runs out of virtual memory
.endif

do-build:
	${CXX} ${CFLAGS} -I${LOCALBASE}/include -I${WRKSRC}/include \
		${LDFLAGS} -L${LOCALBASE}/lib -lbdd -lboost_program_options \
		-o ${WRKSRC}/bddsolve ${WRKSRC}/src/bddsolve.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bddsolve ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/reach.b ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/sat.b ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
