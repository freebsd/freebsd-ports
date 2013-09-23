# $FreeBSD$

PORTNAME=	hunspell
DISTVERSION=	0.01-2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	GNU/aspell/dict/te
PKGNAMEPREFIX=	te-
DISTNAME=	aspell6-te-${DISTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Telugu hunspell dictionaries

BUILD_DEPENDS=	prezip-bin:${PORTSDIR}/textproc/aspell \
		wordlist2hunspell:${PORTSDIR}/textproc/hunspell

USE_BZIP2=	yes

PLIST_FILES=	%%DATADIR%%/te_IN.aff \
		%%DATADIR%%/te_IN.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-build:
	@cd ${WRKSRC}; \
		${LOCALBASE}/bin/prezip-bin -d < te.cwl > te.txt; \
		${SETENV} LANG=te_IN.utf8 ${LOCALBASE}/bin/wordlist2hunspell te.txt te_IN

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/te_IN.aff ${WRKSRC}/te_IN.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
