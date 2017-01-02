# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mosesdecoder
PORTVERSION=	2.1.1
DISTVERSIONPREFIX=	RELEASE-
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A statistical machine translation system

BUILD_DEPENDS=	bash:shells/bash \
		bjam:devel/boost-jam
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libRandLM.so:textproc/randlm \
		libirstlm.so:textproc/irstlm
RUN_DEPENDS=	lmplz:textproc/kenlm

USE_GITHUB=	yes
GH_ACCOUNT=	moses-smt

USES=		compiler:c++11-lang shebangfix
SHEBANG_REGEX=	./scripts/.*\.(sh|pl|perl|cgi)

MAKE_ENV+=	BOOST_BUILD_PATH=${WRKSRC}/jam-files/boost-build

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} bjam --with-boost=${LOCALBASE} --with-irstlm=${LOCALBASE} --with-randlm=${LOCALBASE} --without-tcmalloc --notrace --toolset=${CHOSEN_COMPILER_TYPE} debug-symbols=off ${_MAKE_JOBS}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} bjam --with-boost=${LOCALBASE} --with-irstlm=${LOCALBASE} --with-randlm=${LOCALBASE} --without-tcmalloc --notrace --prefix=${STAGEDIR}${PREFIX} --install-scripts=${STAGEDIR}${DATADIR} --toolset=${CHOSEN_COMPILER_TYPE} debug-symbols=off ${_MAKE_JOBS} release
	cd ${STAGEDIR}${PREFIX}/bin && ${RM} build_binary filter fragment lmplz query

.include <bsd.port.mk>
