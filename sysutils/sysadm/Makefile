# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sysadm
PORTVERSION=	201708101127
CATEGORIES=	sysutils

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	SysAdm API server

LICENSE=	BSD3CLAUSE

WRKSRC_SUBDIR=	src
USE_QT5=	concurrent core network buildtools_build qmake_build websockets sql
USES=		pkgconfig tar:xz qmake ssl
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	sysadm
GH_TAGNAME=	4dded17898321af860be8cf4a224325ac8094d08

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
IGNORE=		requires FreeBSD 10 or later
.endif

.include <bsd.port.post.mk>
