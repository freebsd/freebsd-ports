# New ports collection makefile for:  nut
# Date created:       	Tue Apr 29 12:45:30 GMT 2003
# Whom:                Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	nut
PORTVERSION=	9.8
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.lafn.org/~av832/
PKGNAMEPREFIX=	health-

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Nut is nutrition software to record what you eat

MAN1=		nut.1

USE_SIZE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e \
	's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA}	${WRKSRC}/raw.data/FOOD_DES.txt \
		${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/raw.data/NUT_DATA.txt	\
		${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/raw.data/WEIGHT.txt \
		${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/raw.data/sr16.nut \
		${PREFIX}/etc/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/nut.1 ${PREFIX}/man/man1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
