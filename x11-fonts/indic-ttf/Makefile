# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	indic-ttf
PORTVERSION=	0.5.14
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	DEBIAN/pool/main/t/ttf-indic-fonts
PKGNAMESUFFIX=	-fonts
DISTNAME=	${PORTNAME:C|(.*)-(.*)|\2-\1|}${PKGNAMESUFFIX}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of truetype Indic fonts

BUILD_DEPENDS+=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale \
		fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

WRKSRC=		${WRKDIR}/${DISTNAME:S|_|-|}

NO_BUILD=	yes

OPTIONS_SUB=		yes
OPTIONS_MULTI=		FONTS
OPTIONS_MULTI_FONTS=	BENGALI DEVANAGARI GUJARATI KANNADA MALAYALAM \
			ORIYA PUNJABI TAMIL TELUGU
OPTIONS_DEFAULT=	BENGALI DEVANAGARI GUJARATI KANNADA MALAYALAM \
			ORIYA PUNJABI TAMIL TELUGU

BENGALI_DESC=		BENGALI font set
DEVANAGARI_DESC=	DEVANAGARI font set
GUJARATI_DESC=		GUJARATI font set
KANNADA_DESC=		KANNADA font set
MALAYALAM_DESC=		MALAYALAM font set
ORIYA_DESC=		ORIYA font set
PUNJABI_DESC=		PUNJABI font set
TAMIL_DESC=		TAMIL font set
TELUGU_DESC=		TELUGU font set

FONTSNAME=	indic-ttf
FONTLOC?=	lib/X11/fonts/indic-ttf
FONTSDIR=	${PREFIX}/${FONTLOC}

CONFAVLOC?=	etc/fonts/conf.avail
CONFAVAILDIR=	${PREFIX}/${CONFAVLOC}

PLIST_SUB=	FONTSDIR=${FONTLOC} \
		CONFAVAILDIR=${CONFAVLOC} \
		FCCACHE='${FCCACHE}'

SUB_FILES=	pkg-message
SUB_LIST=	FONTSDIR=${FONTSDIR} \
		CONFAVAILDIR=${CONFAVAILDIR}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBENGALI}
FONTS+=		bengali
.endif

.if ${PORT_OPTIONS:MDEVANAGARI}
FONTS+=		devanagari
.endif

.if ${PORT_OPTIONS:MGUJARATI}
FONTS+=		gujarati
.endif

.if ${PORT_OPTIONS:MKANNADA}
FONTS+=		kannada
.endif

.if ${PORT_OPTIONS:MMALAYALAM}
FONTS+=		malayalam
.endif

.if ${PORT_OPTIONS:MORIYA}
FONTS+=		oriya
.endif

.if ${PORT_OPTIONS:MPUNJABI}
FONTS+=		punjabi
.endif

.if ${PORT_OPTIONS:MTAMIL}
FONTS+=		tamil
.endif

.if ${PORT_OPTIONS:MTELUGU}
FONTS+=		telugu
.endif

SUB_LIST+=	FONTS="${FONTS}"

do-install: install-fonts install-conf

install-fonts:
.for f in ${FONTS}
	${MKDIR} ${STAGEDIR}${FONTSDIR}/${f}
	${INSTALL_DATA} ${WRKSRC}/ttf-${f}/*.ttf ${STAGEDIR}${FONTSDIR}/${f}
	${INSTALL_DATA} ${WRKSRC}/debian/ttf-${f}${PKGNAMESUFFIX}.copyright \
		${STAGEDIR}${FONTSDIR}/${f}
.endfor

install-conf:
	${MKDIR} ${STAGEDIR}${CONFAVAILDIR}
.for f in ${FONTS}
	${INSTALL_DATA} ${WRKSRC}/ttf-${f}/90-ttf-${f}${PKGNAMESUFFIX}.conf \
		${STAGEDIR}${CONFAVAILDIR}/
.endfor

.include <bsd.port.mk>
