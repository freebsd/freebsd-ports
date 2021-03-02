# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	SPRNG
PORTVERSION=	5.0
CATEGORIES=	math science
MASTER_SITES=	http://www.sprng.org/Version${PORTVERSION}/
DISTNAME=	${PORTNAME:tl}${PORTVERSION:R}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Scalable Parallel Pseudo Random Number Generators Library

LICENSE=	CC-BY-NC-SA-4.0
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtestu01.so:math/testu01

USES=		compiler dos2unix fortran gmake localbase tar:bz2
DOS2UNIX_GLOB=	LICENSE

FFLAGS=		-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-testu01=${LOCALBASE}	\
		--with-testu01lib=${LOCALBASE}/lib	\
		--with-testu01inc=${LOCALBASE}/include/TestU01
TEST_TARGET=	check

PORTEXAMPLES=	*

OPTIONS_DEFINE=		EXAMPLES MPICH
OPTIONS_DEFAULT=	EXAMPLES MPICH
OPTIONS_SUB=		yes
MPICH_USES=		mpi:mpich
MPICH_CONFIGURE_WITH=	mpi

ASCII_TEXTS=	checkcmrg checklcg checklcg64 checklfg checkmlfg checkpmlcg	\
		checksprng timecmrg timelcg timelcg64 timelfg timemlfg timepmlcg\
		timesprng

.include <bsd.port.pre.mk>

pre-configure:
.if ${CHOSEN_COMPILER_TYPE} == clang
	${FIND} ${WRKSRC} -name Makefile.in |	\
		${XARGS} ${REINPLACE_CMD} -e 's|-lstdc++|-lc++|'
.endif
.for s in check_gen.cpp check_gen_simple.cpp
	${FIND} ${WRKSRC} -name ${s} |	\
		${XARGS} ${REINPLACE_CMD} -e 's|using namespace std;||'
.endfor

post-stage:
	(cd ${STAGEDIR}${PREFIX}/share &&	\
	${RM} .insertlib gencheck gentime insertlib)
	(cd ${STAGEDIR}${PREFIX}/bin &&	${RM} ${ASCII_TEXTS})

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/EXAMPLES &&	\
	${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	(cd ${STAGEDIR}${EXAMPLESDIR} && ${RM} -r .deps)
.if !defined(WITH_DEBUG)
	${FIND} ${STAGEDIR}${EXAMPLESDIR} -name "*.sprng" | \
		${XARGS} ${STRIP_CMD}
.endif

.include <bsd.port.post.mk>
