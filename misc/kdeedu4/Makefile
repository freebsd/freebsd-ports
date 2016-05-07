# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdeedu
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	misc kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Entertaining and educational programs for KDE 4 (meta port)

USE_KDE4=	kdeprefix
USES=		metaport

OPTIONS_DEFINE=	ARTIKULATE BLINKEN CANTOR KALGEBRA KALZIUM KANAGRAM KBRUCH KGEOGRAPHY \
		KHANGMAN KIG KITEN KLETTRES KMPLOT KSTARS KTOUCH KTURTLE \
		KWORDQUIZ MARBLE PAIRS PARLEY ROCS STEP
OPTIONS_DEFAULT=	${OPTIONS_DEFINE:NARTIKULATE}

ARTIKULATE_DESC=	Pronunciation trainer
ARTIKULATE_RUN_DEPENDS=	${KDE4_PREFIX}/bin/artikulate:misc/artikulate

BLINKEN_DESC=		Memory enhancement game
BLINKEN_RUN_DEPENDS=	${KDE4_PREFIX}/bin/blinken:games/blinken

CANTOR_DESC=		Frontend to mathematical software
CANTOR_RUN_DEPENDS=	${KDE4_PREFIX}/bin/cantor:math/cantor

KALGEBRA_DESC=		Graph calculator
KALGEBRA_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kalgebra:math/kalgebra

KALZIUM_DESC=		Periodic table of elements
KALZIUM_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kalzium:science/kalzium

KANAGRAM_DESC=		Letter order game
KANAGRAM_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kanagram:games/kanagram

KBRUCH_DESC=		Application to exercise fractions
KBRUCH_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kbruch:math/kbruch

KGEOGRAPHY_DESC=	Geography trainer
KGEOGRAPHY_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kgeography:misc/kgeography

KHANGMAN_DESC=		Hangman game
KHANGMAN_RUN_DEPENDS=	${KDE4_PREFIX}/bin/khangman:games/khangman

KIG_DESC=		Interactive geometry application
KIG_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kig:math/kig

KITEN_DESC=		Japanese reference/study tool
KITEN_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kiten:japanese/kiten

KLETTRES_DESC=		Alphabet learning tool
KLETTRES_RUN_DEPENDS=	${KDE4_PREFIX}/bin/klettres:misc/klettres

KMPLOT_DESC=		Mathematical function plotter
KMPLOT_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kmplot:math/kmplot

KSTARS_DESC=		Desktop planetarium
KSTARS_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kstars:astro/kstars

KTOUCH_DESC=		Touch typing tutor
KTOUCH_RUN_DEPENDS=	${KDE4_PREFIX}/bin/ktouch:misc/ktouch

KTURTLE_DESC=		Educational programming environment
KTURTLE_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kturtle:lang/kturtle

KWORDQUIZ_DESC=		Flash card trainer
KWORDQUIZ_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kwordquiz:misc/kwordquiz

MARBLE_DESC=		Virtual globe and world atlas
MARBLE_USE=		KDE4=marble_run

PAIRS_DESC=		Memory and pairs game
PAIRS_RUN_DEPENDS=	${KDE4_PREFIX}/bin/pairs:games/pairs

PARLEY_DESC=		Vocabulary trainer
PARLEY_RUN_DEPENDS=	${KDE4_PREFIX}/bin/parley:misc/parley

ROCS_DESC=		Graph teory IDE
ROCS_RUN_DEPENDS=	${KDE4_PREFIX}/bin/rocs:math/rocs

STEP_DESC=		Interactive physics simulator
STEP_RUN_DEPENDS=	${KDE4_PREFIX}/bin/step:science/step

.include <bsd.port.mk>
