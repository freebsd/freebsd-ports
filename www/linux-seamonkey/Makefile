# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD: head/www/linux-seamonkey/Makefile 363978 2014-08-04 09:11:25Z bapt $

PORTNAME=	seamonkey
DISTVERSION=	2.26
CATEGORIES=	www mail news editors irc ipv6
MASTER_SITES=	MOZILLA/${PORTNAME}/releases/${DISTVERSION}/linux-i686/en-US

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	The open source, standards compliant web browser

USES=		tar:bzip2

USE_LINUX_APPS=	dbusglib dbuslibs alsalib alsa-plugins-oss

.include "${.CURDIR}/Makefile.common"
.include <bsd.port.mk>
