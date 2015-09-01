# Created by: Vsevolod Stakhov <vsevolod@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gringo
PORTVERSION=	4.4.0
DISTVERSIONSUFFIX=	-source
PORTREVISION=	1
CATEGORIES=	math devel
MASTER_SITES=	SOURCEFORGE/potassco/${PORTNAME}/${PORTVERSION}

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Grounding algorithm based on semi-naive database evaluation

LICENSE=	GPLv3

BUILD_DEPENDS=	re2c:${PORTSDIR}/devel/re2c

USES=		bison compiler:c++11-lib scons

MAKE_ARGS+=	${MAKE_ENV}
CXXFLAGS+=	-std=c++11

# Unhide std::to_string() with GCC < 4.9 (ports/193528)
CXXFLAGS+=	-D_GLIBCXX_USE_C99

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/build/release/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
