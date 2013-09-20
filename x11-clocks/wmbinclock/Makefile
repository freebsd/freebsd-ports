# Created by: Harold Gutch <logix@foobar.franken.de>
# $FreeBSD$

PORTNAME=	wmbinclock
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://www.inxsoft.net/wmbinclock/

MAINTAINER=	logix@foobar.franken.de
COMMENT=	A binary clock in a windowmaker applet

PLIST_FILES=	bin/wmBinClock
USE_GMAKE=	yes
USE_XORG=	xpm

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|#include <values.h>||' ${WRKSRC}/wmBinClock.c
	@${REINPLACE_CMD} -e 's|^CC.*=|CC ?=|' -e 's|^CFLAGS.*=|CFLAGS +=|' \
		-e 's|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmBinClock ${PREFIX}/bin

.include <bsd.port.mk>
