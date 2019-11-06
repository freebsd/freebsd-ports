# Created by: Timur I. Bakeyev <timur@gnome.org>
# $FreeBSD$

PORTNAME=	stardict-quick
PORTVERSION=	2.4.2
PORTREVISION=	9
CATEGORIES=	textproc
MASTER_SITES=	http://download.huzheng.org/Quick/
DIST_SUBDIR=	stardict

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Dictionaries from Quick for StarDict

NO_BUILD=	yes
NO_ARCH=	yes
USES=		tar:bzip2

DATADIR=	${PREFIX}/share/stardict
DICTDIR=	${DATADIR}/dic
PORTDATA=	*

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

OPTIONS_DEFINE=	ALL
OPTIONS_DEFAULT=	ALL
ALL_DESC=	All dictionaries
.for dict in ${DICTIONARIES}
OPTIONS_DEFINE+=	${dict:tu:S|-|_|g}
${dict:tu:S|-|_|g}_DESC=	${dict} dictionary
${dict}_DISTNAME=	${PORTNAME}_${dict}-${PORTVERSION}
.endfor

.include <bsd.port.options.mk>

.for dict in ${DICTIONARIES}
.if ${PORT_OPTIONS:MALL} || ${PORT_OPTIONS:M${dict:tu:S|-|_|g}}
INSTALL_DICTIONARIES+=	${dict}
DISTFILES+=	${${dict}_DISTNAME}${EXTRACT_SUFX}
.endif
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${DICTDIR}
.for dict in ${INSTALL_DICTIONARIES}
	${INSTALL_DATA} ${WRKDIR}/${${dict}_DISTNAME}/* \
		${STAGEDIR}${DICTDIR}
.endfor

.include <bsd.port.mk>
