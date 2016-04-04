MASTER_SITES?=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src/kde-l10n/
PKGNAMEPREFIX=	${KDE4_L10N:S/@/_/}-
DISTNAME=	${PORTNAME}-${KDE4_L10N}-${PORTVERSION}
DIST_SUBDIR?=	KDE/${PORTVERSION}/kde-l10n

USE_QT4=	uic_build moc_build qmake_build rcc_build xml
USE_KDE4=	kdelibs kdeprefix automoc4
USES=		cmake gettext tar:xz


# Support for spelling dictionaries

${KDE4_L10N}_CATEGORY?=	textproc
ar_CATEGORY=	arabic
de_CATEGORY=	german
fr_CATEGORY=	french
he_CATEGORY=	hebrew
hu_CATEGORY=	hungarian
ko_CATEGORY=	korean
pl_CATEGORY=	polish
pt_BR_CATEGORY=	portuguese
pt_CATEGORY=	portuguese
ru_CATEGORY=	russian
uk_CATEGORY=	ukrainian
vi_CATEGORY=	vietnamese

en_GB_aspell_PORT_PREFIX=	en-
en_GB_aspell_DETECT_PREFIX=	en-
en_GB_hunspell_PORT_PREFIX=	en-
en_GB_hunspell_DETECT_PREFIX=	en-

ca@valencia_aspell_PORT_PREFIX=		ca-
ca@valencia_aspell_DETECT_PREFIX=	ca-

he_aspell_DETECT_PREFIX=	iw-
he_hunspell_DETECT_PREFIX=	iw-

pt_BR_aspell_PORT_SUFFIX=	-pt_BR
pt_BR_hunspell_DETECT_PREFIX=	pt-

pt_aspell_PORT_SUFFIX=		-pt_PT
pt_aspell_DETECT_PREFIX=	pt_PT-

.for i in ar de fr he hu ko pl pt_BR pt ru uk vi
${i}_aspell_PORT_PREFIX=	#
${i}_hunspell_PORT_PREFIX=	#
.endfor

.for i in aspell hunspell
${KDE4_L10N}_${i}_DETECT_PREFIX?=	${KDE4_L10N}-
${KDE4_L10N}_${i}_DETECT_SUFFIX?=	#
${KDE4_L10N}_${i}_DETECT?=	${${KDE4_L10N}_${i}_DETECT_PREFIX}${i}${${KDE4_L10N}_${i}_DETECT_SUFFIX}>=0

${KDE4_L10N}_${i}_PORT_PREFIX?=	${KDE4_L10N}-
${KDE4_L10N}_${i}_PORT_SUFFIX?=	#
${KDE4_L10N}_${i}_PORT?=	${${KDE4_L10N}_CATEGORY}/${${KDE4_L10N}_${i}_PORT_PREFIX}${i}${${KDE4_L10N}_${i}_PORT_SUFFIX}
.endfor

.if exists(${.CURDIR}/../../${${KDE4_L10N}_aspell_PORT}/Makefile)
OPTIONS_DEFINE+=	ASPELL
ASPELL_DESC=		Install aspell dictionary
.endif

.if exists(${.CURDIR}/../../${${KDE4_L10N}_hunspell_PORT}/Makefile)
OPTIONS_DEFINE+=	HUNSPELL
HUNSPELL_DESC=		Install hunspell dictionary
.endif

ASPELL_RUN_DEPENDS+=	${${KDE4_L10N}_aspell_DETECT}:${${KDE4_L10N}_aspell_PORT}
HUNSPELL_RUN_DEPENDS+=	${${KDE4_L10N}_hunspell_DETECT}:${${KDE4_L10N}_hunspell_PORT}
