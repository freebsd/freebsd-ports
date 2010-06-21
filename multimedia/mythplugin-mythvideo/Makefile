# New ports collection makefile for:	mythplugin-mythvideo
# Date created:		2010-03-06
# Whom:			Bernhard Froehlich <decke@bluelife.at>
#
# $FreeBSD$
#

PORTNAME=	mythvideo
PORTVERSION=	0.23
CATEGORIES=	multimedia
MASTER_SITES=	http://ftp.osuosl.org/pub/mythtv/ \
		http://ftp.oregonstate.edu/pub/mythtv/
PKGNAMEPREFIX=	mythplugin-
DISTNAME=	mythplugins-${PORTVERSION}

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Video playback and browsing plugin for MythTV

BUILD_DEPENDS=	mythfrontend:${PORTSDIR}/multimedia/mythtv
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/MySQLdb/__init__.py:${PORTSDIR}/databases/py-MySQLdb

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	linguist_build moc_build qmake_build rcc_build uic_build
HAS_CONFIGURE=	yes
USE_PYTHON=	yes
USE_LDCONFIG=	${PREFIX}/lib/mythtv/plugins

PLIST_SUB+=	MYTHSHARE="share/mythtv"

QMAKESPEC?=	${LOCALBASE}/share/qt4/mkspecs/freebsd-g++

CONFIGURE_ARGS=	--prefix="${PREFIX}" --disable-all \
		--enable-mythvideo

.include <bsd.port.mk>
