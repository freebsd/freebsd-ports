# Created by: voisine
# $FreeBSD$

PORTNAME=	firefox
DISTVERSION=	24.0
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	MOZILLA/${PORTNAME}/releases/${DISTVERSION}esr/linux-i686/en-US
DISTNAME=	${PORTNAME}-${DISTVERSION}esr

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla

USE_BZIP2=	yes
REPLACE_GRE=	yes

USE_LINUX_APPS=	dbusglib dbuslibs alsalib alsa-plugins-oss

PREFS_FILE=	${WRKSRC}/${APP_SUBDIR}defaults/preferences/browser-prefs.js
APP_SUBDIR=	browser/ # plugins, extensions

NO_STAGE=	yes
.include "${.CURDIR}/../linux-seamonkey/Makefile.common"

.include <bsd.port.mk>
