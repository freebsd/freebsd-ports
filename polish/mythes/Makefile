# $FreeBSD$

PORTNAME=	mythes
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	polish textproc
MASTER_SITES=	SF/synonimy/synonimy/${PORTVERSION}/
DISTNAME=	OOo2-Thesaurus-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Polish thesaurus

LICENSE=	LGPL21

EXTRACT_SUFX=	.zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/th_pl_PL_v2.dat \
		%%DATADIR%%/th_pl_PL_v2.idx
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/th_pl_PL_v2.dat ${WRKSRC}/th_pl_PL_v2.idx ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
