# New ports collection makefile for:	kde2-i18n
# Date created:				1 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kde-i18n
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	1
CATEGORIES=	misc kde
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Localized messages and documentation for KDE

RUN_DEPENDS+=\
	${LOCALBASE}/share/locale/ar/entry.desktop:${PORTSDIR}/arabic/kde3-i18n \
	${LOCALBASE}/share/locale/ja/entry.desktop:${PORTSDIR}/japanese/kde3-i18n \
	${LOCALBASE}/share/locale/fr/entry.desktop:${PORTSDIR}/french/kde3-i18n \
	${LOCALBASE}/share/locale/de/entry.desktop:${PORTSDIR}/german/kde3-i18n \
	${LOCALBASE}/share/locale/he/entry.desktop:${PORTSDIR}/hebrew/kde3-i18n \
	${LOCALBASE}/share/locale/hu/entry.desktop:${PORTSDIR}/hungarian/kde3-i18n \
	${LOCALBASE}/share/locale/ko/entry.desktop:${PORTSDIR}/korean/kde3-i18n \
	${LOCALBASE}/share/locale/ru/entry.desktop:${PORTSDIR}/russian/kde3-i18n \
	${LOCALBASE}/share/locale/sr@Latn/entry.desktop:${PORTSDIR}/misc/kde3-i18n-sr_Latn \
	${LOCALBASE}/share/locale/uk/entry.desktop:${PORTSDIR}/ukrainian/kde3-i18n \
	${LOCALBASE}/share/locale/vi/entry.desktop:${PORTSDIR}/vietnamese/kde3-i18n \
	${LOCALBASE}/share/locale/pl/entry.desktop:${PORTSDIR}/polish/kde3-i18n

.for LANG in af az be bg bn br bs ca cs csb cy da el en_GB eo es et eu fa fi fy ga gl \
	hi hr hsb is it kk km lt lv mk mn ms mt nb nds nl nn nso pa ro rw se sk sl \
	sr ss sv ta te tg th tr uz ven wa xh zu
RUN_DEPENDS+=\
${LOCALBASE}/share/locale/${LANG}/entry.desktop:${PORTSDIR}/misc/kde3-i18n-${LANG}
.endfor
RUN_DEPENDS+=\
${LOCALBASE}/share/locale/pt/entry.desktop:${PORTSDIR}/portuguese/kde3-i18n \
${LOCALBASE}/share/locale/pt_BR/entry.desktop:${PORTSDIR}/portuguese/kde3-i18n-pt_BR
.for ZH in zh_CN zh_TW
RUN_DEPENDS+=\
${LOCALBASE}/share/locale/${ZH}/entry.desktop:${PORTSDIR}/chinese/kde3-i18n-${ZH}
.endfor

USE_KDELIBS_VER=3
NO_BUILD=	yes
KDE_I18N=	yes

do-install:	# none

.include <bsd.port.mk>
