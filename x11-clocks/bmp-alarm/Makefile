# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	bmp-alarm
PORTVERSION=	0.6.0
PORTREVISION=	7
CATEGORIES=	x11-clocks
MASTER_SITES=	http://www.snika.uklinux.net/xmms-alarm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Alarm timer plugin for beep-media-player

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-11-26

LIB_DEPENDS=	beep.2:${PORTSDIR}/multimedia/beep-media-player

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/bmp/General/libalarm.so

# This is to avoid libtool running ldconfig -m ${LOCALBASE}/lib/bmp/General
do-install:
	${INSTALL_DATA} ${WRKSRC}/src/.libs/libalarm.so ${PREFIX}/lib/bmp/General

.include <bsd.port.mk>
