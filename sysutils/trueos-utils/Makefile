# Created by: Joe Maloney <jmaloney@ixsystems.com>
# $FreeBSD$

PORTNAME=	trueos-utils
PORTVERSION=	201706210953
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
GH_TAGNAME=	44586a60313eae88bd374212bf1c8ea7b16f7d24

.include <bsd.port.mk>
