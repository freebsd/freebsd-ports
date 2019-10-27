# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	2019.10.06
CATEGORIES=	textproc
MASTER_SITES=	SF/wordlist/speller/${PORTVERSION}/
PKGNAMEPREFIX=	en-
DISTFILES=	hunspell-en_US${US_VARIANT}-${PORTVERSION}${EXTRACT_SUFX} \
		hunspell-en_CA${CA_VARIANT}-${PORTVERSION}${EXTRACT_SUFX} \
		hunspell-en_GB${GB_VARIANT}-${PORTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	English hunspell dictionaries

LICENSE=	BSD3CLAUSE

USES=		zip
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

OPTIONS_RADIO=	CA GB US
OPTIONS_RADIO_CA=	CA_STANDARD CA_LARGE
OPTIONS_RADIO_GB=	GB_IZE GB_ISE GB_LARGE
OPTIONS_RADIO_US=	US_STANDARD US_LARGE
OPTIONS_DEFAULT=CA_STANDARD GB_ISE US_STANDARD
GB_IZE_DESC=	en_GB dictionary with -ize spelling
GB_ISE_DESC=	en_GB dictionary with -ise spelling
CA_STANDARD_DESC=	Canadian dictionary considered standard by maintainers
US_STANDARD_DESC=	American dictionary considered standard by maintainers
GB_LARGE_DESC=	Dictionary with more words and multiple variants per word
CA_LARGE_DESC=	${GB_LARGE_DESC}
US_LARGE_DESC=	${GB_LARGE_DESC}

PLIST_FILES=	${DATADIR}/en_CA${CA_VARIANT}.aff \
		${DATADIR}/en_CA${CA_VARIANT}.dic \
		${DATADIR}/README_en_CA${CA_VARIANT}.txt \
		${DATADIR}/en_GB${GB_VARIANT}.dic \
		${DATADIR}/en_GB${GB_VARIANT}.aff \
		${DATADIR}/README_en_GB${GB_VARIANT}.txt \
		${DATADIR}/en_US${US_VARIANT}.aff \
		${DATADIR}/en_US${US_VARIANT}.dic \
		${DATADIR}/README_en_US${US_VARIANT}.txt	\
		${DATADIR}/en_GB.dic \
		${DATADIR}/en_GB.aff \

COPY=		-lh	# Use hardlinks rather than copies under stage/

.for c in CA GB US
.	for v in STANDARD ISE IZE LARGE
${c}_${v}_VARS=		${c}_VARIANT=${v:S/STANDARD//:tl:C/^.+$/-&/}
.	endfor
.endfor

US_LARGE_PLIST_FILES=	${DATADIR}/en_US.aff ${DATADIR}/en_US.dic
CA_LARGE_PLIST_FILES=	${DATADIR}/en_CA.aff ${DATADIR}/en_CA.dic

GBALIASES=	en_AG en_AU en_BS en_BW en_BZ en_DK en_GH en_HK en_IE en_IN \
		en_JM en_NA en_NG en_NZ en_SG en_TT en_ZA en_ZW
USALIASES=	en_PH

.for ALIAS in ${GBALIASES} ${USALIASES}
PLIST_FILES+=	${DATADIR}/${ALIAS}.aff \
		${DATADIR}/${ALIAS}.dic
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/*.aff ${WRKSRC}/*.dic ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/README_*.txt ${STAGEDIR}${DATADIR}/
	${LN} -s en_GB${GB_VARIANT}.aff ${STAGEDIR}${DATADIR}/en_GB.aff
	${LN} -s en_GB${GB_VARIANT}.dic ${STAGEDIR}${DATADIR}/en_GB.dic
.for ALIAS in ${GBALIASES}
	${LN} -s en_GB.aff ${STAGEDIR}${DATADIR}/${ALIAS}.aff
	${LN} -s en_GB.dic ${STAGEDIR}${DATADIR}/${ALIAS}.dic
.endfor
.for ALIAS in ${USALIASES}
	${LN} -s en_US.aff ${STAGEDIR}${DATADIR}/${ALIAS}.aff
	${LN} -s en_US.dic ${STAGEDIR}${DATADIR}/${ALIAS}.dic
.endfor

do-install-CA_LARGE-on:
	${LN} -s en_CA-large.aff ${STAGEDIR}${DATADIR}/en_CA.aff
	${LN} -s en_CA-large.dic ${STAGEDIR}${DATADIR}/en_CA.dic

do-install-US_LARGE-on:
	${LN} -s en_US-large.aff ${STAGEDIR}${DATADIR}/en_US.aff
	${LN} -s en_US-large.dic ${STAGEDIR}${DATADIR}/en_US.dic

# maintainer section:

.if defined(MAINTAINER_MODE)
DISTFILES=	hunspell-en_CA-${PORTVERSION}${EXTRACT_SUFX} \
		hunspell-en_CA-large-${PORTVERSION}${EXTRACT_SUFX} \
		hunspell-en_GB-large-${PORTVERSION}${EXTRACT_SUFX} \
		hunspell-en_GB-ise-${PORTVERSION}${EXTRACT_SUFX} \
		hunspell-en_GB-ize-${PORTVERSION}${EXTRACT_SUFX} \
		hunspell-en_US-${PORTVERSION}${EXTRACT_SUFX} \
		hunspell-en_US-large-${PORTVERSION}${EXTRACT_SUFX}
.endif

.include <bsd.port.mk>
