# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	indic-ttf
PORTVERSION=	0.5.14
CATEGORIES=	x11-fonts
MASTER_SITES=	DEBIAN/pool/main/t/ttf-indic-fonts
PKGNAMESUFFIX=	-fonts
DISTNAME=	${PORTNAME:C|(.*)-(.*)|\2-\1|}${PKGNAMESUFFIX}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A collection of truetype Indic fonts

BUILD_DEPENDS+=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale \
		fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

WRKSRC=		${WRKDIR}/${DISTNAME:S|_|-|}

NO_BUILD=	yes

OPTIONS_MULTI=	FONTS
OPTIONS_MULTI_FONTS=	BENGALI DEVANAGARI GUJARATI KANNADA ORIYA PUNJABI \
			TAMIL TELUGU
OPTIONS_DEFAULT=	BENGALI DEVANAGARI GUJARATI KANNADA ORIYA PUNJABI \
			TAMIL TELUGU

BENGALI_DESC=		BENGALI font set
DEVANAGARI_DESC=	DEVANAGARI font set
GUJARATI_DESC=		GUJARATI font set
KANNADA_DESC=		KANNADA font set
MALAYALAM_DESC=		MALAYALAM font set
ORIYA_DESC=		ORIYA font set
PUNJABI_DESC=		PUNJABI font set
TAMIL_DESC=		TAMIL font set
TELUGU_DESC=		TELUGU font set

NO_STAGE=	yes
.include <bsd.port.options.mk>

FONTSNAME=	${PORTNAME}
FONTSDIR?=	${PREFIX}/lib/X11/fonts/${FONTSNAME}

CONFAVAILDIR?=	${PREFIX}/etc/fonts/conf.avail

MKFONTSCALE?=	${LOCALBASE}/bin/mkfontscale
MKFONTSDIR?=	${LOCALBASE}/bin/mkfontdir
FCCACHE?=	${LOCALBASE}/bin/fc-cache -f -v

PLIST_SUB=	FONTSDIR=${FONTSDIR:S|${PREFIX}/||} \
		CONFAVAILDIR=${CONFAVAILDIR:S|${PREFIX}/||} \
		FCCACHE='${FCCACHE}'

SUB_FILES=	pkg-message
SUB_LIST=	FONTSDIR=${FONTSDIR} \
		CONFAVAILDIR=${CONFAVAILDIR}

.if ${PORT_OPTIONS:MBENGALI}
FONTS=		bengali
PLIST_SUB+=	BENGALI=''
.else
PLIST_SUB+=	BENGALI='@comment '
.endif

.if ${PORT_OPTIONS:MDEVANAGARI}
FONTS+=		devanagari
PLIST_SUB+=	DEVANAGARI=''
.else
PLIST_SUB+=	DEVANAGARI='@comment '
.endif

.if ${PORT_OPTIONS:MGUJARATI}
FONTS+=		gujarati
PLIST_SUB+=	GUJARATI=''
.else
PLIST_SUB+=	GUJARATI='@comment '
.endif

.if ${PORT_OPTIONS:MKANNADA}
FONTS+=		kannada
PLIST_SUB+=	KANNADA=''
.else
PLIST_SUB+=	KANNADA='@comment '
.endif

.if ${PORT_OPTIONS:MMALAYALAM}
FONTS+=		malayalam
PLIST_SUB+=	MALAYALAM=''
.else
PLIST_SUB+=	MALAYALAM='@comment '
.endif

.if ${PORT_OPTIONS:MORIYA}
FONTS+=		oriya
PLIST_SUB+=	ORIYA=''
.else
PLIST_SUB+=	ORIYA='@comment '
.endif

.if ${PORT_OPTIONS:MPUNJABI}
FONTS+=		punjabi
PLIST_SUB+=	PUNJABI=''
.else
PLIST_SUB+=	PUNJABI='@comment '
.endif

.if ${PORT_OPTIONS:MTAMIL}
FONTS+=		tamil
PLIST_SUB+=	TAMIL=''
.else
PLIST_SUB+=	TAMIL='@comment '
.endif

.if ${PORT_OPTIONS:MTELUGU}
FONTS+=		telugu
PLIST_SUB+=	TELUGU=''
.else
PLIST_SUB+=	TELUGU='@comment '
.endif

SUB_LIST+=	FONTS="${FONTS}"

do-install: install-fonts install-conf

install-fonts:

.for f in ${FONTS}
	${MKDIR} ${FONTSDIR}/${f}
	${INSTALL_DATA} ${WRKSRC}/ttf-${f}/*.ttf ${FONTSDIR}/${f}
	${INSTALL_DATA} ${WRKSRC}/debian/ttf-${f}${PKGNAMESUFFIX}.copyright ${FONTSDIR}/${f}
	${MKFONTSCALE} ${FONTSDIR}/${f} 2>/dev/null || ${TRUE}
	${MKFONTSDIR} ${FONTSDIR}/${f} 2>/dev/null || ${TRUE}
.endfor

install-conf:
	${MKDIR} ${CONFAVAILDIR}
.for f in ${FONTS}
	${INSTALL_DATA} ${WRKSRC}/ttf-${f}/90-ttf-${f}${PKGNAMESUFFIX}.conf ${CONFAVAILDIR}/
.endfor

post-install:
	@${ECHO_MSG} "===> Running fc-cache"
	-${FCCACHE} ${FONTSDIR}
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
