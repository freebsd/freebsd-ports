# New ports collection makefile for:	pcbsd-i18n
# Date created:				13 May 2014
# Whom:					Kris Moore <kmoore@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	pcbsd-i18n
PORTVERSION=	1420819571
CATEGORIES=	misc
MASTER_SITES=
DISTFILES=

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PC-BSD i18n Support

RUN_DEPENDS=	pcbsd-base>=0:${PORTSDIR}/misc/pcbsd-base \
		pcbsd-i18n-qt5>=0:${PORTSDIR}/misc/pcbsd-i18n-qt5 \
		ja-font-vlgothic>=0:${PORTSDIR}/japanese/font-vlgothic \
		ibus-qt>=0:${PORTSDIR}/textproc/ibus-qt \
		zh-ibus-chewing>=0:${PORTSDIR}/chinese/ibus-chewing \
		zh-ibus-pinyin>=0:${PORTSDIR}/chinese/ibus-pinyin \
		ja-ibus-mozc>=0:${PORTSDIR}/japanese/ibus-mozc \
		ibus-m17n>=0:${PORTSDIR}/textproc/ibus-m17n \
		ibus-table>=0:${PORTSDIR}/textproc/ibus-table \
		fonts-indic>=0:${PORTSDIR}/x11-fonts/fonts-indic \
		ko-baekmukfonts-ttf>=0:${PORTSDIR}/korean/baekmukfonts-ttf \
		ar-aspell>=0:${PORTSDIR}/arabic/aspell \
		fr-aspell>=0:${PORTSDIR}/french/aspell \
		de-aspell>=0:${PORTSDIR}/german/aspell \
		iw-aspell>=0:${PORTSDIR}/hebrew/aspell \
		hu-aspell>=0:${PORTSDIR}/hungarian/aspell \
		pl-aspell>=0:${PORTSDIR}/polish/aspell \
		ru-aspell>=0:${PORTSDIR}/russian/aspell \
		uk-aspell>=0:${PORTSDIR}/ukrainian/aspell \
		vi-aspell>=0:${PORTSDIR}/vietnamese/aspell \
		wqy>=0:${PORTSDIR}/x11-fonts/wqy 

NO_BUILD=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
