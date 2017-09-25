# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kenlm
PORTVERSION=	20140830
PORTREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	http://kheafield.com/code/
DISTNAME=	${PORTNAME}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	KenLM Language Model Toolkit

BUILD_DEPENDS=	bjam:devel/boost-jam \
		bash:shells/bash
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES+=		compiler:c++11-lib
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ENV+=	BOOST_BUILD_PATH=${WRKSRC}/jam-files/boost-build

BROKEN_aarch64=		fails to compile: target architecture was not detected as supported by Double-Conversion
BROKEN_powerpc64=	fails to compile: error: in QuantTrieAll: difference{inf} between static_cast<double> and static_cast<double> exceeds 0.001%

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/bjam --toolset=${CHOSEN_COMPILER_TYPE} --with-boost=${LOCALBASE} ${_MAKE_JOBS})

do-install:
	(cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} lmplz fragment query filter build_binary dump_counts cat_compressed ${STAGEDIR}${PREFIX}/bin/)

.include <bsd.port.mk>
