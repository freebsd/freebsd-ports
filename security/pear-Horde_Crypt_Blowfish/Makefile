# Ports collection makefile for:  pear-Horde_Crypt
# Date created:			  12 December 2012
# Whom:				  Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Horde_Crypt_Blowfish
PORTVERSION=	1.0.2
CATEGORIES=	security www pear
PKGNAMEPREFIX=	pear-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde blowfish encryption for PHP string data

USE_HORDE_RUN=	Horde_Exception \
		Horde_Support

OPTIONS_DEFINE=	MHASH OPENSSL
MHASH_DESC=	Depend on mhash PHP extension
OPENSSL_DESC=	Depend on OpenSSL PHP extension

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MMHASH}
USE_PHP+=	mhash
.endif

.if ${PORT_OPTIONS:MOPENSSL}
USE_PHP+=	openssl
.endif

.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
