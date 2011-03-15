# New ports collection makefile for:	wmWeather-1.28
# Date created:		26 January 1998
# Whom:			Kris Kennaway <kkennawa@physics.adelaide.edu.au>
#
# $FreeBSD$

PORTNAME=	wmweather
PORTVERSION=	2.4.3
PORTREVISION=	4
CATEGORIES=	misc windowmaker geography
MASTER_SITES=	http://www.godisch.de/debian/wmweather/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A WMaker dockapp which displays meteorological data for your city

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	xmessage:${PORTSDIR}/x11/xmessage
RUN_DEPENDS=	xmessage:${PORTSDIR}/x11/xmessage

CFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib"
WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_GMAKE=	yes
USE_XORG=	xpm

MAN1=		wmweather.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmweather ${PREFIX}/bin/
	${LN} ${PREFIX}/bin/wmweather ${PREFIX}/bin/wmWeather
	${INSTALL_MAN} ${WRKSRC}/wmweather.1 ${PREFIX}/man/man1/
	${INSTALL_DATA} -m 644 ${WRKSRC}/wmweather.conf ${PREFIX}/etc/wmweather.conf.sample
	test -f ${PREFIX}/etc/wmweather.conf || ${CP} ${PREFIX}/etc/wmweather.conf.sample ${PREFIX}/etc/wmweather.conf

.include <bsd.port.mk>
