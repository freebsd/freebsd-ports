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

LICENSE=	BSD

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/nl_NL.aff \
		%%DATADIR%%/nl_NL.dic
PLIST_DIRSTRY=	%%DATADIR%%

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
