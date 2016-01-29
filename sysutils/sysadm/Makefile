# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sysadm
PORTVERSION=	1454028596
CATEGORIES=	sysutils

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PC-BSD SysAdm API server

LICENSE=	BSD3CLAUSE

WRKSRC_SUBDIR=	src
USE_QT5=	core network buildtools qmake gui websockets
USES=		pkgconfig tar:xz qmake
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	pcbsd
GH_PROJECT=	sysadm
GH_TAGNAME=	b34ed3073e323bd0ad2b87350eb5e421703d29d4

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
IGNORE=		requires FreeBSD 10 or later
.endif

.include <bsd.port.post.mk>
