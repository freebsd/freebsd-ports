# New ports collection Makefile for:	kdeedu
# Date created:				2008-01-31
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdeedu
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	misc kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Set of entertaining, educational programs for KDE 4 (meta-port)

LATEST_LINK=	${PORTNAME}4

USE_KDE4=	kdeprefix
NO_BUILD=	yes

OPTIONS=	BLINKEN "Memory enhancement game" on \
		CANTOR "Frontend to mathematical software" on \
		KALGEBRA "Graph calculator" on \
		KALZIUM "Periodic table of elements" on \
		KANAGRAM "Letter order game" on \
		KBRUCH "Application to exercise fractions" on \
		KGEOGRAPHY "Geography trainer" on \
		KHANGMAN "Hangman game" on \
		KIG "Interactive geometry application" on \
		KITEN "Japanese reference/study tool" on \
		KLETTRES "Alphabet learning tool" on \
		KMPLOT "Mathematical function plotter" on \
		KSTARS "Desktop planetarium" on \
		KTOUCH "Touch typing tutor" on \
		KTURTLE "Educational programming environment" on \
		KWORDQUIZ "Flash card trainer" on \
		MARBLE "Virtual globe and world atlas" on \
		PARLEY "Vocabulary trainer" on \
		ROCS "Graph teory IDE" on \
		STEP "Interactive physics simulator" on

.include <bsd.port.options.mk>

.ifndef(WITHOUT_BLINKEN)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/blinken:${PORTSDIR}/games/blinken
.endif

.ifndef(WITHOUT_CANTOR)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/cantor:${PORTSDIR}/math/cantor
.endif

.ifndef(WITHOUT_KALGEBRA)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kalgebra:${PORTSDIR}/math/kalgebra
.endif

.ifndef(WITHOUT_KALZIUM)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kalzium:${PORTSDIR}/science/kalzium
.endif

.ifndef(WITHOUT_KANAGRAM)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kanagram:${PORTSDIR}/games/kanagram
.endif

.ifndef(WITHOUT_KBRUCH)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kbruch:${PORTSDIR}/math/kbruch
.endif

.ifndef(WITHOUT_KGEOGRAPHY)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kgeography:${PORTSDIR}/misc/kgeography
.endif

.ifndef(WITHOUT_KHANGMAN)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/khangman:${PORTSDIR}/games/khangman
.endif

.ifndef(WITHOUT_KIG)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kig:${PORTSDIR}/math/kig
.endif

.ifndef(WITHOUT_KITEN)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kiten:${PORTSDIR}/japanese/kiten
.endif

.ifndef(WITHOUT_KLETTRES)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/klettres:${PORTSDIR}/misc/klettres
.endif

.ifndef(WITHOUT_KMPLOT)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kmplot:${PORTSDIR}/math/kmplot
.endif

.ifndef(WITHOUT_KSTARS)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kstars:${PORTSDIR}/astro/kstars
.endif

.ifndef(WITHOUT_KTOUCH)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/ktouch:${PORTSDIR}/misc/ktouch
.endif

.ifndef(WITHOUT_KTURTLE)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kturtle:${PORTSDIR}/lang/kturtle
.endif

.ifndef(WITHOUT_KWORDQUIZ)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kwordquiz:${PORTSDIR}/misc/kwordquiz
.endif

.ifndef(WITHOUT_MARBLE)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/marble:${PORTSDIR}/astro/marble
.endif

.ifndef(WITHOUT_PARLEY)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/parley:${PORTSDIR}/misc/parley
.endif

.ifndef(WITHOUT_ROCS)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/rocs:${PORTSDIR}/math/rocs
.endif

.ifndef(WITHOUT_STEP)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/step:${PORTSDIR}/science/step
.endif

do-install:
	${DO_NADA}

.include <bsd.port.mk>
