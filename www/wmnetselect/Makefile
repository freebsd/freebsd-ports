# New ports collection makefile for:   wmnetselect
# Date created:        7 March 1999
# Whom:                David McNett <nugget@slacker.com>
#
# $FreeBSD$
#

PORTNAME=	wmnetselect
PORTVERSION=	0.8
CATEGORIES=	www windowmaker
MASTER_SITES=	http://home.att.net/~apathos/code/

MAINTAINER=	nugget@slacker.com
COMMENT=	WindowMaker Netscape launcher to display urls from X selection

PLIST_FILES=	bin/wmnetselect
USE_IMAKE=	yes
USE_XPM=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmnetselect ${X11BASE}/bin

.include <bsd.port.mk>
