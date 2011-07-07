# Ports collection makefile for:  horde4-webmail
# Date created:			  7 July 2011
# Whom:				  Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	webmail
PORTVERSION=	4.0.1
CATEGORIES=	mail www pear
PKGNAMEPREFIX=	horde-

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Horde Groupware Webmail Edition

CONFLICTS=	horde-groupware-4*

USE_HORDE_BUILD=	Horde_Role
USE_HORDE_RUN=	Horde_Role \
		content \
		horde \
		imp \
		ingo \
		kronolith \
		mnemo \
		nag \
		timeobjects \
		turba \
		Horde_Core

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
