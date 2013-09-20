# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	20080604
PORTREVISION=	1
CATEGORIES=	vietnamese textproc
MASTER_SITES=	LOCAL/sunpoet/${PORTNAME}/
DISTNAME=	vi_VN-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Vietnamese hunspell dictionaries

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PROJECTHOST=	hunspell-spellcheck-vi

PLIST_FILES=	%%DATADIR%%/vi_VN.aff \
		%%DATADIR%%/vi_VN.dic
PLIST_DIRSTRY=	%%DATADIR%%

NO_STAGE=	yes
do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/vi_VN.aff ${WRKSRC}/vi_VN.dic ${DATADIR}/

.include <bsd.port.mk>
