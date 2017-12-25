# Created by: Yuri Victorovich <yuri@FreeBSD.org>
# $FreeBSD$

PORTNAME=	SoPlex
DISTVERSION=	3.0.1
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

USES=		cmake:outsource,noninja tar:tgz
USE_LDCONFIG=	yes
PLIST_SUB=	SHL4=${DISTVERSION}.0 SHL2=${DISTVERSION:R}

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1100000
CMAKE_ARGS=	-DFREEBSD_NO_CXX_THREAD_LOCAL_BUG224581:BOOL=ON  # https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=224581
# This also necessitates noninja above for some reason
.endif

.include <bsd.port.post.mk>
