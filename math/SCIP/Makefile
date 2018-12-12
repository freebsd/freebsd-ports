# Created by: Yuri Victorovich <yuri@FreeBSD.org>
# $FreeBSD$

PORTNAME=	SCIP
DISTVERSION=	6.0.0
PORTREVISION=	1
CATEGORIES=	math science
MASTER_SITES=	http://scip.zib.de/download/release/
DISTNAME=	${PORTNAME:tl}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Solver for mixed integer, mixed integer nonlinear programming

LICENSE=	ZIB
LICENSE_NAME=	ZIB ACADEMIC LICENSE
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

EXTRACT_DEPENDS=	gtar:archivers/gtar
LIB_DEPENDS=	libgmp.so:math/gmp \
		libsoplex.so:math/SoPlex

CONFLICTS_BUILD=	Ipopt

USES=		compiler:c11 cmake:outsource readline tar:tgz
EXTRACT_CMD=	gtar
USE_LDCONFIG=	yes
PLIST_SUB=	SHL4=${DISTVERSION}.0 SHL2=${DISTVERSION:R}

CXXFLAGS+=	-I${LOCALBASE}/include/soplex

.include <bsd.port.mk>
