# $FreeBSD$

PORTNAME=	stardict-dict-fa_IR
PORTVERSION=	1.0.0
CATEGORIES=	textproc
MASTER_SITES=	SF/pyglossary/dic/English-Persion/
DISTNAME=	Open%20Dictionary%20aka%20QueerDick-2010-09-28-rich
DIST_SUBDIR=	stardict

MAINTAINER=	javad.kouhi@gmail.com
COMMENT=	English-Persian dictionary for stardict

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
WRKSRC=		"${WRKDIR}/Open Dictionary aka QueerDick-2010-09-28-rich"

PLIST_FILES=	share/stardict/dic/Arianpur-OpenDictionary.dict.dz \
		share/stardict/dic/Arianpur-OpenDictionary.idx \
		share/stardict/dic/Arianpur-OpenDictionary.ifo
PLIST_DIRSTRY=	share/stardict/dic \
		share/stardict

NO_STAGE=	yes
do-install:
	${MKDIR} ${PREFIX}/share/stardict/dic/
	${INSTALL_DATA} ${WRKSRC}/Arianpur-OpenDictionary.dict.dz ${PREFIX}/share/stardict/dic/
	${INSTALL_DATA} ${WRKSRC}/Arianpur-OpenDictionary.idx ${PREFIX}/share/stardict/dic/
	${INSTALL_DATA} ${WRKSRC}/Arianpur-OpenDictionary.ifo ${PREFIX}/share/stardict/dic/

.include <bsd.port.mk>
