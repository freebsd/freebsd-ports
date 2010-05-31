# New ports collection makefile for: ttf-indic-fonts
# Date created:        March 31 2008
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	indic-ttf
PORTVERSION=	0.5.10
CATEGORIES=	x11-fonts
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/t/ttf-indic-fonts
PKGNAMESUFFIX=	-fonts
DISTNAME=	${PORTNAME:C|(.*)-(.*)|\2-\1|}${PKGNAMESUFFIX}_${PORTVERSION}

MAINTAINER=	jacula@FreeBSD.org
COMMENT=	A collection of truetype Indic fonts

BUILD_DEPENDS+=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale \
		fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

WRKSRC=		${WRKDIR}/${DISTNAME:S|_|-|}

NO_BUILD=	yes

OPTIONS=	BENGALI		"BENGALI font set" on \
		DEVANAGARI	"DEVANAGARI font set" on \
		GUJARATI	"GUJARATI font set" on \
		KANNADA		"KANNADA font set" on \
		MALAYALAM	"MALAYALAM font set" on \
		ORIYA		"ORIYA font set" on \
		PUNJABI		"PUNJABI font set" on \
		TAMIL		"TAMIL font set" on \
		TELUGU		"TELUGU font set" on

.include <bsd.port.pre.mk>

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

.if defined(WITHOUT_BENGALI)
PLIST_SUB+=	BENGALI='@comment '
.else
FONTS=		bengali
PLIST_SUB+=	BENGALI=''
.endif

.if defined(WITHOUT_DEVANAGARI)
PLIST_SUB+=	DEVANAGARI='@comment '
.else
FONTS+=		devanagari
PLIST_SUB+=	DEVANAGARI=''
.endif

.if defined(WITHOUT_GUJARATI)
PLIST_SUB+=	GUJARATI='@comment '
.else
FONTS+=		gujarati
PLIST_SUB+=	GUJARATI=''
.endif

.if defined(WITHOUT_KANNADA)
PLIST_SUB+=	KANNADA='@comment '
.else
FONTS+=		kannada
PLIST_SUB+=	KANNADA=''
.endif

.if defined(WITHOUT_MALAYALAM)
PLIST_SUB+=	MALAYALAM='@comment '
.else
FONTS+=		malayalam
PLIST_SUB+=	MALAYALAM=''
.endif

.if defined(WITHOUT_ORIYA)
PLIST_SUB+=	ORIYA='@comment '
.else
FONTS+=		oriya
PLIST_SUB+=	ORIYA=''
.endif

.if defined(WITHOUT_PUNJABI)
PLIST_SUB+=	PUNJABI='@comment '
.else
FONTS+=		punjabi
PLIST_SUB+=	PUNJABI=''
.endif

.if defined(WITHOUT_TAMIL)
PLIST_SUB+=	TAMIL='@comment '
.else
FONTS+=		tamil
PLIST_SUB+=	TAMIL=''
.endif

.if defined(WITHOUT_TELUGU)
PLIST_SUB+=	TELUGU='@comment '
.else
FONTS+=		telugu
PLIST_SUB+=	TELUGU=''
.endif

SUB_LIST+=	FONTS="${FONTS}"

.if empty(FONTS)
IGNORE=	you have to select at least an option
.endif

do-install: install-fonts install-conf

install-fonts:

.for f in ${FONTS}
	${MKDIR} ${FONTSDIR}/${f}
	${INSTALL_DATA} ${WRKSRC}/ttf-${f}/*.ttf ${FONTSDIR}/${f}
	${INSTALL_DATA} ${WRKSRC}/debian/ttf-${f}${PKGNAMESUFFIX}.copyright ${FONTSDIR}/${f}
	${MKFONTSCALE} ${FONTSDIR}/${f} 2>/dev/null || true
	${MKFONTSDIR} ${FONTSDIR}/${f} 2>/dev/null || true
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

.include <bsd.port.post.mk>
