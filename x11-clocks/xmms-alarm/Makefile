# New ports collection makefile for:	xmms-alarm
# Date created:			15 April 2002
# Whom:				Christian Brueffer <chris@unixpages.org>
#
# $FreeBSD$
#

PORTNAME=	xmms-alarm
PORTVERSION=	0.3.7
CATEGORIES=	x11-clocks
MASTER_SITES=	http://www.snika.uklinux.net/xmms-alarm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Alarm timer plugin for the X Multimedia System

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnometarget gtk12
USE_LIBTOOL_VER=	15

PLIST_FILES=	lib/xmms/General/libalarm.so

# This is to avoid libtool running ldconfig -m ${X11BASE}/lib/xmms/General
do-install:
	${INSTALL_DATA} ${WRKSRC}/src/.libs/libalarm.so ${PREFIX}/lib/xmms/General

.include <bsd.port.mk>
