# Ports collection makefile for:  amap
# Date created:			  23 Mar  2003
# Whom:				  Yonatan <Yonatan@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	amap
PORTVERSION=	1.2.1
CATEGORIES=	security
MASTER_SITES=	http://www.thehackerschoice.com/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	Yonatan@xpert.com
COMMENT=	Application mapper

HAS_CONFIGURE=	yes
USE_REINPLACE=	yes
ALL_TARGET=	all
MAN1=		amap.1

post-patch:
	${REINPLACE_CMD} -e 's|PREFIX|${PREFIX}|' ${WRKSRC}/amap.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/amap ${PREFIX}/bin/
	${MKDIR} ${PREFIX}/share/amap
	${INSTALL_DATA} ${WRKSRC}/appdefs.resp ${PREFIX}/share/amap/
	${INSTALL_DATA} ${WRKSRC}/appdefs.trig ${PREFIX}/share/amap/
	${INSTALL_MAN} ${WRKSRC}/amap.1 ${MANPREFIX}/man/man1/

.include <bsd.port.mk>
