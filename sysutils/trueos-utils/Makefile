# Created by: Joe Maloney <jmaloney@ixsystems.com>
# $FreeBSD$

PORTNAME=	trueos-utils
PORTVERSION=	201710251127
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
GH_TAGNAME=	3782f44aee56ef90e6a5bf7708244083059f7281

.include <bsd.port.mk>
