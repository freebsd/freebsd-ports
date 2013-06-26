# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	thunderbird
PORTVERSION=	17.0.7
CATEGORIES=	mail
DISTNAME=	${PORTNAME}-${DISTVERSION}esr
MASTER_SITES=   MOZILLA/${PORTNAME}/releases/${PORTVERSION}esr/linux-i686/en-US

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Mozilla Thunderbird is standalone mail and news that stands above

USE_BZIP2=	yes

USE_LINUX_APPS=	dbusglib dbuslibs alsalib alsa-plugins-oss

.include "${.CURDIR}/../../www/linux-seamonkey/Makefile.common"
.include <bsd.port.mk>
