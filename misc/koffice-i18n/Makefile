# New ports collection makefile for:	koffice-i18n
# Date created:				27 April 2003
# Whom:					Michael Nottebrock <michaelnottebrock@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	koffice-i18n
PORTVERSION=	1.3.2
CATEGORIES=	misc kde
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Localized messages and documentation for KDE

RUN_DEPENDS+=\
	${LOCALBASE}/share/locale/ar/LC_MESSAGES/kword.mo:${PORTSDIR}/arabic/koffice-i18n\
	${LOCALBASE}/share/locale/de/LC_MESSAGES/kword.mo:${PORTSDIR}/german/koffice-i18n\
	${LOCALBASE}/share/locale/fr/LC_MESSAGES/kword.mo:${PORTSDIR}/french/koffice-i18n\
	${LOCALBASE}/share/locale/hu/LC_MESSAGES/kword.mo:${PORTSDIR}/hungarian/koffice-i18n\
	${LOCALBASE}/share/locale/he/LC_MESSAGES/kword.mo:${PORTSDIR}/hebrew/koffice-i18n\
	${LOCALBASE}/share/locale/ja/LC_MESSAGES/kword.mo:${PORTSDIR}/japanese/koffice-i18n\
	${LOCALBASE}/share/locale/po/LC_MESSAGES/kword.mo:${PORTSDIR}/polish/koffice-i18n\
	${LOCALBASE}/share/locale/pt/LC_MESSAGES/kword.mo:${PORTSDIR}/portuguese/koffice-i18n\
	${LOCALBASE}/share/locale/pt_BR/LC_MESSAGES/kword.mo:${PORTSDIR}/portuguese/koffice-i18n-pt_BR\
	${LOCALBASE}/share/locale/ru/LC_MESSAGES/kword.mo:${PORTSDIR}/russian/koffice-i18n\
	${LOCALBASE}/share/locale/uk/LC_MESSAGES/kword.mo:${PORTSDIR}/ukrainian/koffice-i18n\
	${LOCALBASE}/share/locale/zh_TW/LC_MESSAGES/kword.mo:${PORTSDIR}/chinese/koffice-i18n-zh_TW

.for LANG in af bg bs ca cs da el en_GB eo es et fa fi it \
	lo lt lv mt nb nl nn se sk sl sr sv tg th tr ven xh zu
RUN_DEPENDS+=\
${LOCALBASE}/share/locale/${LANG}/LC_MESSAGES/kword.mo:${PORTSDIR}/misc/koffice-i18n-${LANG}
.endfor

USE_KDELIBS_VER=3
NO_BUILD=	yes
KDE_I18N=	yes

do-install:	# none

.include <bsd.port.mk>
