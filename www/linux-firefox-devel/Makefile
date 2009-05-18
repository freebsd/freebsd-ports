# New ports collection makefile for:	linux-firefox-devel
# Date created:		8 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	firefox
DISTVERSION=	3.0b2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITE_SUBDIR?=	${PORTNAME}/releases/${DISTVERSION}/linux-i686/en-US
PKGNAMESUFFIX=		-devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla

USE_BZIP2=	yes

FORBIDDEN=	Security issues http://www.vuxml.org/freebsd/f29fea8f-b19f-11dd-a55e-00163e000016.html 

.include "${.CURDIR}/../linux-seamonkey/Makefile.common"
.include <bsd.port.mk>
