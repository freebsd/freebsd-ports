# New ports collection makefile for:	squirrelmail-compatibility-plugin
# Date created:				3 Jul 2005
# Whom:					Alexander Wittig <alexander@wittig.name>
#
# $FreeBSD$

PORTNAME=	compatibility
PORTVERSION=	2.0.12
CATEGORIES=	mail www
MASTER_SITES=	http://www.squirrelmail.org/plugins/
PKGNAMEPREFIX=	squirrelmail-
PKGNAMESUFFIX=	-plugin
DISTNAME=	${PORTNAME}-${PORTVERSION}-1.0
DIST_SUBDIR=	squirrelmail

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	Required by many plugins for compatibility with SquirrelMail

CONFLICTS=	squirrelmail-compatibility-plugin-1.*

.include <bsd.port.pre.mk>
.include "../squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.post.mk>
