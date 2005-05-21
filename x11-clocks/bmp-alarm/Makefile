# New ports collection makefile for:	bmp-alarm
# Date created:				2005-05-22
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	bmp-alarm
PORTVERSION=	0.6.0
CATEGORIES=	x11-clocks
MASTER_SITES=	http://www.snika.uklinux.net/xmms-alarm/

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Alarm timer plugin for beep-media-player

LIB_DEPENDS=	beep.2:${PORTSDIR}/multimedia/beep-media-player

USE_BZIP2=	yes
USE_GNOME=	gnometarget gtk20
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15

PLIST_FILES=	lib/bmp/General/libalarm.so

# This is to avoid libtool running ldconfig -m ${X11BASE}/lib/xmms/General
do-install:
	${INSTALL_DATA} ${WRKSRC}/src/.libs/libalarm.so ${PREFIX}/lib/bmp/General

.include <bsd.port.mk>
