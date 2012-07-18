# Ports collection makefile for:  pear-Horde_Secret
# Date created:			  7 July 2011
# Whom:				  Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Horde_Secret
PORTVERSION=	1.0.2
CATEGORIES=	security www pear

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Secret Encryption API

RUN_DEPENDS=	${PEARDIR}/Crypt/Blowfish.php:${PORTSDIR}/security/pear-Crypt_Blowfish

USE_HORDE_RUN=	Horde_Exception
USE_PHP=	hash

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
