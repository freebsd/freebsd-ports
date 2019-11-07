# Created by: Harold Gutch <logix@foobar.franken.de>
# $FreeBSD$

PORTNAME=	wmbinclock
PORTVERSION=	0.51
CATEGORIES=	x11-clocks windowmaker

MAINTAINER=	logix@foobar.franken.de
COMMENT=	Binary clock in a windowmaker applet

LICENSE=	GPLv2 BSD3CLAUSE
LICENSE_COMB=	dual

USE_GITHUB=	yes
GH_ACCOUNT=	engerim42

PLIST_FILES=	bin/wmBinClock
USES=		gmake xorg
USE_XORG=	xpm

post-patch:
	@${REINPLACE_CMD} -e 's|#include <values.h>||' ${WRKSRC}/wmBinClock.c
	@${REINPLACE_CMD} -e 's|^CC.*=|CC ?=|' -e 's|^CFLAGS.*=|CFLAGS +=|' \
		-e 's|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmBinClock ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
