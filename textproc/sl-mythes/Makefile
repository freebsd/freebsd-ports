# $FreeBSD$

PORTNAME=	mythes
PORTVERSION=	2013.10.27
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/sunpoet/${PORTNAME}/
PKGNAMEPREFIX=	sl-
DISTNAME=	thes_sl_SI_v2-${PORTVERSION:C/\.//g}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Slovenian thesaurus

LICENSE=	LGPL21

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/th_sl_SI_v2.dat \
		%%DATADIR%%/th_sl_SI_v2.idx
PLIST_DIRSTRY=	%%DATADIR%%

NO_STAGE=	yes
do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/th_sl_SI_v2.dat ${WRKSRC}/th_sl_SI_v2.idx ${DATADIR}/

.include <bsd.port.mk>
