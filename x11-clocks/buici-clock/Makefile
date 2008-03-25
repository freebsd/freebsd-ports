# New ports collection makefile for:	buici-clock
# Date created:		22nd Nov 2004
# Whom:				Hendrik Scholz <hscholz@raisdorf.net>
#
# $FreeBSD$
#

PORTNAME=	buici-clock
PORTVERSION=	0.4.5
PORTREVISION=	3
CATEGORIES=	x11-clocks
MASTER_SITES=	ftp://ftp.buici.com/pub/buici-clock/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Xlib implementation of an attractive, configurable clock

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_BISON=	build
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_XORG=	x11 xau xdmcp xext ice sm

MAN1=	buici-clock.1
PLIST_FILES=	bin/buici-clock

post-patch:
	@${REINPLACE_CMD} -e 's,_=,+=,' ${WRKSRC}/xo/Makefile.in
	@${REINPLACE_CMD} -e 's|\./configure|./configure ${CONFIGURE_ARGS}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|\./configure|./configure ${CONFIGURE_ARGS}|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
