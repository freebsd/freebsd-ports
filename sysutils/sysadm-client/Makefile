# $FreeBSD$

PORTNAME=	sysadm-client
PORTVERSION=	1.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	SysAdm Qt5 Client

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

WRKSRC_SUBDIR=	src-qt5
USES=		compiler:c++11-lang gmake pkgconfig qmake ssl qt:5 tar:xz
USE_QT=		core buildtools_build gui network qmake websockets widgets svg concurrent
USE_GL+=	gl
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	sysadm-ui-qt

.include <bsd.port.mk>
