# $FreeBSD$

PORTNAME=	sysadm-client
PORTVERSION=	1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	SysAdm Qt5 Client

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

WRKSRC_SUBDIR=	src-qt5
USE_QT=		core buildtools_build gui network qmake websockets widgets svg concurrent
USES=		gmake pkgconfig qt:5 tar:xz qmake ssl
USE_GL+=	gl
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	sysadm-ui-qt

.include <bsd.port.mk>
