# New ports collection makefile for:	smpeg
# Version required:   	0.3.3
# Date created:		2 Feb 2000
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	smpeg-0.3.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.lokigames.com/development/download/smpeg/

MAINTAINER=	cpiazza@FreeBSD.org

LIB_DEPENDS=  	SDL-1.0.2:${PORTSDIR}/devel/sdl

GTK_CONFIG=	${X11BASE}/bin/gtk12-config
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

MAN1=		gtv.1 plaympeg.1

.include <bsd.port.mk>
