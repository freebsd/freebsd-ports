# Created by: Thomas Hurst <tom@hur.st>
# $FreeBSD$

PORTNAME=	lnav
PORTVERSION=	0.8.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	tom@hur.st
COMMENT=	Terminal based log file navigator

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libpcrecpp.so:devel/pcre

USE_GITHUB=	yes
GH_ACCOUNT=	tstack

USES=		autoreconf execinfo gmake ncurses python sqlite readline
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

PLIST_FILES=	bin/lnav man/man1/lnav.1.gz

.include <bsd.port.mk>
