# $FreeBSD$

PORTNAME=	deluge
PORTVERSION=	2.0.3
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	net-p2p python

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Bittorrent client using Python, GTK3, and libtorrent-rasterbar

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.83:devel/py-dbus@${PY_FLAVOR} \
		${PYGAME} \
		xdg-utils>=1.0.2:devel/xdg-utils \
		deluge:net-p2p/deluge-cli

USES=		gnome metaport python:3.5+
USE_GNOME=	gtk30 librsvg2 pygobject3

.include <bsd.port.mk>
