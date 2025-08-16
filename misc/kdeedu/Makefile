PORTNAME=	kdeedu
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	misc education kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Entertaining and educational programs for KDE (meta port)
WWW=		https://apps.kde.org/categories/education/

USES=		kde:6 metaport

OPTIONS_DEFINE=	ARTIKULATE BLINKEN CANTOR KALGEBRA KALZIUM KANAGRAM KBRUCH KGEOGRAPHY \
		KHANGMAN KIG KITEN KLETTRES KMPLOT KTOUCH KTURTLE \
		KWORDQUIZ MARBLE MINUET PARLEY ROCS STEP
OPTIONS_DEFAULT=	${OPTIONS_DEFINE:NKIG}
OPTIONS_DEFAULT_amd64=	KIG
OPTIONS_DEFAULT_i386=	KIG

ARTIKULATE_DESC=	Pronunciation trainer
ARTIKULATE_RUN_DEPENDS=	artikulate>=${KDE_APPLICATIONS_VERSION}:misc/artikulate

BLINKEN_DESC=		Memory enhancement game
BLINKEN_RUN_DEPENDS=	blinken>=${KDE_APPLICATIONS_VERSION}:games/blinken

CANTOR_DESC=		Frontend to mathematical software
CANTOR_RUN_DEPENDS=	cantor>=${KDE_APPLICATIONS_VERSION}:math/cantor

KALGEBRA_DESC=		Graph calculator
KALGEBRA_RUN_DEPENDS=	kalgebra>=${KDE_APPLICATIONS_VERSION}:math/kalgebra

KALZIUM_DESC=		Periodic table of elements
KALZIUM_RUN_DEPENDS=	kalzium>=${KDE_APPLICATIONS_VERSION}:science/kalzium

KANAGRAM_DESC=		Letter order game
KANAGRAM_RUN_DEPENDS=	kanagram>=${KDE_APPLICATIONS_VERSION}:games/kanagram

KBRUCH_DESC=		Application to exercise fractions
KBRUCH_RUN_DEPENDS=	kbruch>=${KDE_APPLICATIONS_VERSION}:math/kbruch

KGEOGRAPHY_DESC=	Geography trainer
KGEOGRAPHY_RUN_DEPENDS=	kgeography>=${KDE_APPLICATIONS_VERSION}:misc/kgeography

KHANGMAN_DESC=		Hangman game
KHANGMAN_RUN_DEPENDS=	khangman>=${KDE_APPLICATIONS_VERSION}:games/khangman

KIG_DESC=		Interactive geometry application
KIG_RUN_DEPENDS=	kig>=${KDE_APPLICATIONS_VERSION}:math/kig

KITEN_DESC=		Japanese reference/study tool
KITEN_RUN_DEPENDS=	ja-kiten>=${KDE_APPLICATIONS_VERSION}:japanese/kiten

KLETTRES_DESC=		Alphabet learning tool
KLETTRES_RUN_DEPENDS=	klettres>=${KDE_APPLICATIONS_VERSION}:misc/klettres

KMPLOT_DESC=		Mathematical function plotter
KMPLOT_RUN_DEPENDS=	kmplot>=${KDE_APPLICATIONS_VERSION}:math/kmplot

KTOUCH_DESC=		Touch typing trainer
KTOUCH_RUN_DEPENDS=	ktouch>=${KDE_APPLICATIONS_VERSION}:misc/ktouch

KTURTLE_DESC=		Educational programming environment
KTURTLE_RUN_DEPENDS=	kturtle>=${KDE_APPLICATIONS_VERSION}:lang/kturtle

KWORDQUIZ_DESC=		Flash card trainer
KWORDQUIZ_RUN_DEPENDS=	kwordquiz>=${KDE_APPLICATIONS_VERSION}:misc/kwordquiz

MARBLE_DESC=		Virtual globe and world atlas
MARBLE_RUN_DEPENDS=	marble>=${KDE_APPLICATIONS_VERSION}:astro/marble

MINUET_DESC=		Software for music education
MINUET_RUN_DEPENDS=	minuet>=${KDE_APPLICATIONS_VERSION}:misc/minuet

PARLEY_DESC=		Vocabulary trainer
PARLEY_RUN_DEPENDS=	parley>=${KDE_APPLICATIONS_VERSION}:misc/parley

ROCS_DESC=		Graph teory IDE
ROCS_RUN_DEPENDS=	rocs>=${KDE_APPLICATIONS_VERSION}:math/rocs

STEP_DESC=		Interactive physics simulator
STEP_RUN_DEPENDS=	step>=${KDE_APPLICATIONS_VERSION}:science/step

.include <bsd.port.mk>
