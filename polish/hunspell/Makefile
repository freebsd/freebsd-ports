# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	20131103
CATEGORIES=	polish textproc
MASTER_SITES=	LOCAL/sunpoet/${PORTNAME}
DISTNAME=	sjp-myspell-pl-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Polish hunspell dictionaries

LICENSE=	LGPL21 GPLv2 MPL
LICENSE_COMB=	dual

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	%%DATADIR%%/pl_PL.aff \
		%%DATADIR%%/pl_PL.dic
PLIST_DIRSTRY=	%%DATADIR%%

NO_STAGE=	yes
post-extract:
	@${EXTRACT_CMD} ${WRKDIR}/pl_PL.zip -d ${WRKSRC}/

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/pl_PL.aff ${WRKSRC}/pl_PL.dic ${DATADIR}/

.include <bsd.port.mk>
