# New ports collection makefile for:	nut
# Date created:		Tue Apr 29 12:45:30 GMT 2003
# Whom:			Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	nut
PORTVERSION=	11.4
CATEGORIES=	misc
MASTER_SITES=	http://www.lafn.org/~av832/ \
		http://bsd1.csme.ru/myports/ \
		http://bsd2.csme.ru/myports/ \
		http://bsd3.csme.ru/myports/ \
		http://voodoo.bawue.com/download/
PKGNAMEPREFIX=	health-

MAINTAINER=	freebsd@unixfreunde.de
COMMENT=	Nutrition software to record what you eat

MAN1=		${PORTNAME}.1

USE_BZIP2=	yes
USE_GMAKE=	yes
PORTDOCS=	CREDITS LICENSE README
ALL_TARGET=	${PORTNAME}
RAW=		FOOD_DES.txt NUT_DATA.txt WEIGHT.lib WEIGHT.txt sr18.nut
PLIST_FILES=	bin/${PORTNAME} ${RAW:S,^,%%DATADIR%%/,}
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/local/lib/nut|${DATADIR}|" \
		-e 's|^CFLAGS=|CFLAGS+=|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${INSTALL} -d ${DATADIR}
	${INSTALL_DATA}	${RAW:S,^,${WRKSRC}/raw.data/,} ${DATADIR}/
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
