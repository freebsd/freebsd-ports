# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pcbsd-utils
PORTVERSION=	1440778617
CATEGORIES=	sysutils

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PC-BSD Command-Line Utilities

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	sipcalc:net-mgmt/sipcalc \
		eject:sysutils/eject

WRKSRC_SUBDIR=	src-sh/pcbsd-utils
USE_QT5=	core network buildtools qmake
USES=		pkgconfig tar:xz
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	pcbsd
GH_PROJECT=	pcbsd
GH_TAGNAME=	3c4d2b

.include <bsd.port.mk>
