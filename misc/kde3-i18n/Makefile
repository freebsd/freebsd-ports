# New ports collection makefile for:	kde2-i18n
# Date created:				1 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kde-i18n
PORTVERSION=	${KDE_VERSION}
CATEGORIES=	misc kde
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	kde@FreeBSD.org

RUN_DEPENDS+=\
	${PREFIX}/share/locale/ja/entry.desktop:${PORTSDIR}/japanese/kde3-i18n \
	${PREFIX}/share/locale/fr/entry.desktop:${PORTSDIR}/french/kde3-i18n \
	${PREFIX}/share/locale/de/entry.desktop:${PORTSDIR}/german/kde3-i18n \
	${PREFIX}/share/locale/ko/entry.desktop:${PORTSDIR}/korean/kde3-i18n \
	${PREFIX}/share/locale/ru/entry.desktop:${PORTSDIR}/russian/kde3-i18n \
	${PREFIX}/share/locale/uk/entry.desktop:${PORTSDIR}/ukrainian/kde3-i18n

.for LANG in af ar az bg bs ca cs da el en_GB eo es et fi he hr hu id is it \
	lt lv mt nb nl nn pl pt pt_BR ro sk sl sr sv ta th tr ven vi xh zu
RUN_DEPENDS+=\
${PREFIX}/share/locale/${LANG}/entry.desktop:${PORTSDIR}/misc/kde3-i18n-${LANG}
.endfor
.for ZH in zh_CN zh_TW
RUN_DEPENDS+=\
${PREFIX}/share/locale/${ZH}/entry.desktop:${PORTSDIR}/chinese/kde3-i18n-${ZH}
.endfor

USE_KDELIBS_VER=3
NO_BUILD=	yes
KDE_I18N=	yes

do-install:	# none

.include <bsd.port.mk>
