# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sysadm
PORTVERSION=	201708251128
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
GH_TAGNAME=	991dcdd2f9f7161c4b9d400d3fef1154379e07a7

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
IGNORE=		requires FreeBSD 10 or later
.endif

.include <bsd.port.post.mk>
