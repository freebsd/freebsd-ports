PORTNAME=	deluge
PORTVERSION=	2.1.1
PORTREVISION=	3
PORTEPOCH=	2
CATEGORIES=	net-p2p python

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Bittorrent client using Python, GTK3, and libtorrent-rasterbar
WWW=		https://deluge-torrent.org/

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.83:devel/py-dbus@${PY_FLAVOR} \
		${PYGAME} \
		${PY_PILLOW} \
		xdg-utils>=1.0.2:devel/xdg-utils \
		deluge:net-p2p/deluge-cli

USES=		gnome metaport python
USE_GNOME=	gtk30 librsvg2 pygobject3

.include <bsd.port.mk>
