# New ports collection makefile for:   wmnetselect
# Version required:    0.4
# Date created:        7 March 1999
# Whom:                David McNett <nugget@slacker.com>
#
# $FreeBSD$
#

DISTNAME=	wmnetselect-0.8
CATEGORIES=	www windowmaker
MASTER_SITES=	http://home.att.net/~apathos/code/

MAINTAINER=	nugget@slacker.com

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmnetselect ${X11BASE}/bin

.include <bsd.port.mk>
