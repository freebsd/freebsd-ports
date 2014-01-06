# $FreeBSD$

PORTNAME=	mythes
PORTVERSION=	2014.01.05
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/sunpoet/${PORTNAME}/
PKGNAMEPREFIX=	sl-
DISTNAME=	thes_sl_SI_v2-${PORTVERSION:C/\.//g}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Slovenian thesaurus

LICENSE=	LGPL21

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/th_sl_SI_v2.dat \
		%%DATADIR%%/th_sl_SI_v2.idx
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/th_sl_SI_v2.dat ${WRKSRC}/th_sl_SI_v2.idx ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
