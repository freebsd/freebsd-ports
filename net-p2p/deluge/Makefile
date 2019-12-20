# $FreeBSD$

PORTNAME=	deluge
PORTVERSION=	1.3.15
PORTEPOCH=	2
CATEGORIES=	net-p2p python

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Bittorrent client using Python, GTK2, and libtorrent-rasterbar

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.83:devel/py-dbus@${PY_FLAVOR} \
		${PYGAME} \
		${PYTHON_PKGNAMEPREFIX}notify>=0.1.1:devel/py-notify@${PY_FLAVOR} \
		xdg-utils>=1.0.2:devel/xdg-utils \
		deluge:net-p2p/deluge-cli

USES=		gnome metaport python:-2.7
USE_GNOME=	librsvg2 pygtk2

.include <bsd.port.mk>
