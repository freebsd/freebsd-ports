# Ports collection makefile for:	stardict-quick
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
PKGNAMESUFFIX=	-quick
DIST_SUBDIR=	stardict

MAINTAINER=	timur@gnome.org
COMMENT=	Dictionaries from Quick for StarDict

RUN_DEPENDS=	stardict:${PORTSDIR}/textproc/stardict2

NO_BUILD=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}

DICTDIR=	share/gnome/stardict/dic

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

.include <bsd.port.post.mk>
