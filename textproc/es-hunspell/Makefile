# New ports collection makefile for:	es-hunspell
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	es-hunspell
PORTVERSION=	0.5
CATEGORIES=	textproc
MASTER_SITES=	http://extensions.services.openoffice.org/e-files/1639/2/
DISTNAME=	es_ANY
EXTRACT_SUFX=	.oxt

MAINTAINER=	office@FreeBSD.org
COMMENT=	Spanish hunspell dictionaries

LICENSE=	GPLv3 LGPL3 MPL
LICENSE_COMB=	dual

USE_ZIP=	yes
NO_BUILD=	yes

ESALIASES=	es_AR es_BO es_CL es_CO es_CR es_CU es_DO es_EC es_GT es_HN es_MX \
		es_NI es_PA es_PE es_PR es_PY es_SV es_US es_UY es_VE

PLIST_FILES=	share/hunspell/es_ES.aff \
		share/hunspell/es_ES.dic

.for ALIAS in ${ESALIASES}
PLIST_FILES+=	share/hunspell/${ALIAS}.aff \
		share/hunspell/${ALIAS}.dic
.endfor

PLIST_DIRS=	share/hunspell

do-install:
	@${MKDIR} ${PREFIX}/share/hunspell
	@${INSTALL_DATA} ${WRKDIR}/es_ANY.aff ${PREFIX}/share/hunspell/es_ES.aff
	@${INSTALL_DATA} ${WRKDIR}/es_ANY.dic ${PREFIX}/share/hunspell/es_ES.dic
	@cd ${PREFIX}/share/hunspell; \
	for alias in ${ESALIASES}; do \
		${LN} -s es_ES.aff $${alias}.aff ; \
		${LN} -s es_ES.dic $${alias}.dic ; \
	done

.include <bsd.port.mk>
