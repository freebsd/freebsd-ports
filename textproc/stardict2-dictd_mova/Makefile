# Ports collection makefile for:	stardict-dictd_www.mova.org
# Date created:				16 Dec 2004
# Whom:					Timur I. Bakeyev <timur@gnome.org>
# $FreeBSD$
#

PORTNAME=	stardict
PORTVERSION=	2.4.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	stardict
PKGNAMESUFFIX=	-dictd_mova
DIST_SUBDIR=	stardict

MAINTAINER=	timur@gnome.org
COMMENT=	Dictionaries from www.mova.org for StarDict

RUN_DEPENDS=	stardict:${PORTSDIR}/textproc/stardict2

NO_BUILD=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}

DICTDIR=	share/gnome/stardict/dic

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
OPTIONS=	ALL "All dictionaries" on
.for dict in ${DICTIONARIES}
OPTIONS+=	${dict:U:S|-|_|g} "${dict} dictionary" off
.endfor
.endif

.include <bsd.port.pre.mk>

.for dict in ${DICTIONARIES}
.if defined(WITH_ALL) || defined(WITH_${dict:U:S|-|_|g})
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

.include <bsd.port.post.mk>
