# Created by: Thomas Hurst <tom@hur.st>
# $FreeBSD$

PORTNAME=	lnav
PORTVERSION=	0.8.1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	tom@hur.st
COMMENT=	Terminal based log file navigator

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libpcre.a:devel/pcre \
		${LOCALBASE}/lib/libsqlite3.a:databases/sqlite3

USE_GITHUB=	yes
GH_ACCOUNT=	tstack

GNU_CONFIGURE=	yes
USES=		autoreconf execinfo gmake ncurses python readline

PLIST_FILES=	bin/lnav man/man1/lnav.1.gz

.include <bsd.port.mk>
