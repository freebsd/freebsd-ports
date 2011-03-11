# New ports collection makefile for:	xmms-alarm
# Date created:			15 April 2002
# Whom:				Christian Brueffer <chris@unixpages.org>
#
# $FreeBSD$
#

PORTNAME=	xmms-alarm
PORTVERSION=	0.3.7
PORTREVISION=	5
CATEGORIES=	x11-clocks
MASTER_SITES=	http://www.snika.uklinux.net/xmms-alarm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Alarm timer plugin for the X Multimedia System

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnometarget gtk12
GNU_CONFIGURE=	yes
USE_XORG=	x11 xaw xmu xpm

PLIST_FILES=	lib/xmms/General/libalarm.so

post-patch:
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/configure

# This is to avoid libtool running ldconfig -m ${LOCALBASE}/lib/xmms/General
do-install:
	${INSTALL_DATA} ${WRKSRC}/src/.libs/libalarm.so ${PREFIX}/lib/xmms/General

.include <bsd.port.mk>
