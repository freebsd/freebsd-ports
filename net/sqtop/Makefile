PORTNAME=	sqtop
DISTVERSIONPREFIX=	v
DISTVERSION=	2015-02-08
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	coco@executive-computing.de
COMMENT=	Console-based display of Squid proxy connections
WWW=		https://github.com/paleg/sqtop/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	paleg

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/sqtop \
		share/man/man1/sqtop.1.gz

OPTIONS_DEFINE=		NCURSES
OPTIONS_DEFAULT=	NCURSES

NCURSES_CONFIGURE_ENABLE=	ui
NCURSES_USES=	ncurses

.include <bsd.port.mk>
