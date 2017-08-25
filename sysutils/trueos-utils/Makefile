# Created by: Joe Maloney <jmaloney@ixsystems.com>
# $FreeBSD$

PORTNAME=	trueos-utils
PORTVERSION=	201708251126
CATEGORIES=	sysutils

MAINTAINER=	jmaloney@ixsystems.com
COMMENT=	TrueOS Shell Utilities

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=    sipcalc:net-mgmt/sipcalc \
                eject:sysutils/eject \
                unzip:archivers/unzip \
                tree:sysutils/tree

WRKSRC_SUBDIR=  src-sh/trueos-utils
USE_QT5=        core network buildtools qmake
USES=           pkgconfig python:3.2+ tar:xz
MAKE_ARGS=      PREFIX=${STAGEDIR}${PREFIX}
MAKE_JOBS_UNSAFE=yes

CONFLICTS=      pcbsd-utils*

USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	trueos-utils
GH_TAGNAME=	0d037f67f1e0cad1fe6a862e2494192c9139a5ac

.include <bsd.port.mk>
