# New ports collection makefile for:	en-hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	en-hunspell
PORTVERSION=	7.1
CATEGORIES=	textproc
MASTER_SITES=	SF/wordlist/Hunspell%20en_US/${PORTVERSION}-0/ \
		SF/wordlist/Hunspell%20en_CA/${PORTVERSION}-0/:CA \
		http://en-gb.pyxidium.co.uk/dictionary/:GB
DISTFILES=	hunspell-en_US-${PORTVERSION}-0${EXTRACT_SUFX} \
		hunspell-en_CA-${PORTVERSION}-0${EXTRACT_SUFX}:CA \
		en_GB.zip:GB

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Hunspell english dictionnaries

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hunspell/en_GB.dic \
		share/hunspell/en_GB.aff \
		share/hunspell/en_CA.aff \
		share/hunspell/en_CA.dic \
		share/hunspell/en_US.aff \
		share/hunspell/en_US.dic \

GBALIASES=	en_AG en_AU en_BS en_BW en_BZ en_DK en_GH en_HK en_IE en_IN en_JM \
		en_NA en_NG en_NZ en_SG en_TT en_ZA en_ZW
USALIASES=	en_PH

.for ALIAS in ${GBALIASES}
PLIST_FILES+=	share/hunspell/${ALIAS}.aff \
		share/hunspell/${ALIAS}.dic
.endfor
.for ALIAS in ${USALIASES}
PLIST_FILES+=	share/hunspell/${ALIAS}.aff \
		share/hunspell/${ALIAS}.dic
.endfor

PLIST_DIRS=	share/hunspell

do-install:
	@${MKDIR} ${PREFIX}/share/hunspell
	@${INSTALL_DATA} ${WRKDIR}/*.dic ${WRKDIR}/*.aff ${PREFIX}/share/hunspell
	@cd ${PREFIX}/share/hunspell; \
	for alias in ${GBALIASES}; do \
		${LN} -s en_GB.aff $${alias}.aff ; \
		${LN} -s en_GB.dic $${alias}.dic ; \
	done; \
	for alias in ${USALIASES}; do \
		${LN} -s en_US.aff $${alias}.aff ; \
		${LN} -s en_US.dic $${alias}.dic ; \
	done; \

.include <bsd.port.mk>
