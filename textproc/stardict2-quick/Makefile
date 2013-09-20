# Created by: Timur I. Bakeyev <timur@gnome.org>
# $FreeBSD$

PORTNAME=	stardict
PORTVERSION=	2.4.2
PORTREVISION=	9
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-dictionaries-quick/${PORTVERSION}
PKGNAMESUFFIX=	-quick
DIST_SUBDIR=	stardict

MAINTAINER=	timur@FreeBSD.org
COMMENT=	Dictionaries from Quick for StarDict

.MAKE.FreeBSD_UL=	yes
NO_BUILD=	yes
USE_BZIP2=	yes

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}

STARDICT_DIR=	share/stardict
DICTDIR=	${STARDICT_DIR}/dic

DICTIONARIES=	afr-eng afr-swe bul-swe dan-deu dan-eng dan-fin dan-fra \
		dan-hun dan-ind dan-ita dan-jpn dan-lat dan-nld dan-nor \
		dan-por dan-rus dan-spa dan-swa dan-swe deu-dan deu-deu \
		deu-eng deu-swe eng-afr eng-dan eng-deu eng-eng eng-fin \
		eng-fra eng-gre eng-hun eng-ind eng-ita eng-jpn eng-lat \
		eng-nld eng-nor eng-por eng-rus eng-spa eng-swa eng-swe \
		esp-swe fin-dan fin-eng fin-swe fra-dan fra-eng fra-swe \
		fry-swe gre-eng gre-swe hun-dan hun-eng hun-swe ind-dan \
		ind-eng ind-swe isl-swe ita-dan ita-eng ita-swe jpn-dan \
		jpn-eng jpn-swe lat-dan lat-eng lat-swe nld-dan nld-eng \
		nld-swe nor-dan nor-eng nor-swe pol-swe por-dan por-eng \
		por-swe rum-swe rus-dan rus-eng rus-swe slo-swe spa-dan \
		spa-eng spa-swe swa-dan swa-eng swa-swe swe-afr swe-bul \
		swe-dan swe-deu swe-eng swe-esp swe-fin swe-fra swe-fry \
		swe-gre swe-hun swe-ind swe-isl swe-ita swe-jpn swe-lat \
		swe-nld swe-nor swe-pol swe-por swe-rum swe-rus swe-slo \
		swe-spa swe-swa swe-wel wel-swe

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
DISTFILES+=	${PORTNAME}${PKGNAMESUFFIX}_${dict}-${PORTVERSION}${EXTRACT_SUFX}
.endfor

do-build:
	@${DO_NADA}

do-install:
		@${MKDIR} ${PREFIX}/${DICTDIR}
.for dict in ${INSTALL_DICTIONARIES}
		${INSTALL_DATA} ${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}_${dict}-${PORTVERSION}/* \
			${PREFIX}/${DICTDIR}
.endfor

post-install:
.for dict in ${INSTALL_DICTIONARIES}
		@cd ${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}_${dict}-${PORTVERSION} && \
		${FIND} -s . -type f -o -type l | ${SED} -e 's|^\.|${DICTDIR}|' >> ${TMPPLIST}
.endfor
		@${ECHO_CMD} "@unexec ${RMDIR} %D/${DICTDIR} 2>/dev/null || true" >> ${TMPPLIST}
		@${ECHO_CMD} "@unexec ${RMDIR} %D/${STARDICT_DIR} 2>/dev/null || true" >> ${TMPPLIST}

.include <bsd.port.mk>
