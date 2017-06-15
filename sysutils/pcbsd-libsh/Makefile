# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pcbsd-libsh
PORTVERSION=	1438351389
CATEGORIES=	sysutils

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PC-BSD Shell Library

LICENSE=	BSD3CLAUSE

WRKSRC_SUBDIR=	src-sh/libsh
USES=		pkgconfig
NO_BUILD=	yes
NO_ARCH=	yes
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	pcbsd
GH_PROJECT=	pcbsd
GH_TAGNAME=	2c5a0c

PLIST_FILES=	share/pcbsd/scripts/functions.sh

.include <bsd.port.mk>
