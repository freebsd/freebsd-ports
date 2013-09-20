# Created by: Timur I. Bakeyev <timur@gnome.org>
# $FreeBSD$

PORTNAME=	stardict
PORTVERSION=	2.4.2
PORTREVISION=	8
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-dictionaries-mova/${PORTVERSION}
PKGNAMESUFFIX=	-dictd_mova
DIST_SUBDIR=	stardict

MAINTAINER=	timur@FreeBSD.org
COMMENT=	Dictionaries from www.mova.org for StarDict

.MAKE.FreeBSD_UL=	yes
NO_BUILD=	yes
USE_BZIP2=	yes

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}

STARDICT_DIR=	share/stardict
DICTDIR=	${STARDICT_DIR}/dic

DISTSUFFIX=	-dictd_www.mova.org

DICTIONARIES=	1000pbio aviation beslov biology brok_and_efr compbe \
		deutsch engcom ethnographic findict geology_enru geology_ruen \
		idioms korolew_enru korolew_ruen mech mueller7 ozhegov \
		religion sc-abbr \
		sinyagin_abbrev sinyagin_alexeymavrin sinyagin_business \
		sinyagin_computer sinyagin_general_er \
		sinyagin_general_re sinyagin_unsorted \
		slovnyk_be-en slovnyk_be-ru slovnyk_be-uk slovnyk_en-be \
		slovnyk_en-ru slovnyk_en-uk slovnyk_ru-be slovnyk_ru-en \
		slovnyk_ru-uk slovnyk_uk-be slovnyk_uk-en slovnyk_uk-ru \
		smiley sokrat_enru sokrat_ruen swedish teo ushakov \
		zhelezyaki_abbr zhelezyaki_analogs

.if !defined(DICT_PACK)
OPTIONS_DEFINE=	ALL
OPTIONS_DEFAULT=	ALL
ALL_DESC=	All dictionaries
.for dict in ${DICTIONARIES}
OPTIONS_DEFINE+=	${dict:U:S|-|_|g}
${dict:U:S|-|_|g}_DESC=	${dict} dictionary
.endfor
.endif

NO_STAGE=	yes
.include <bsd.port.options.mk>

.for dict in ${DICTIONARIES}
.if ${PORT_OPTIONS:MALL} || ${PORT_OPTIONS:M${dict:U:S|-|_|g}}
INSTALL_DICTIONARIES+=	${dict}
.endif
.endfor

.for dict in ${INSTALL_DICTIONARIES}
DISTFILES+=	${PORTNAME}${DISTSUFFIX}_${dict}-${PORTVERSION}${EXTRACT_SUFX}
.endfor

do-build:
	    @${DO_NADA}

do-install:
	    ${MKDIR} ${PREFIX}/${DICTDIR}
.for dict in ${INSTALL_DICTIONARIES}
.for ext in dict.dz idx ifo
	    ${INSTALL_DATA} \
		${WRKDIR}/${PORTNAME}${DISTSUFFIX}_${dict}-${PORTVERSION}/${DISTSUFFIX:C|^-||}_${dict}.${ext} \
		${PREFIX}/${DICTDIR}
	    @${ECHO_CMD} "${DICTDIR}/${DISTSUFFIX:C|^-||}_${dict}.${ext}" >> ${TMPPLIST}
.endfor
.endfor
	    @${ECHO_CMD} "@unexec ${RMDIR} %D/${DICTDIR} 2>/dev/null || true" >> ${TMPPLIST}
	    @${ECHO_CMD} "@unexec ${RMDIR} %D/${STARDICT_DIR} 2>/dev/null || true" >> ${TMPPLIST}

.include <bsd.port.mk>
