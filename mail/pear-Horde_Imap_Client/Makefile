# Ports collection makefile for:  pear-Horde_Imap_Client
# Date created:			  6 July 2011
# Whom:				  Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	Horde_Imap_Client
PORTVERSION=	1.1.0
CATEGORIES=	mail www pear
PKGNAMEPREFIX=	pear-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde IMAP abstraction interface

OPTIONS=	IMAP "Require PHP imap extension" On \
		MBSTRING "Require PHP mbstring extension" On \
		SASL "Support SASL Authentication" On

USE_PHP=	hash
USE_HORDE_RUN=	Horde_Exception Horde_Mime Horde_Util

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_IMAP)
USE_PHP+=	imap
.endif

.if !defined(WITHOUT_MBSTRING)
USE_PHP+=	mbstring
.endif

.if !defined(WITHOUT_SASL)
RUN_DEPENDS+=	${PEARDIR}/Auth/SASL.php:${PORTSDIR}/security/pear-Auth_SASL
.endif

.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
