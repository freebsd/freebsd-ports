# Created by: Vsevolod Stakhov <vsevolod@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gringo
PORTVERSION=	4.5.2
DISTVERSIONSUFFIX=	-source
CATEGORIES=	math devel
MASTER_SITES=	SOURCEFORGE/potassco/${PORTNAME}/${PORTVERSION}

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Grounding algorithm based on semi-naive database evaluation

LICENSE=	GPLv3

BUILD_DEPENDS=	re2c:${PORTSDIR}/devel/re2c

USES=	scons bison compiler:c++11-lang

MAKE_ARGS+=	${MAKE_ENV}
CXXFLAGS+=	-std=c++11
MAKE_ENV+=	WITH_LUA=no

PLIST_FILES=	bin/${PORTNAME} bin/clingo

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
USE_GCC=	yes
.endif

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/build/debug/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/build/debug/clingo ${STAGEDIR}${PREFIX}/bin/clingo

.include <bsd.port.post.mk>
