# Created by: voisine
# $FreeBSD$

PORTNAME=	firefox
DISTVERSION=	32.0
PORTEPOCH=	1
CATEGORIES=	www ipv6
MASTER_SITES=	MOZILLA/${PORTNAME}/releases/${DISTVERSION}/linux-i686/en-US

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla

USES=		tar:bzip2

WANT_GTK218=	yes

PREFS_FILE=	${WRKSRC}/${APP_SUBDIR}defaults/preferences/browser-prefs.js
APP_SUBDIR=	browser/ # plugins, extensions

.include "${.CURDIR}/../linux-seamonkey/Makefile.common"
.include <bsd.port.mk>
