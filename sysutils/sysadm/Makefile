# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sysadm
PORTVERSION=	1454072401
CATEGORIES=	sysutils

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PC-BSD SysAdm API server

LICENSE=	BSD3CLAUSE

WRKSRC_SUBDIR=	src
USE_QT5=	concurrent core network buildtools qmake gui websockets
USES=		pkgconfig tar:xz qmake
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	pcbsd
GH_PROJECT=	sysadm
GH_TAGNAME=	9a32c2553e5cf2a19fca4f2490d7b0d09d314127

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
IGNORE=		requires FreeBSD 10 or later
.endif

.include <bsd.port.post.mk>
