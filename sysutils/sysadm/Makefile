# $FreeBSD$

PORTNAME=	sysadm
PORTVERSION=	1.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	SysAdm API server

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

WRKSRC_SUBDIR=	src
USE_QT5=	concurrent core network buildtools qmake gui websockets sql
USES=		pkgconfig tar:xz qmake ssl
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	trueos

.include <bsd.port.mk>
