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
		wqy>=0:${PORTSDIR}/x11-fonts/wqy 

NO_BUILD=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
