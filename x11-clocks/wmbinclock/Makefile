# New ports collection makefile for:	wmBinClock
# Date created:			16 Mar 2003
# Whom:				Harold Gutch <logix@foobar.franken.de>
#
# $FreeBSD$
#

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

post-patch:
	@${REINPLACE_CMD} -e 's|#include <values.h>||' ${WRKSRC}/wmBinClock.c
	@${REINPLACE_CMD} -e 's|^CC.*=|CC ?=|' -e 's|^CFLAGS.*=|CFLAGS +=|' \
		-e 's|/usr/X11R6|${X11BASE}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmBinClock ${PREFIX}/bin

.include <bsd.port.mk>
