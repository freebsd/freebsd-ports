# $FreeBSD$

PORTNAME=	deluge
PORTVERSION=	1.3.13
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net-p2p python

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Bittorrent client using Python, GTK2, and libtorrent-rasterbar

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.83:devel/py-dbus \
		${PYTHON_PKGNAMEPREFIX}game>=1.8.1:devel/py-game \
		${PYTHON_PKGNAMEPREFIX}notify>=0.1.1:devel/py-notify \
		xdg-utils>=1.0.2:devel/xdg-utils \
		deluge:net-p2p/deluge-cli
USE_GNOME=	librsvg2 pygtk2
USES=		python:-2.7 metaport

.include <bsd.port.mk>
