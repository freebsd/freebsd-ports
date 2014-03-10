# $FreeBSD$

PORTNAME=	hyphen
PORTVERSION=	2005.11.18
PORTREVISION=	1
CATEGORIES=	textproc spanish
MASTER_SITES=	LOCAL/sunpoet/${PORTNAME}/
PKGNAMEPREFIX=	es-
DISTNAME=	hyph_es_ES-${PORTVERSION:C/\.//g}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Spanish hyphenation rules

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/hyph_es_ES.dic
PLIST_DIRSTRY=	%%DATADIR%%

ESALIASES=	es_AR es_BO es_CL es_CO es_CR es_CU es_DO es_EC es_GT es_HN \
		es_MX es_NI es_PA es_PE es_PR es_PY es_SV es_US es_UY es_VE
.for ALIAS in ${ESALIASES}
PLIST_FILES+=	%%DATADIR%%/hyph_${ALIAS}.dic
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/hyph_es_ES.dic ${STAGEDIR}${DATADIR}/
.for ALIAS in ${ESALIASES}
	${LN} -s hyph_es_ES.dic ${STAGEDIR}${DATADIR}/hyph_${ALIAS}.dic
.endfor

.include <bsd.port.mk>
