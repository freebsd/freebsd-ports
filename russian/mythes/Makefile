# $FreeBSD$

PORTNAME=	mythes
PORTVERSION=	2007.06.13
PORTREVISION=	1
CATEGORIES=	russian textproc
MASTER_SITES=	LOCAL/sunpoet/${PORTNAME}/
DISTNAME=	thes_ru_RU_v2-${PORTVERSION:C/\.//g}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Russian thesaurus

LICENSE=	LGPL21

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/th_ru_RU_v2.dat \
		%%DATADIR%%/th_ru_RU_v2.idx \
		%%DATADIR%%/th_ru_UA_v2.dat \
		%%DATADIR%%/th_ru_UA_v2.idx
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/th_ru_RU_v2.dat ${WRKSRC}/th_ru_RU_v2.idx ${STAGEDIR}${DATADIR}/
	${LN} -s th_ru_RU_v2.dat ${STAGEDIR}${DATADIR}/th_ru_UA_v2.dat
	${LN} -s th_ru_RU_v2.idx ${STAGEDIR}${DATADIR}/th_ru_UA_v2.idx

.include <bsd.port.mk>
