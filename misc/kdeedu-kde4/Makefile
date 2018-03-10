# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdeedu
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	4
CATEGORIES=	misc kde
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Entertaining and educational programs for KDE 4 (meta port)

USES=		kde:4 metaport

OPTIONS_DEFINE=	ARTIKULATE BLINKEN CANTOR KALGEBRA KALZIUM KANAGRAM KBRUCH KGEOGRAPHY \
		KHANGMAN KIG KITEN KLETTRES KMPLOT KSTARS KTOUCH KTURTLE \
		KWORDQUIZ MARBLE PAIRS PARLEY ROCS STEP
OPTIONS_DEFAULT=	${OPTIONS_DEFINE:NARTIKULATE}

ARTIKULATE_DESC=	Pronunciation trainer
ARTIKULATE_RUN_DEPENDS=	${KDE_PREFIX}/bin/artikulate:misc/artikulate-kde4

BLINKEN_DESC=		Memory enhancement game
BLINKEN_RUN_DEPENDS=	${KDE_PREFIX}/bin/blinken:games/blinken-kde4

CANTOR_DESC=		Frontend to mathematical software
CANTOR_RUN_DEPENDS=	${KDE_PREFIX}/bin/cantor:math/cantor-kde4

KALGEBRA_DESC=		Graph calculator
KALGEBRA_RUN_DEPENDS=	${KDE_PREFIX}/bin/kalgebra:math/kalgebra-kde4

KALZIUM_DESC=		Periodic table of elements
KALZIUM_RUN_DEPENDS=	${KDE_PREFIX}/bin/kalzium:science/kalzium-kde4

KANAGRAM_DESC=		Letter order game
KANAGRAM_RUN_DEPENDS=	${KDE_PREFIX}/bin/kanagram:games/kanagram-kde4

KBRUCH_DESC=		Application to exercise fractions
KBRUCH_RUN_DEPENDS=	${KDE_PREFIX}/bin/kbruch:math/kbruch-kde4

KGEOGRAPHY_DESC=	Geography trainer
KGEOGRAPHY_RUN_DEPENDS=	${KDE_PREFIX}/bin/kgeography:misc/kgeography-kde4

KHANGMAN_DESC=		Hangman game
KHANGMAN_RUN_DEPENDS=	${KDE_PREFIX}/bin/khangman:games/khangman-kde4

KIG_DESC=		Interactive geometry application
KIG_RUN_DEPENDS=	${KDE_PREFIX}/bin/kig:math/kig-kde4

KITEN_DESC=		Japanese reference/study tool
KITEN_RUN_DEPENDS=	${KDE_PREFIX}/bin/kiten:japanese/kiten-kde4

KLETTRES_DESC=		Alphabet learning tool
KLETTRES_RUN_DEPENDS=	${KDE_PREFIX}/bin/klettres:misc/klettres-kde4

KMPLOT_DESC=		Mathematical function plotter
KMPLOT_RUN_DEPENDS=	${KDE_PREFIX}/bin/kmplot:math/kmplot-kde4

KSTARS_DESC=		Desktop planetarium
KSTARS_RUN_DEPENDS=	${KDE_PREFIX}/bin/kstars:astro/kstars-kde4

KTOUCH_DESC=		Touch typing tutor
KTOUCH_RUN_DEPENDS=	${KDE_PREFIX}/bin/ktouch:misc/ktouch-kde4

KTURTLE_DESC=		Educational programming environment
KTURTLE_RUN_DEPENDS=	${KDE_PREFIX}/bin/kturtle:lang/kturtle-kde4

KWORDQUIZ_DESC=		Flash card trainer
KWORDQUIZ_RUN_DEPENDS=	${KDE_PREFIX}/bin/kwordquiz:misc/kwordquiz-kde4

MARBLE_DESC=		Virtual globe and world atlas
MARBLE_USE=		KDE=marble_run

PAIRS_DESC=		Memory and pairs game
PAIRS_RUN_DEPENDS=	${KDE_PREFIX}/bin/pairs:games/pairs-kde4

PARLEY_DESC=		Vocabulary trainer
PARLEY_RUN_DEPENDS=	${KDE_PREFIX}/bin/parley:misc/parley-kde4

ROCS_DESC=		Graph teory IDE
ROCS_RUN_DEPENDS=	${KDE_PREFIX}/bin/rocs:math/rocs-kde4

STEP_DESC=		Interactive physics simulator
STEP_RUN_DEPENDS=	${KDE_PREFIX}/bin/step:science/step-kde4

.include <bsd.port.mk>
