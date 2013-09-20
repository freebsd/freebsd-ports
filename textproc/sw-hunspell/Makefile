# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	1.46
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	sw-
DISTNAME=	sv-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Swedish hunspell dictionaries

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PROJECTHOST=	dsso

PLIST_FILES=	%%DATADIR%%/sv_FI.aff \
		%%DATADIR%%/sv_FI.dic \
		%%DATADIR%%/sv_SE.aff \
		%%DATADIR%%/sv_SE.dic
PLIST_DIRSTRY=	%%DATADIR%%

NO_STAGE=	yes
do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/sv_SE.aff ${WRKSRC}/sv_SE.dic ${DATADIR}/
	${LN} -s sv_SE.aff ${DATADIR}/sv_FI.aff
	${LN} -s sv_SE.dic ${DATADIR}/sv_FI.dic

.include <bsd.port.mk>
