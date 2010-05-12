# New ports collection makefile for:	bddsolve
# Date created:				11 May 2010
# Whom:					Ed Schouten <ed@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bddsolve
PORTVERSION=	1.02
CATEGORIES=	science
MASTER_SITES=	http://www.win.tue.nl/~wieger/bddsolve/

MAINTAINER=	ed@FreeBSD.org
COMMENT=	BDD-based satisfiability and reachability solver

LIB_DEPENDS+=	bdd:${PORTSDIR}/science/buddy \
		boost_program_options:${PORTSDIR}/devel/boost-libs

USE_ZIP=	yes
USE_GCC=	4.2+
NO_WRKSUBDIR=	yes

.include <bsd.port.pre.mk>

do-build:
	${CXX} ${CFLAGS} -I${LOCALBASE}/include -I${WRKSRC}/include \
		${LDFLAGS} -L${LOCALBASE}/lib -lbdd -lboost_program_options \
		-o ${WRKSRC}/bddsolve ${WRKSRC}/src/bddsolve.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bddsolve ${LOCALBASE}/bin/
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/reach.b ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/example/sat.b ${EXAMPLESDIR}/
.endif

.include <bsd.port.post.mk>
