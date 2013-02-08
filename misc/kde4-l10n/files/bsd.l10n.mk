MASTER_SITES?=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR?=	${KDE4_BRANCH}/${PORTVERSION}/src/kde-l10n/
PKGNAMEPREFIX=	${KDE4_L10N:S/@/_/}-
DISTNAME=	${PORTNAME}-${KDE4_L10N}-${PORTVERSION}
DIST_SUBDIR?=	KDE/kde-l10n

USE_XZ=	yes
USE_QT4=	uic_build moc_build qmake_build rcc_build xml
USE_GETTEXT=	yes
USE_KDE4=	kdelibs kdehier kdeprefix automoc4
USE_CMAKE=	yes

MAKE_JOBS_SAFE=	yes

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

ca@valencia_aspell_PORT_PREFIX=		ca-
ca@valencia_aspell_DETECT_PREFIX=	ca-

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

.include <bsd.port.pre.mk>

OPTIONS_DEFINE=		#
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

.if exists(${PORTSDIR}/${${KDE4_L10N}_aspell_PORT}/Makefile)
OPTIONS_DEFINE+=	ASPELL
ASPELL_DESC=		Install aspell dictionary
.endif

.if exists(${PORTSDIR}/${${KDE4_L10N}_hunspell_PORT}/Makefile)
OPTIONS_DEFINE+=	HUNSPELL
HUNSPELL_DESC=		Install hunspell dictionary
.endif

.include <bsd.port.options.mk>

.if ${OPTIONS_DEFINE:MASPELL} && ${PORT_OPTIONS:MASPELL}
RUN_DEPENDS+=	${${KDE4_L10N}_aspell_DETECT}:${PORTSDIR}/${${KDE4_L10N}_aspell_PORT}
.endif

.if ${OPTIONS_DEFINE:MHUNSPELL} && ${PORT_OPTIONS:MHUNSPELL}
RUN_DEPENDS+=	${${KDE4_L10N}_hunspell_DETECT}:${PORTSDIR}/${${KDE4_L10N}_hunspell_PORT}
.endif
