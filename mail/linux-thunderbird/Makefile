# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	thunderbird
DISTVERSION=	24.0
CATEGORIES=	mail
DISTNAME=	${PORTNAME}-${DISTVERSION}
MASTER_SITES=	MOZILLA/${PORTNAME}/releases/${DISTVERSION}/linux-i686/en-US

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Mozilla Thunderbird is standalone mail and news that stands above

USE_BZIP2=	yes
REPLACE_GRE=	yes

USE_LINUX_APPS=	dbusglib dbuslibs alsalib alsa-plugins-oss

NO_STAGE=	yes
.include "${.CURDIR}/../../www/linux-seamonkey/Makefile.common"
.include <bsd.port.mk>
