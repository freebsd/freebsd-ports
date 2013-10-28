# $FreeBSD$

PORTNAME=	mythes
PORTVERSION=	2013.10.27
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/sunpoet/${PORTNAME}/
PKGNAMEPREFIX=	sk-
DISTNAME=	OOo-Thesaurus2-sk_SK-${PORTVERSION:C/\.//g}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Slovak thesaurus

LICENSE=	BSD

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/th_sk_SK_v2.dat \
		%%DATADIR%%/th_sk_SK_v2.idx
PLIST_DIRSTRY=	%%DATADIR%%

NO_STAGE=	yes
do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/th_sk_SK_v2.dat ${WRKSRC}/th_sk_SK_v2.idx ${DATADIR}/

.include <bsd.port.mk>
