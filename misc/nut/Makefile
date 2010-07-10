# New ports collection makefile for:	nut
# Date created:		Tue Apr 29 12:45:30 GMT 2003
# Whom:			Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	nut
PORTVERSION=	15.7
CATEGORIES=	misc
MASTER_SITES=	SF
PKGNAMEPREFIX=	health-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Nutrition software to record what you eat

USE_GMAKE=	yes
PORTDOCS=	CREDITS LICENSE README nut.html README.DOS
DOCSDIR=	${PREFIX}/share/doc/${UNIQUENAME}
ALL_TARGET=	${PORTNAME}
PLIST_FILES=	bin/${PORTNAME} %%DATADIR%%/FOOD_DES.txt \
		%%DATADIR%%/NUT_DATA.txt %%DATADIR%%/WEIGHT.lib \
		%%DATADIR%%/WEIGHT.txt %%DATADIR%%/sr22.nut
PLIST_DIRS=	%%DATADIR%%
MAN1=		${PORTNAME}.1

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/local/lib/nut|${DATADIR}|" \
		-e 's|^CFLAGS=|CFLAGS+=|g;s|-Os||;s|gcc|$${CC}|' ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL} -d ${DATADIR}/
	@cd ${WRKSRC}/raw.data/ && ${COPYTREE_SHARE} . ${DATADIR}/
	@${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1/
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
