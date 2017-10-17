# Created by: Joe Maloney <jmaloney@ixsystems.com>
# $FreeBSD$

PORTNAME=	pc-diskmanager
PORTVERSION=	201710171153
CATEGORIES=	sysutils

MAINTAINER=	jmaloney@ixsystems.com
COMMENT=	TrueOS QT5 Disk Manager

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${LOCALBASE}/bin/qsudo:sysutils/qsudo

WRKSRC_SUBDIR=  src-qt5
MAKE_ARGS=      PREFIX=${STAGEDIR}${PREFIX}

CONFLICTS=      pcbsd-utils-[0-9]*

MAKE_JOBS_UNSAFE=yes
ONLY_FOR_ARCHS= amd64
USE_LDCONFIG=   yes
USE_QT5=        core gui network svg linguist_build \
		buildtools_build widgets
USES=           qmake shebangfix tar:xz

WRKSRC_SUBDIR=  src-qt5

QMAKE_ARGS=     CONFIG+="configure"

USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	pc-diskmanager
GH_TAGNAME=	1e7c8f8d158105ce387b909f47be371ba56a5e12

.include <bsd.port.mk>
