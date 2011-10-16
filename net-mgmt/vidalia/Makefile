# New ports collection makefile for:	vidalia
# Date created:		2007-02-19
# Whom:			Fabian Keil <fk@fabiankeil.de>
#
# $FreeBSD$
#

PORTNAME=	vidalia
PORTVERSION=	0.2.15
CATEGORIES=	net-mgmt security
MASTER_SITES=	https://archive.torproject.org/tor-package-archive/vidalia/ \
		https://www.torproject.org/dist/vidalia/ \
		http://tor.ccc.de/dist/vidalia/ \
		http://tor.cyberarmy.at/dist/vidalia/ \
		http://www.torservers.net/mirrors/torproject.org/dist/vidalia/

MAINTAINER=	fk@fabiankeil.de
COMMENT=	A graphical Tor controller based on Qt 4.x

USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes
INSTALLS_ICONS=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui moc_build qmake_build rcc_build uic_build network xml linguist_build
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
