# New ports collection makefile for:	pcbsd-meta-window_maker
#
# $FreeBSD$
#

PORTNAME=	pcbsd-meta-window_maker
PORTVERSION=	1405258480
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# none

MAINTAINER=	kris@pcbsd.org
COMMENT=	The meta-port pcbsd-meta-window_maker

RUN_DEPENDS=	windowmaker>=0:${PORTSDIR}/x11-wm/windowmaker \
		xconsole>=0:${PORTSDIR}/x11/xconsole \
		xman>=0:${PORTSDIR}/x11/xman \
		xfontsel>=0:${PORTSDIR}/x11-fonts/xfontsel \
		libinotify>=0:${PORTSDIR}/devel/libinotify \
		wmakerconf>=0:${PORTSDIR}/x11-wm/wmakerconf

NO_BUILD=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
