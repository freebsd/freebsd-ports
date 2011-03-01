# New ports collection makefile for:	linux-thunderbird
# Date created:		17 April 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	thunderbird
PORTVERSION=	3.1.8
CATEGORIES=	mail
MASTER_SITE_SUBDIR?=	${PORTNAME}/releases/${PORTVERSION}/linux-i686/en-US

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Mozilla Thunderbird is standalone mail and news that stands above

USE_BZIP2=	yes

USE_LINUX_APPS=	dbusglib dbuslibs alsalib

.include "${.CURDIR}/../../www/linux-seamonkey/Makefile.common"
.include <bsd.port.mk>
