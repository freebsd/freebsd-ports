# Created by: voisine
# $FreeBSD$

PORTNAME=	firefox
DISTVERSION=	45.6.0
DISTVERSIONSUFFIX=esr
PORTEPOCH=	2
CATEGORIES=	www ipv6
MASTER_SITES=	MOZILLA/${PORTNAME}/releases/${DISTVERSION}esr/linux-i686/en-US \
		MOZILLA/${PORTNAME}/candidates/${DISTVERSION}esr-candidates/build1/linux-i686/en-US

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla

USES=		tar:bzip2

PREFS_FILE=	${WRKSRC}/${APP_SUBDIR}defaults/preferences/browser-prefs.js
APP_SUBDIR=	browser/ # plugins, extensions

.include "${.CURDIR}/../linux-seamonkey/Makefile.common"
.include <bsd.port.mk>
