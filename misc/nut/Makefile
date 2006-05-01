# New ports collection makefile for:  nut
# Date created:       	Tue Apr 29 12:45:30 GMT 2003
# Whom:                Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	nut
PORTVERSION=	11.4
CATEGORIES=	misc
MASTER_SITES=	http://www.lafn.org/~av832/ \
		http://voodoo.bawue.com/download/
PKGNAMEPREFIX=	health-

MAINTAINER=	freebsd@unixfreunde.de
COMMENT=	Nutrition software to record what you eat

MAN1=		nut.1

USE_GMAKE=	yes
ALL_TARGET=	${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
		s|^CFLAGS=|CFLAGS+=|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA}	${WRKSRC}/raw.data/FOOD_DES.txt ${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/raw.data/NUT_DATA.txt	${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/raw.data/WEIGHT.lib ${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/raw.data/WEIGHT.txt ${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/raw.data/sr18.nut ${PREFIX}/etc/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/nut.1 ${MANPREFIX}/man/man1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
