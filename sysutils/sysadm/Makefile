# $FreeBSD$

PORTNAME=	sysadm
PORTVERSION=	1.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	SysAdm API server

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

WRKSRC_SUBDIR=	src
USES=		compiler:c++11-lang pkgconfig qmake qt:5 ssl tar:xz
USE_QT=		concurrent core network buildtools qmake gui websockets sql
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	trueos

.include <bsd.port.mk>
