# Created by: Vsevolod Stakhov <vsevolod@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gringo
PORTVERSION=	4.2.1
DISTVERSIONSUFFIX=	-source
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	potassco/${PORTNAME}/${PORTVERSION}

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Grounding algorithm based on semi-naive database evaluation

BUILD_DEPENDS=	re2c:${PORTSDIR}/devel/re2c

USES=	scons lua:51+ bison

MAKE_ARGS+=	${MAKE_ENV} WITH_LUA="lua-${LUA_VER}"
CXXFLAGS+=	-std=c++11 -I${LUA_INCDIR}
LDFLAGS+=	-L${LUA_LIBDIR}

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/build/release/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
