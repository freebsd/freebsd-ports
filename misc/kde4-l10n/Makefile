# New ports collection makefile for:	kde4-l10n
# Date created:				21 July 2008
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kde-l10n
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	misc kde
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Localized messages and documentation for KDE

NO_BUILD=	yes
# NO_INSTALL=	yes
USE_KDE4=	kdeprefix

KDE4_LANG_ALL=	ar bg bn_IN ca cs csb da de el en_GB eo es et eu fi fr \
		fy ga gl gu he hi hu is it ja kk km kn ko ku lt lv \
		mai mk ml mr nb nds nl nn pa pl pt pt_BR ro ru \
		sk sl sr sv ta tg th tr uk wa zh_CN zh_TW

ar_PORT=	arabic/kde4-l10n
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
zh_CN_PORT=	chinese/kde4-l10n-zh_CN
zh_TW_PORT=	chinese/kde4-l10n-zh_TW

.include <${.CURDIR}/files/kde4-lang-names>

.for lang in ${KDE4_LANG_ALL}
${lang}_DETECT?=	${KDE4_PREFIX}/share/locale/${lang}/entry.desktop
${lang}_PORT?=		misc/kde4-l10n-${lang}
${lang}_NAME?=		${lang}
.endfor

OPTIONS=	ALL "All localizations" on
.for lang in ${KDE4_LANG_ALL}
OPTIONS+=	${lang} "${${lang}_NAME} localization" off
.endfor

.include <bsd.port.pre.mk>

.for lang in ${KDE4_LANG_ALL}
.if defined(WITH_ALL) || defined(WITH_${lang})
RUN_DEPENDS+=	${${lang}_DETECT}:${PORTSDIR}/${${lang}_PORT}
.endif
.endfor

do-install:
	${DO_NADA}

.include <bsd.port.post.mk>
