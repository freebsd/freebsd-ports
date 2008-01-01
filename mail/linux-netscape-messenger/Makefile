# New ports collection makefile for:	linux-netscape-messenger
# Date created:		14 December 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	netscape-messenger
DISTVERSION=	9.0a1
CATEGORIES=	mail
MASTER_SITES=	http://http.netscape.com.edgesuite.net/pub/netscape9/messenger/en-US/9.0a/unix/linux/
PKGNAMEPREFIX=	linux-

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Mail and news client from AOL Netscape

RESTRICTED=	redistribution not allowed
BIN_NAME=	messenger

DEPRECATED=	End of support by AOL on 2008-02-01: \
http://blog.netscape.com/2007/12/28/end-of-support-for-netscape-web-browsers/
EXPIRATION_DATE=	2007-01-31

.include "${.CURDIR}/../../www/linux-seamonkey/Makefile.common"
.include <bsd.port.mk>
