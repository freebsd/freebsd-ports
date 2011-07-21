# New ports collection makefile for:	es-mythes
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	es-mythes
PORTVERSION=	20101002
CATEGORIES=	textproc
MASTER_SITES=	http://openthes-es.berlios.de/download/
DISTNAME=	OOo2-thes_es_ES

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Spanish thesaurus

LICENSE=	LGPL21

USE_BZIP2=	yes
NO_BUILD=	yes

ESALIASES=	es_AR es_BO es_CL es_CO es_CR es_CU es_DO es_EC es_GT es_HN es_MX \
		es_NI es_PA es_PE es_PR es_PY es_SV es_US es_UY es_VE

PLIST_FILES=	share/mythes/th_es_ES_v2.dat \
		share/mythes/th_es_ES_v2.idx

.for ALIAS in ${ESALIASES}
PLIST_FILES+=	share/mythes/th_${ALIAS}_v2.dat \
		share/mythes/th_${ALIAS}_v2.idx
.endfor

PLIST_DIRS=	share/mythes

do-install:
	@${MKDIR} ${PREFIX}/share/mythes
	@${INSTALL_DATA} ${WRKDIR}/th_es_ES_v2.* ${PREFIX}/share/mythes
	@cd ${PREFIX}/share/mythes; \
	for alias in ${ESALIASES}; do \
	  ${LN} -s th_es_ES_v2.idx th_$${alias}_v2.idx ; \
	  ${LN} -s th_es_ES_v2.dat th_$${alias}_v2.dat ; \
	done

.include <bsd.port.mk>
