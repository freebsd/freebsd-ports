# Created by: Thomas Hurst <tom@hur.st>
# $FreeBSD$

PORTNAME=	lnav
PORTVERSION=	0.8.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	tom@hur.st
COMMENT=	Terminal based log file navigator

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libpcre.a:devel/pcre

USE_GITHUB=	yes
GH_ACCOUNT=	tstack

GNU_CONFIGURE=	yes
USES=		autoreconf execinfo ncurses python readline sqlite

PLIST_FILES=	bin/lnav man/man1/lnav.1.gz

.include <bsd.port.mk>
