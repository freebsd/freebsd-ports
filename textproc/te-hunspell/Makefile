# $FreeBSD$

PORTNAME=	hunspell
DISTVERSION=	0.01-2
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	GNU/aspell/dict/te
PKGNAMEPREFIX=	te-
DISTNAME=	aspell6-te-${DISTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Telugu hunspell dictionaries

LICENSE=	GPLv2

BUILD_DEPENDS=	prezip-bin:textproc/aspell \
		wordlist2hunspell:textproc/hunspell

NO_ARCH=	yes
USES=		tar:bzip2

PLIST_FILES=	%%DATADIR%%/te_IN.aff \
		%%DATADIR%%/te_IN.dic

do-build:
	@cd ${WRKSRC}; \
		${LOCALBASE}/bin/prezip-bin -d < te.cwl > te.txt; \
		${SETENV} LANG=te_IN.utf8 LC_ALL=te_IN.utf8 ${LOCALBASE}/bin/wordlist2hunspell te.txt te_IN

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/te_IN.aff ${WRKSRC}/te_IN.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
