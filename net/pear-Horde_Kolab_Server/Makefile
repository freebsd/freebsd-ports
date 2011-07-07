# Ports collection makefile for:  pear-Horde_Kolab_Format
# Date created:			  7 July 2011
# Whom:				  Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Horde_Kolab_Server
PORTVERSION=	1.0.0
CATEGORIES=	net www pear
PKGNAMEPREFIX=	pear-

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Horde library for manipulating the Kolab user database

OPTIONS=	LDAP "Enable LDAP support" On

USE_PHP=	hash
USE_HORDE_RUN=	Horde_Auth \
		Horde_Exception

# Not required but we want it
USE_HORDE_RUN+=	Horde_Date

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_LDAP)
USE_HORDE_RUN+=	Horde_Ldap
.endif

.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
