# $FreeBSD$

PORTNAME=	hyphen
PORTVERSION=	2013.09.01	# 0.7
PORTEPOCH=	1
CATEGORIES=	textproc spanish
MASTER_SITES=	LOCAL/sunpoet/${PORTNAME}/
PKGNAMEPREFIX=	es-
DISTNAME=	es_any-0.7
EXTRACT_SUFX=	.oxt
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Spanish hyphenation rules

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

PLIST_FILES=	%%DATADIR%%/hyph_es_ES.dic

ESALIASES=	es_AR es_BO es_CL es_CO es_CR es_CU es_DO es_EC es_GT es_HN \
		es_MX es_NI es_PA es_PE es_PR es_PY es_SV es_US es_UY es_VE
.for ALIAS in ${ESALIASES}
PLIST_FILES+=	%%DATADIR%%/hyph_${ALIAS}.dic
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/hyph_es_ANY.dic ${STAGEDIR}${DATADIR}/hyph_es_ES.dic
.for ALIAS in ${ESALIASES}
	${LN} -s hyph_es_ES.dic ${STAGEDIR}${DATADIR}/hyph_${ALIAS}.dic
.endfor

.include <bsd.port.mk>
