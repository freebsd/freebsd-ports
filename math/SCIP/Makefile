# Created by: Yuri Victorovich <yuri@FreeBSD.org>
# $FreeBSD$

PORTNAME=	SCIP
DISTVERSION=	7.0.1
CATEGORIES=	math science
MASTER_SITES=	https://www.scipopt.org/download/release/
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

USES=		compiler:c11 cmake readline tar:tgz
EXTRACT_CMD=	gtar
USE_LDCONFIG=	yes

CXXFLAGS+=	-I${LOCALBASE}/include/soplex

CONFLICTS_BUILD=	Ipopt

.include <bsd.port.mk>
