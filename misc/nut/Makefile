# New ports collection makefile for:  nut
# Date created:       	Tue Apr 29 12:45:30 GMT 2003
# Whom:                Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	nut
PORTVERSION=	8.5
CATEGORIES=	misc
MASTER_SITES=	http://www.lafn.org/~av832/
PKGNAMEPREFIX=	health-
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ponomarew@oberon.net
COMMENT=	Nut is nutrition software to record what you eat

MAN1=		nut.1

USE_GMAKE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nut ${PREFIX}/bin/
	${MKDIR} ${PREFIX}/etc/nut
	${INSTALL_DATA}	${WRKSRC}/raw.data/FOOD_DES.txt ${PREFIX}/etc/nut/
	${INSTALL_DATA} ${WRKSRC}/raw.data/NUT_DATA.txt	${PREFIX}/etc/nut/
	${INSTALL_DATA} ${WRKSRC}/raw.data/WEIGHT.txt	${PREFIX}/etc/nut/
	${INSTALL_DATA} ${WRKSRC}/raw.data/sr15.nut	${PREFIX}/etc/nut/
	${INSTALL_MAN} ${WRKSRC}/nut.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
