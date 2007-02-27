#
# Ports collection makefile for:        tv-grab-au
# Date created:                         27 February 2007
# Whom:                                 Greg Lehey <grog@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	tv_grab_au
PORTVERSION=	0.6.2
CATEGORIES=	multimedia
MASTER_SITES=	http://www.onlinetractorparts.com.au/rohbags/xmltvau/
# DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	grog@FreeBSD.org
COMMENT=	X 'tv_grab_au' is an XMLTV grabber for Australian TV programmes

RUN_DEPENDS=	tv_check:${PORTSDIR}/textproc/p5-xmltv

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
		${INSTALL} ${WRKDIR}/tv_grab_au ${PREFIX}/bin
		${MKDIR} ${PREFIX}/share/p5-xmltv/tv_grab_au
		${INSTALL} ${WRKDIR}/channel_ids ${PREFIX}/share/p5-xmltv/tv_grab_au/channel_ids

.include <bsd.port.mk>
