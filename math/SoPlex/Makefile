# Created by: Yuri Victorovich <yuri@FreeBSD.org>
# $FreeBSD$

PORTNAME=	SoPlex
DISTVERSION=	4.0.0
PORTREVISION=	1
CATEGORIES=	math science
MASTER_SITES=	http://soplex.zib.de/download/release/
DISTNAME=	${PORTNAME:tl}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Optimization package for solving linear programming problems (LPs)

LICENSE=	ZIB
LICENSE_NAME=	ZIB ACADEMIC LICENSE
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		cmake compiler:c++11-lang tar:tgz
USE_LDCONFIG=	yes
PLIST_SUB=	SHL4=${DISTVERSION}.0 SHL2=${DISTVERSION:R}

.include <bsd.port.mk>
