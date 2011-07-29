# New ports collection makefile for:	es-hunspell
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hunspell
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://extensions.services.openoffice.org/e-files/1639/2/
PKGNAMEPREFIX=	es-
DISTNAME=	es_ANY
EXTRACT_SUFX=	.oxt

MAINTAINER=	office@FreeBSD.org
COMMENT=	Spanish hunspell dictionaries

LICENSE=	GPLv3 LGPL3 MPL
LICENSE_COMB=	dual

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	%%DATADIR%%/es_ES.aff \
		%%DATADIR%%/es_ES.dic
PLIST_DIRSTRY=	%%DATADIR%%

ESALIASES=	es_AR es_BO es_CL es_CO es_CR es_CU es_DO es_EC es_GT es_HN \
		es_MX es_NI es_PA es_PE es_PR es_PY es_SV es_US es_UY es_VE
.for ALIAS in ${ESALIASES}
PLIST_FILES+=	%%DATADIR%%/${ALIAS}.aff \
		%%DATADIR%%/${ALIAS}.dic
.endfor

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKDIR}/es_ANY.aff ${DATADIR}/es_ES.aff
	${INSTALL_DATA} ${WRKDIR}/es_ANY.dic ${DATADIR}/es_ES.dic
.for ALIAS in ${ESALIASES}
	${LN} -s es_ES.aff ${DATADIR}/${ALIAS}.aff
	${LN} -s es_ES.dic ${DATADIR}/${ALIAS}.dic
.endfor

.include <bsd.port.mk>
