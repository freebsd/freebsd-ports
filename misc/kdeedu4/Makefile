# Created by: Martin Wilke <miwi@FreeBSD.org>
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

OPTIONS_DEFINE=	BLINKEN CANTOR KALGEBRA KALZIUM KANAGRAM KBRUCH KGEOGRAPHY \
		KHANGMAN KIG KITEN KLETTRES KMPLOT KSTARS KTOUCH KTURTLE \
		KWORDQUIZ MARBLE PAIRS PARLEY ROCS STEP
OPTIONS_DEFAULT=	${OPTIONS_DEFINE:NKALZIUM}

BLINKEN_DESC=		Memory enhancement game
CANTOR_DESC=		Frontend to mathematical software
KALGEBRA_DESC=		Graph calculator
KALZIUM_DESC=		Periodic table of elements (requires GCC 4.5+)
KANAGRAM_DESC=		Letter order game
KBRUCH_DESC=		Application to exercise fractions
KGEOGRAPHY_DESC=	Geography trainer
KHANGMAN_DESC=		Hangman game
KIG_DESC=		Interactive geometry application
KITEN_DESC=		Japanese reference/study tool
KLETTRES_DESC=		Alphabet learning tool
KMPLOT_DESC=		Mathematical function plotter
KSTARS_DESC=		Desktop planetarium
KTOUCH_DESC=		Touch typing tutor
KTURTLE_DESC=		Educational programming environment
KWORDQUIZ_DESC=		Flash card trainer
MARBLE_DESC=		Virtual globe and world atlas
PAIRS_DESC=		Memory and pairs game
PARLEY_DESC=		Vocabulary trainer
ROCS_DESC=		Graph teory IDE
STEP_DESC=		Interactive physics simulator

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBLINKEN}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/blinken:${PORTSDIR}/games/blinken
.endif

.if ${PORT_OPTIONS:MCANTOR}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/cantor:${PORTSDIR}/math/cantor
.endif

.if ${PORT_OPTIONS:MKALGEBRA}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kalgebra:${PORTSDIR}/math/kalgebra
.endif

.if ${PORT_OPTIONS:MKALZIUM}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kalzium:${PORTSDIR}/science/kalzium
.endif

.if ${PORT_OPTIONS:MKANAGRAM}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kanagram:${PORTSDIR}/games/kanagram
.endif

.if ${PORT_OPTIONS:MKBRUCH}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kbruch:${PORTSDIR}/math/kbruch
.endif

.if ${PORT_OPTIONS:MKGEOGRAPHY}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kgeography:${PORTSDIR}/misc/kgeography
.endif

.if ${PORT_OPTIONS:MKHANGMAN}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/khangman:${PORTSDIR}/games/khangman
.endif

.if ${PORT_OPTIONS:MKIG}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kig:${PORTSDIR}/math/kig
.endif

.if ${PORT_OPTIONS:MKITEN}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kiten:${PORTSDIR}/japanese/kiten
.endif

.if ${PORT_OPTIONS:MKLETTRES}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/klettres:${PORTSDIR}/misc/klettres
.endif

.if ${PORT_OPTIONS:MKMPLOT}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kmplot:${PORTSDIR}/math/kmplot
.endif

.if ${PORT_OPTIONS:MKSTARS}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kstars:${PORTSDIR}/astro/kstars
.endif

.if ${PORT_OPTIONS:MKTOUCH}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/ktouch:${PORTSDIR}/misc/ktouch
.endif

.if ${PORT_OPTIONS:MKTURTLE}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kturtle:${PORTSDIR}/lang/kturtle
.endif

.if ${PORT_OPTIONS:MKWORDQUIZ}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kwordquiz:${PORTSDIR}/misc/kwordquiz
.endif

.if ${PORT_OPTIONS:MMARBLE}
USE_KDE4+=	marble_run
.endif

.if ${PORT_OPTIONS:MPAIRS}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/pairs:${PORTSDIR}/games/pairs
.endif

.if ${PORT_OPTIONS:MPARLEY}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/parley:${PORTSDIR}/misc/parley
.endif

.if ${PORT_OPTIONS:MROCS}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/rocs:${PORTSDIR}/math/rocs
.endif

.if ${PORT_OPTIONS:MSTEP}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/step:${PORTSDIR}/science/step
.endif

do-install:
	${DO_NADA}

.include <bsd.port.mk>
