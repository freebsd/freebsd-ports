# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kde-l10n
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	misc kde
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Localized messages and documentation for KDE

NO_BUILD=	yes
USE_KDE4=	kdeprefix

KDE4_LANG_ALL=	ar bg bs ca ca@valencia cs da de el en_GB es et eu fa \
		fi fr ga gl he hi hr hu ia is it ja kk km ko lt lv nb nds \
		nl nn pa pl pt pt_BR ro ru si sk sl sr sv tg th tr ug uk \
		vi wa zh_CN zh_TW

ar_PORT=	arabic/kde4-l10n
ca@valencia_PORT=	misc/kde4-l10n-ca_valencia
de_PORT=	german/kde4-l10n
fr_PORT=	french/kde4-l10n
he_PORT=	hebrew/kde4-l10n
hu_PORT=	hungarian/kde4-l10n
ja_PORT=	japanese/kde4-l10n
ko_PORT=	korean/kde4-l10n
pl_PORT=	polish/kde4-l10n
pt_BR_PORT=	portuguese/kde4-l10n-pt_BR
pt_PORT=	portuguese/kde4-l10n
ru_PORT=	russian/kde4-l10n
uk_PORT=	ukrainian/kde4-l10n
vi_PORT=	vietnamese/kde4-l10n
zh_CN_PORT=	chinese/kde4-l10n-zh_CN
zh_TW_PORT=	chinese/kde4-l10n-zh_TW

.include <${.CURDIR}/files/kde4-lang-names>
# kde4-lang-names is encoded in UTF, override with plain ASCII:
nb_NAME=	Norwegian Bokmal

OPTIONS_DEFINE=	ALL ${LANG_OPT_ALL}
OPTIONS_DEFAULT=	ALL

ALL_DESC=	All localizations

.for lang in ${KDE4_LANG_ALL}
${lang}_DETECT?=	${KDE4_PREFIX}/share/locale/${lang}/entry.desktop
${lang}_PORT?=		misc/kde4-l10n-${lang}
${lang}_NAME?=		${lang}

${lang}_OPT=		${lang:S/@/_/}
LANG_OPT_ALL+=		${${lang}_OPT}
${${lang}_OPT}_DESC=	${${lang}_NAME} localization

${${lang}_OPT}_DEP=	${${lang}_DETECT}:${PORTSDIR}/${${lang}_PORT}
.endfor

.include <bsd.port.options.mk>

.for opt in ${LANG_OPT_ALL}
. if ${PORT_OPTIONS:M${opt}} || ${PORT_OPTIONS:MALL}
RUN_DEPENDS+=	${${opt}_DEP}
. endif
.endfor

do-install:
	${DO_NADA}

.include <bsd.port.mk>
