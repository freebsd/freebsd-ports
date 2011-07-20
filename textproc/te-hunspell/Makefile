# New ports collection makefile for:	te-hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	te-hunspell
DISTVERSION=	0.01-2
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.gnu.org/gnu/aspell/dict/te/
DISTNAME=	aspell6-te-${DISTVERSION}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Telugu hunspell dictionaries

BUILD_DEPENDS=	wordlist2hunspell:${PORTSDIR}/textproc/hunspell \
		prezip-bin:${PORTSDIR}/textproc/aspell
USE_BZIP2=	yes

PLIST_FILES=	share/hunspell/te_IN.aff \
		share/hunspell/te_IN.dic

PLIST_DIRS=	share/hunspell

do-build:
	@cd ${WRKSRC}; \
	${LOCALBASE}/bin/prezip-bin -d < te.cwl > te.txt; \
	LANG=te_IN.utf8	${LOCALBASE}/bin/wordlist2hunspell te.txt te_IN

do-install:
	@${MKDIR} ${PREFIX}/share/hunspell
	@${INSTALL_DATA} ${WRKSRC}/te_IN.aff ${PREFIX}/share/hunspell
	@${INSTALL_DATA} ${WRKSRC}/te_IN.dic ${PREFIX}/share/hunspell

.include <bsd.port.mk>
