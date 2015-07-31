# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	2.10
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/sunpoet/${PORTNAME}
PKGNAMEPREFIX=	nl-
DISTNAME=	OpenTaal-${PORTVERSION:R}${PORTVERSION:E}G-LO
EXTRACT_SUFX=	.oxt
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Dutch hunspell dictionaries

LICENSE=	BSD2CLAUSE CCbyNCSA3
LICENSE_COMB=	dual
LICENSE_NAME_CCbyNCSA3=Attribution-NonCommercial-ShareAlike 3.0 Unported
LICENSE_TEXT_CCbyNCSA3=http://creativecommons.org/licenses/by/3.0/legalcode
LICENSE_PERMS_CCbyNCSA3=dist-mirror pkg-mirror auto-accept

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/nl_NL.aff \
		%%DATADIR%%/nl_NL.dic

NLALIASES=	nl_AW nl_BE
.for ALIAS in ${NLALIASES}
PLIST_FILES+=	%%DATADIR%%/${ALIAS}.aff \
		%%DATADIR%%/${ALIAS}.dic
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/nl_NL.aff ${STAGEDIR}${DATADIR}/nl_NL.aff
	${INSTALL_DATA} ${WRKSRC}/nl_NL.dic ${STAGEDIR}${DATADIR}/nl_NL.dic
.for ALIAS in ${NLALIASES}
	${LN} -s nl_NL.aff ${STAGEDIR}${DATADIR}/${ALIAS}.aff
	${LN} -s nl_NL.dic ${STAGEDIR}${DATADIR}/${ALIAS}.dic
.endfor

.include <bsd.port.mk>
