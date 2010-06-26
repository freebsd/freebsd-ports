# Ports collection Makefile for:	thunderbird-dictionaries
# Date created:				19 February 2006
# Whom:					Matthew Luckie <mjl@luckie.org.nz>
# Based on:				multimedia/mplayer-skins
#
# $FreeBSD$
#

PORTNAME=	thunderbird-dictionaries
PORTVERSION=	20060220
PORTREVISION=	6
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_MOZDEV}
MASTER_SITE_SUBDIR=	dictionaries
DISTFILES=	# filled in later after options
DIST_SUBDIR=	thunderbird

MAINTAINER=	mjl@luckie.org.nz
COMMENT=	Dictionaries for Mozilla Thunderbird

RUN_DEPENDS=	thunderbird>=3.0.0:${PORTSDIR}/mail/thunderbird3

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/dictionaries

# Dictionary files
AF_ZA_FILE=	spell-af-ZA.xpi
BG_FILE=	spell-bg.xpi
CA_FILE=	spell-ca.xpi
CS_FILE=	spell-cs.xpi
CY_GB_FILE=	spell-cy-GB.xpi
DA_FILE=	spell-da.xpi
DE_AT_FILE=	spell-de-AT.xpi
DE_CH_FILE=	spell-de-CH.xpi
DE_DE_FILE=	spell-de-DE.xpi
EL_FILE=	spell-el.xpi
EN_AU_FILE=	spell-en-AU.xpi
EN_CA_FILE=	spell-en-CA.xpi
EN_GB_FILE=	spell-en-GB.xpi
EN_NZ_FILE=	spell-en-NZ.xpi
ES_ES_FILE=	spell-es-ES.xpi
ES_MX_FILE=	spell-es-MX.xpi
FO_FILE=	spell-fo.xpi
FR_FR_FILE=	spell-fr-FR.xpi
GA_FILE=	spell-ga.xpi
GL_FILE=	spell-gl.xpi
HE_IL_FILE=	spell-he-IL.xpi
HR_FILE=	spell-hr.xpi
HU_FILE=	spell-hu.xpi
IA_FILE=	spell-ia.xpi
IT_FILE=	spell-it.xpi
LA_FILE=	spell-la.xpi
LT_FILE=	spell-lt.xpi
LV_LV_FILE=	spell-lv-LV.xpi
MI_FILE=	spell-mi.xpi
MS_FILE=	spell-ms.xpi
NB_FILE=	spell-nb.xpi
NL_FILE=	spell-nl.xpi
NN_FILE=	spell-nn.xpi
PL_FILE=	spell-pl.xpi
PT_FILE=	spell-pt.xpi
PT_BR_FILE=	spell-pt-BR.xpi
RO_FILE=	spell-ro.xpi
RU_FILE=	spell-ru.xpi
SK_FILE=	spell-sk.xpi
SL_FILE=	spell-sl.xpi
SV_FILE=	spell-sv.xpi
UK_FILE=	spell-uk.xpi
ZU_ZA_FILE=	spell-zu-ZA.xpi

# Dictionary options
OPTIONS=	DICT_ALL "all dictionaries" on
OPTIONS+=	DICT_AF_ZA "Afrikaans" off
OPTIONS+=	DICT_BG "Bulgarian" off
OPTIONS+=	DICT_CA "Catalan" off
OPTIONS+=	DICT_HR "Croatian" off
OPTIONS+=	DICT_CS "Czech" off
OPTIONS+=	DICT_DA "Danish" off
OPTIONS+=	DICT_NL "Dutch" off
OPTIONS+=	DICT_EN_AU "English (Australia)" off
OPTIONS+=	DICT_EN_CA "English (Canada)" off
OPTIONS+=	DICT_EN_NZ "English (New Zealand)" off
OPTIONS+=	DICT_EN_GB "English (United Kingdom)" off
OPTIONS+=	DICT_FR_FR "French (France)" off
OPTIONS+=	DICT_FO "Faroese" off
OPTIONS+=	DICT_GL "Galician (Spain)" off
OPTIONS+=	DICT_DE_AT "German (Austria)" off
OPTIONS+=	DICT_DE_DE "German (Germany)" off
OPTIONS+=	DICT_DE_CH "German (Switzerland)" off
OPTIONS+=	DICT_EL "Greek" off
OPTIONS+=	DICT_HE_IL "Hebrew" off
OPTIONS+=	DICT_HU "Hungarian" off
OPTIONS+=	DICT_IA "Interlingua" off
OPTIONS+=	DICT_GA "Irish" off
OPTIONS+=	DICT_IT "Italian" off
OPTIONS+=	DICT_LA "Latin" off
OPTIONS+=	DICT_LV_LV "Latvian" off
OPTIONS+=	DICT_LT "Lithuanian" off
OPTIONS+=	DICT_MS "Malay" off
OPTIONS+=	DICT_MI "Maori" off
OPTIONS+=	DICT_NB "Norwegian (Bokmal)" off
OPTIONS+=	DICT_NN "Norwegian (Nynorsk)" off
OPTIONS+=	DICT_PL "Polish" off
OPTIONS+=	DICT_PT "Portuguese (Portugal)" off
OPTIONS+=	DICT_PT_BR "Portuguese (Brasil)" off
OPTIONS+=	DICT_RO "Romanian" off
OPTIONS+=	DICT_RU "Russian" off
OPTIONS+=	DICT_ES_MX "Spanish (Mexico)" off
OPTIONS+=	DICT_ES_ES "Spanish (Spain)" off
OPTIONS+=	DICT_SK "Slovak" off
OPTIONS+=	DICT_SL "Slovenian" off
OPTIONS+=	DICT_SV "Swedish" off
OPTIONS+=	DICT_UK "Ukrainian" off
OPTIONS+=	DICT_CY_GB "Welsh" off
OPTIONS+=	DICT_ZU_ZA "Zulu (South Africa)" off

.include <bsd.port.pre.mk>

# For batch building, build all dictionaries
.if defined(BATCH)
WITH_DICT_ALL=yes
.endif

# All available dictionaries
ALLDICTS=	AF_ZA BG CA CS CY_GB DA DE_AT DE_CH DE_DE EL EN_AU EN_CA \
		EN_GB EN_NZ ES_ES ES_MX FO FR_FR GA GL HE_IL HR HU IA IT \
		LA LT LV_LV MI MS NB NL NN PL PT PT_BR RO RU SK SL SV \
		UK ZU_ZA

# this dictionary requires special handling in do-install
BG_DICT=	BG

# Build and install all dictionaries
.if defined(WITH_DICT_ALL)
.for f in ${ALLDICTS}
WITH_DICT_${f}=	yes
.endfor
.endif

# Figure out which distfiles to use, and how to construct the plist
.for f in ${ALLDICTS}
.ifdef(WITH_DICT_${f})
PLIST_SUB+=	${f}=""
HAVE_DICT=	yes
DISTFILES+=	${${f}_FILE}
.else
PLIST_SUB+=	${f}="@comment "
.endif
.endfor

# Extract the relevant distfiles
do-extract:
	@${MKDIR} ${WRKSRC}
.for f in ${ALLDICTS}
.ifdef(WITH_DICT_${f})
	@${UNZIP_CMD} -q ${DISTDIR}/${DIST_SUBDIR}/${${f}_FILE} -d ${WRKSRC}/${${f}_FILE}
.endif
.endfor

# Check to make sure that at least one dictionary was selected
do-build:
.if !defined(HAVE_DICT)
	@${ECHO_MSG} "No dictionary selected"
	@${FALSE}
.else
	@${DO_NADA}
.endif

# Install the requested dictionaries
do-install:
.for f in ${ALLDICTS}
.ifdef(WITH_DICT_${f})
.if ${BG_DICT}==${f}
	@${INSTALL_DATA} \
		${WRKSRC}/${${f}_FILE}/bin/components/myspell/${${f}_FILE:S/spell-//:S/xpi//}aff \
		${PREFIX}/lib/thunderbird/dictionaries
	@${INSTALL_DATA} \
		${WRKSRC}/${${f}_FILE}/bin/components/myspell/${${f}_FILE:S/spell-//:S/xpi//}dic \
		${PREFIX}/lib/thunderbird/dictionaries
.else
	@${INSTALL_DATA} \
		${WRKSRC}/${${f}_FILE}/${${f}_FILE:S/spell-//:S/xpi//}aff \
		${PREFIX}/lib/thunderbird/dictionaries
	@${INSTALL_DATA} \
		${WRKSRC}/${${f}_FILE}/${${f}_FILE:S/spell-//:S/xpi//}dic \
		${PREFIX}/lib/thunderbird/dictionaries
.endif
.endif
.endfor

.include <bsd.port.post.mk>
