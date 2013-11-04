# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	addons/204314
PKGNAMEPREFIX=	tk-
DISTNAME=	turkmen_spell_checker-${PORTVERSION}-fx+tb+sm
EXTRACT_SUFX=	.xpi
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Turkmen hunspell dictionaries

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/dictionaries

PLIST_FILES=	%%DATADIR%%/tk.aff \
		%%DATADIR%%/tk.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/tk.aff ${WRKSRC}/tk.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
