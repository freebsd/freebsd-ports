# New ports collection makefile for:	es-hyphen
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	es-hyphen
PORTVERSION=	2005.11.18
CATEGORIES=	textproc
MASTER_SITES=	http://ftp.osuosl.org/pub/openoffice/contrib/dictionaries/
DISTNAME=	hyph_es_ES

MAINTAINER=	office@FreeBSD.org
COMMENT=	Spanish hyphenation rules

USE_ZIP=	yes
NO_BUILD=	yes

ESALIASES=	es_AR es_BO es_CL es_CO es_CR es_CU es_DO es_EC es_GT es_HN \
		es_MX es_NI es_PA es_PE es_PR es_PY es_SV es_US es_UY es_VE

PLIST_FILES=	share/hyphen/hyph_es_ES.dic
.for ALIAS in ${ESALIASES}
PLIST_FILES+=	share/hyphen/hyph_${ALIAS}.dic
.endfor
PLIST_DIRS=	share/hyphen

do-install:
	@${MKDIR} ${PREFIX}/share/hyphen
	@${INSTALL_DATA} ${WRKDIR}/hyph_es_ES.dic ${PREFIX}/share/hyphen
	@cd ${PREFIX}/share/hyphen; \
	for alias in ${ESALIASES}; do \
	  ${LN} -s hyph_es_ES.dic hyph_$${alias}.dic ; \
	done

.include <bsd.port.mk>
