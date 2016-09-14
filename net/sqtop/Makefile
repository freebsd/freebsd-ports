# Created by: Marco Steinbach <coco@webdev.c0c0.intra>
# $FreeBSD$

PORTNAME=	sqtop
DISTVERSION=	2013-12-17
CATEGORIES=	net
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	coco@executive-computing.de
COMMENT=	Console-based display of Squid proxy connections

LICENSE=	GPLv2

BROKEN=		Unfetchable (google code has gone away)

USES=	tar:bzip2

PLIST_FILES=	bin/sqtop \
		man/man1/sqtop.1.gz

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=		NCURSES
OPTIONS_DEFAULT=	NCURSES

NCURSES_CONFIGURE_ENABLE=	ui
NCURSES_USES=	ncurses

.include <bsd.port.mk>
