# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	7.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/wordlist/Hunspell%20en_US/${PORTVERSION}-0/ \
		SF/wordlist/Hunspell%20en_CA/${PORTVERSION}-0/:CA \
		LOCAL/sunpoet/${PORTNAME}/:GB
PKGNAMEPREFIX=	en-
DISTFILES=	hunspell-en_US-${PORTVERSION}-0${EXTRACT_SUFX} \
		hunspell-en_CA-${PORTVERSION}-0${EXTRACT_SUFX}:CA \
		en_GB-1.20.zip:GB
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	English hunspell dictionaries

EXTRACT_SUFX=	.zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/en_CA.aff \
		%%DATADIR%%/en_CA.dic \
		%%DATADIR%%/en_GB.dic \
		%%DATADIR%%/en_GB.aff \
		%%DATADIR%%/en_US.aff \
		%%DATADIR%%/en_US.dic
PLIST_DIRSTRY=	%%DATADIR%%

GBALIASES=	en_AG en_AU en_BS en_BW en_BZ en_DK en_GH en_HK en_IE en_IN \
		en_JM en_NA en_NG en_NZ en_SG en_TT en_ZA en_ZW
USALIASES=	en_PH
.for ALIAS in ${GBALIASES} ${USALIASES}
PLIST_FILES+=	%%DATADIR%%/${ALIAS}.aff \
		%%DATADIR%%/${ALIAS}.dic
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/*.aff ${WRKSRC}/*.dic ${STAGEDIR}${DATADIR}/
.for ALIAS in ${GBALIASES}
	${LN} -s en_GB.aff ${STAGEDIR}${DATADIR}/${ALIAS}.aff
	${LN} -s en_GB.dic ${STAGEDIR}${DATADIR}/${ALIAS}.dic
.endfor
.for ALIAS in ${USALIASES}
	${LN} -s en_US.aff ${STAGEDIR}${DATADIR}/${ALIAS}.aff
	${LN} -s en_US.dic ${STAGEDIR}${DATADIR}/${ALIAS}.dic
.endfor

.include <bsd.port.mk>
