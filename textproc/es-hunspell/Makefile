# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	2.2
CATEGORIES=	textproc spanish
MASTER_SITES=	https://github.com/sbosio/rla-es/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	es-
DISTNAME=	es_ANY
EXTRACT_SUFX=	.oxt
DIST_SUBDIR=	${PORTNAME}/es-${PORTNAME}-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Spanish hunspell dictionaries

LICENSE=	GPLv3 LGPL3 MPL11
LICENSE_COMB=	dual
LICENSE_FILE_GPLv3=	${WRKSRC}/GPLv3.txt
LICENSE_FILE_LGPL3=	${WRKSRC}/LGPLv3.txt
LICENSE_FILE_MPL11=	${WRKSRC}/MPL-1.1.txt

BROKEN_armv6=	fails to package: tar: Pathname cannot be converted from UTF-8 to current locale
BROKEN_armv7=	fails to package: tar: Pathname cannot be converted from UTF-8 to current locale
BROKEN_mips=	fails to package: tar: Pathname cannot be converted from UTF-8 to current locale

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/es_ES.aff \
		%%DATADIR%%/es_ES.dic

ESALIASES=	es_AR es_BO es_CL es_CO es_CR es_CU es_DO es_EC es_GT es_HN \
		es_MX es_NI es_PA es_PE es_PR es_PY es_SV es_US es_UY es_VE
.for ALIAS in ${ESALIASES}
PLIST_FILES+=	%%DATADIR%%/${ALIAS}.aff \
		%%DATADIR%%/${ALIAS}.dic
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/es_ANY.aff ${STAGEDIR}${DATADIR}/es_ES.aff
	${INSTALL_DATA} ${WRKSRC}/es_ANY.dic ${STAGEDIR}${DATADIR}/es_ES.dic
.for ALIAS in ${ESALIASES}
	${LN} -s es_ES.aff ${STAGEDIR}${DATADIR}/${ALIAS}.aff
	${LN} -s es_ES.dic ${STAGEDIR}${DATADIR}/${ALIAS}.dic
.endfor

.include <bsd.port.mk>
