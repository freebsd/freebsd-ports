# New ports collection makefile for:	linux-firefox
# Date created:				2004-09-17
# Whom:					voisine
#
# $FreeBSD$
#

PORTNAME=	firefox
PORTVERSION=	10.0.6
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITE_SUBDIR?=	firefox/releases/${PORTVERSION}esr/linux-i686/en-US
DISTNAME=	${PORTNAME}-${DISTVERSION}esr

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla

USE_LDCONFIG=	yes
USE_BZIP2=	yes

USE_LINUX_APPS=	dbusglib dbuslibs alsalib alsa-plugins-oss

.include "${.CURDIR}/../linux-seamonkey/Makefile.common"
.include <bsd.port.mk>
