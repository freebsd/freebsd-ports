# $FreeBSD$

PORTNAME=	mythes
PORTVERSION=	2007.09.26
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/sunpoet/${PORTNAME}/
PKGNAMEPREFIX=	cs-
DISTNAME=	thes_cs_CZ_v2-${PORTVERSION:C/\.//g}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Czech thesaurus

LICENSE=	BSD

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/th_cs_CZ_v2.dat \
		%%DATADIR%%/th_cs_CZ_v2.idx
PLIST_DIRSTRY=	%%DATADIR%%

NO_STAGE=	yes
do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/th_cs_CZ_v2.dat ${WRKSRC}/th_cs_CZ_v2.idx ${DATADIR}/

.include <bsd.port.mk>
