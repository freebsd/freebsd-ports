# New ports collection makefile for:	kde4-l10n
# Date created:				21 July 2008
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kde-l10n
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	misc kde
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Localized messages and documentation for KDE

RUN_DEPENDS+=\
	${KDE4_PREFIX}/share/locale/ja/entry.desktop:${PORTSDIR}/japanese/kde4-l10n \
	${KDE4_PREFIX}/share/locale/fr/entry.desktop:${PORTSDIR}/french/kde4-l10n \
	${KDE4_PREFIX}/share/locale/de/entry.desktop:${PORTSDIR}/german/kde4-l10n \
	${KDE4_PREFIX}/share/locale/hu/entry.desktop:${PORTSDIR}/hungarian/kde4-l10n \
	${KDE4_PREFIX}/share/locale/ko/entry.desktop:${PORTSDIR}/korean/kde4-l10n \
	${KDE4_PREFIX}/share/locale/ru/entry.desktop:${PORTSDIR}/russian/kde4-l10n \
	${KDE4_PREFIX}/share/locale/uk/entry.desktop:${PORTSDIR}/ukrainian/kde4-l10n \
	${KDE4_PREFIX}/share/locale/pl/entry.desktop:${PORTSDIR}/polish/kde4-l10n

.for LANG in bg ca cs csb da el en_GB eo es et fi fy ga gl hi it kk km ku lt \
	lv mk ml nb nds pa sl sr sv ta th tr wo
RUN_DEPENS+= \
	${KDE4_PREFIX}/share/locale/${LANG}/entry.desktop:${PORTSDIR}/misc/kde4-l10n-${LANG}
.endfor
RUN_DEPENDS+=\
	${KDE4_PREFIX}/share/locale/pt/entry.desktop:${PORTSDIR}/portuguese/kde4-l10n \
	${KDE4_PREFIX}/share/locale/pt_BR/entry.desktop:${PORTSDIR}/portuguese/kde4-l10n-pt_BR
.for ZH in zh_CN zh_TW
RUN_DEPENDS+=\
${LOCALBASE}/share/locale/${ZH}/entry.desktop:${PORTSDIR}/chinese/kde4-l10n-${ZH}
.endfor

NO_BUILD=	yes
USE_KDE4=	kdeprefix kdelibs

do-install:	# none

.include <bsd.port.mk>
