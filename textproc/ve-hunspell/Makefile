# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	20110323
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	addons/46601
PKGNAMEPREFIX=	ve-
DISTNAME=	venda_spell_checker-${PORTVERSION}-tb+fn+fx+sm
EXTRACT_SUFX=	.xpi
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Venda hunspell dictionaries

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/dictionaries

PLIST_FILES=	%%DATADIR%%/ve.aff \
		%%DATADIR%%/ve.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/ve-ZA.aff ${STAGEDIR}${DATADIR}/ve.aff
	${INSTALL_DATA} ${WRKSRC}/ve-ZA.dic ${STAGEDIR}${DATADIR}/ve.dic

.include <bsd.port.mk>
