# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pcbsd-syscache
PORTVERSION=	1438369862
CATEGORIES=	sysutils

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PC-BSD SysCache Utility

LICENSE=	BSD3CLAUSE

WRKSRC_SUBDIR=	src-sh/syscache
USE_QT5=	core network buildtools qmake
USES=		pkgconfig tar:xz
NO_BUILD=	yes
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

PLIST_FILES=	bin/syscache \
		bin/syscache-daemon \
		etc/rc.d/syscache

USE_GITHUB=	yes
GH_ACCOUNT=	pcbsd
GH_PROJECT=	pcbsd
GH_TAGNAME=	2c5a0c

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
IGNORE=		requires FreeBSD 10 or later
.endif

.include <bsd.port.post.mk>
