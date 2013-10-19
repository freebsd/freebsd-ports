# $FreeBSD$

PORTNAME=	v4l_compat
PORTVERSION=	1.0.${DUMMYDATE}
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	LOCAL/kwm

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Video4Linux IOCTL header files

LICENSE=	GPLv2

DUMMYDATE=	20120501

NO_BUILD=	yes
BASE_HEADERS=	input.h uinput.h videodev.h videodev2.h
DVB_HEADERS=	audio.h ca.h dmx.h frontend.h net.h osd.h version.h video.h

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/linux/dvb
	cd ${WRKSRC}; ${INSTALL_DATA} ${BASE_HEADERS} ${STAGEDIR}${PREFIX}/include/linux/
	cd ${WRKSRC}/dvb; ${INSTALL_DATA} ${DVB_HEADERS} ${STAGEDIR}${PREFIX}/include/linux/dvb/

.include <bsd.port.mk>
