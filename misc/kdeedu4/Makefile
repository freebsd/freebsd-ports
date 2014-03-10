# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdeedu
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	misc kde
DISTFILES=	# empty

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Entertaining and educational programs for KDE 4 (meta port)

USE_KDE4=	kdeprefix
NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes

OPTIONS_DEFINE=	BLINKEN CANTOR KALGEBRA KALZIUM KANAGRAM KBRUCH KGEOGRAPHY \
		KHANGMAN KIG KITEN KLETTRES KMPLOT KSTARS KTOUCH KTURTLE \
		KWORDQUIZ MARBLE PAIRS PARLEY ROCS STEP
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

BLINKEN_DESC=		Memory enhancement game
BLINKEN_RUN_DEPENDS=	${KDE4_PREFIX}/bin/blinken:${PORTSDIR}/games/blinken

CANTOR_DESC=		Frontend to mathematical software
CANTOR_RUN_DEPENDS=	${KDE4_PREFIX}/bin/cantor:${PORTSDIR}/math/cantor

KALGEBRA_DESC=		Graph calculator
KALGEBRA_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kalgebra:${PORTSDIR}/math/kalgebra

KALZIUM_DESC=		Periodic table of elements
KALZIUM_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kalzium:${PORTSDIR}/science/kalzium

KANAGRAM_DESC=		Letter order game
KANAGRAM_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kanagram:${PORTSDIR}/games/kanagram

KBRUCH_DESC=		Application to exercise fractions
KBRUCH_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kbruch:${PORTSDIR}/math/kbruch

KGEOGRAPHY_DESC=	Geography trainer
KGEOGRAPHY_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kgeography:${PORTSDIR}/misc/kgeography

KHANGMAN_DESC=		Hangman game
KHANGMAN_RUN_DEPENDS=	${KDE4_PREFIX}/bin/khangman:${PORTSDIR}/games/khangman

KIG_DESC=		Interactive geometry application
KIG_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kig:${PORTSDIR}/math/kig

KITEN_DESC=		Japanese reference/study tool
KITEN_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kiten:${PORTSDIR}/japanese/kiten

KLETTRES_DESC=		Alphabet learning tool
KLETTRES_RUN_DEPENDS=	${KDE4_PREFIX}/bin/klettres:${PORTSDIR}/misc/klettres

KMPLOT_DESC=		Mathematical function plotter
KMPLOT_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kmplot:${PORTSDIR}/math/kmplot

KSTARS_DESC=		Desktop planetarium
KSTARS_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kstars:${PORTSDIR}/astro/kstars

KTOUCH_DESC=		Touch typing tutor
KTOUCH_RUN_DEPENDS=	${KDE4_PREFIX}/bin/ktouch:${PORTSDIR}/misc/ktouch

KTURTLE_DESC=		Educational programming environment
KTURTLE_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kturtle:${PORTSDIR}/lang/kturtle

KWORDQUIZ_DESC=		Flash card trainer
KWORDQUIZ_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kwordquiz:${PORTSDIR}/misc/kwordquiz

MARBLE_DESC=		Virtual globe and world atlas
MARBLE_USE=		KDE4=marble_run

PAIRS_DESC=		Memory and pairs game
PAIRS_RUN_DEPENDS=	${KDE4_PREFIX}/bin/pairs:${PORTSDIR}/games/pairs

PARLEY_DESC=		Vocabulary trainer
PARLEY_RUN_DEPENDS=	${KDE4_PREFIX}/bin/parley:${PORTSDIR}/misc/parley

ROCS_DESC=		Graph teory IDE
ROCS_RUN_DEPENDS=	${KDE4_PREFIX}/bin/rocs:${PORTSDIR}/math/rocs

STEP_DESC=		Interactive physics simulator
STEP_RUN_DEPENDS=	${KDE4_PREFIX}/bin/step:${PORTSDIR}/science/step

.include <bsd.port.mk>
