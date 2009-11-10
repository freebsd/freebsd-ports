# New ports collection makefile for:	squirrelmail-vlogin-plugin
# Date created:		10 Oct 2005
# Whom:		Matt Emmerton <matt@gsicomp.on.ca>
#
# $FreeBSD$

PORTNAME=		vlogin
PORTVERSION=		3.10.1
CATEGORIES=		mail www
MASTER_SITES=		http://www.squirrelmail.org/plugins/
PKGNAMEPREFIX=		squirrelmail-
PKGNAMESUFFIX=		-plugin
DISTNAME=		${PORTNAME}-${PORTVERSION}-1.2.7
DIST_SUBDIR=		squirrelmail

MAINTAINER=		neil@darlow.co.uk
COMMENT=		Adds multi-site-hosting capabilities to SquirrelMail

RUN_DEPENDS=		squirrelmail-compatibility-plugin>=2.0.14:${PORTSDIR}/mail/squirrelmail-compatibility-plugin

USE_PERL5_RUN=		yes

.include <bsd.port.pre.mk>
.include "../squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.post.mk>
