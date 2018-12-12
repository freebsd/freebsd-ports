# Created by: Vsevolod Stakhov <vsevolod@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gringo
DISTVERSION=	4.5.4
DISTVERSIONSUFFIX=	-source
PORTREVISION=	2
CATEGORIES=	math devel
MASTER_SITES=	SOURCEFORGE/potassco/${PORTNAME}/${PORTVERSION}

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Grounding algorithm based on semi-naive database evaluation

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	re2c:devel/re2c

USES=		bison compiler:c++11-lib python:2.7 scons
MAKE_ARGS=	${MAKE_ENV}
CXXFLAGS+=	-std=c++11
MAKE_ENV=	WITH_LUA=no

# Unhide std::to_string() with GCC < 4.9 (ports/193528)
CXXFLAGS+=	-D_GLIBCXX_USE_C99

PLIST_FILES=	bin/${PORTNAME} bin/clingo

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/build/debug/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/build/debug/clingo ${STAGEDIR}${PREFIX}/bin/clingo

.include <bsd.port.mk>
