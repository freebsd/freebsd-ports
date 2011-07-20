# New ports collection makefile for:	hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hunspell
PORTVERSION=	20110608
CATEGORIES=	portuguese textproc
MASTER_SITES=	http://natura.di.uminho.pt/download/sources/Dictionaries/hunspell/ \
		http://www.broffice.org/files/:BR
DISTFILES=	hunspell-pt_PT-${PORTVERSION}.tar.gz \
		pt_BR-2011-05-27AOC.zip:BR

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Hunspell portuguese dictionnary

# rely on bsdtar ability to extract .gz and .zip archives
EXTRACT_CMD=	${CAT}
EXTRACT_BEFORE_ARGS=

NO_BUILD=	yes
WRKSRC=	${WRKDIR}/hunspell-pt_PT-${PORTVERSION}

PLIST_FILES=	share/hunspell/pt_PT.aff \
		share/hunspell/pt_PT.dic \
		share/hunspell/pt_BR.aff \
		share/hunspell/pt_BR.dic
PLIST_DIRS=	share/hunspell

do-install:
		@${MKDIR} ${PREFIX}/share/hunspell
		@${INSTALL_DATA} ${WRKDIR}/pt_BR.aff \
			${WRKDIR}/pt_BR.dic \
			${WRKSRC}/pt_PT.aff \
			${WRKSRC}/pt_PT.dic \
			${PREFIX}/share/hunspell/

.include <bsd.port.mk>
