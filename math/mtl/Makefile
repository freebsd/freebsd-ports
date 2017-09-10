# Created by: ijliao
# $FreeBSD$

PORTNAME=	mtl
DISTVERSION=	2.1.2-23.tentative
PORTREVISION=	1
CATEGORIES=	math devel
MASTER_SITES=	http://www.osl.iu.edu/download/research/mtl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Matrix Template Library, Version 2

LICENSE=	MTL
LICENSE_NAME=	Matrix Template Library License
LICENSE_FILE=	${WRKSRC}/license.mtl.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

CONFIGURE_ENV=	CXXCPP="${CXXCPP}"
CXXCPP?=	${CXX} -E
GNU_CONFIGURE=	yes
NO_BUILD=	yes
USES=		perl5
USE_PERL5=	build
WRKSRC=		${WRKDIR}/${DISTNAME:R}

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e '/gnu\*)/,/;;/{/CXX=/d; /CXX_OPTIMIZE_FLAGS=/d; \
	s/CXXFLAGS="/&$$ac_cv_env_CXXFLAGS_value /; }' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|\./.*\.pl[[:blank:]]|${PERL} &|' \
		${WRKSRC}/test/Makefile.in
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${TOUCH} -m

check regression-test test: build
	@cd ${WRKSRC}/test; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} QUICK=-qQ test summary

fulltest: build
	@cd ${WRKSRC}/test; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} QUICK= test summary

.include <bsd.port.pre.mk>

.if defined(USE_GCC) || !empty(CXX:M*g++4*)
CXXFLAGS+=	-fpermissive
.endif

PORTEXAMPLES=	*

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/doubledouble
	@${INSTALL_DATA} ${WRKSRC}/contrib/examples/* ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/contrib/doubledouble/* ${STAGEDIR}${EXAMPLESDIR}/doubledouble

.include <bsd.port.post.mk>
