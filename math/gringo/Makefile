# Created by: Vsevolod Stakhov <vsevolod@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gringo
PORTVERSION=	4.4.0
DISTVERSIONSUFFIX=	-source
PORTREVISION=	1
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	potassco/${PORTNAME}/${PORTVERSION}

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Grounding algorithm based on semi-naive database evaluation

LICENSE=	GPLv3

BUILD_DEPENDS=	re2c:${PORTSDIR}/devel/re2c

USES=	scons bison compiler:c++11-lang

MAKE_ARGS+=	${MAKE_ENV}
CXXFLAGS+=	-std=c++11

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
USE_GCC=	4.8+
.endif

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/build/release/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.post.mk>
