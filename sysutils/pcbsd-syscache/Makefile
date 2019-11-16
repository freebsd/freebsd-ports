# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pcbsd-syscache
PORTVERSION=	1439494375
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PC-BSD SysCache Utility

LICENSE=	BSD3CLAUSE

DEPRECATED=	Abandoned upstream
EXPIRATION_DATE=	2019-12-15

WRKSRC_SUBDIR=	src-sh/syscache
USE_QT=		core network buildtools qmake
USES=		pkgconfig qt:5
NO_BUILD=	yes
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

PLIST_FILES=	bin/syscache \
		bin/syscache-daemon \
		etc/rc.d/syscache

USE_GITHUB=	yes
GH_ACCOUNT=	pcbsd
GH_PROJECT=	pcbsd
GH_TAGNAME=	3c4d2b

.include <bsd.port.mk>
