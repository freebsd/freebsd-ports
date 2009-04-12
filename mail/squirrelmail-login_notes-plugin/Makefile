# New ports collection makefile for:		squirrelmail-login_notes-plugin
# Date created:		10 Feb 2006
# Whom:		Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$

PORTNAME=	login_notes
PORTVERSION=	1.2
CATEGORIES=	mail www
MASTER_SITES=	http://www.squirrelmail.org/plugins/
PKGNAMEPREFIX=	squirrelmail-
PKGNAMESUFFIX=	-plugin
DISTNAME=	${SQUIRREL_PLUGIN_NAME}-${PORTVERSION}-1.4.0
DIST_SUBDIR=	squirrelmail

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Place notes on the login screen

RUN_DEPENDS=	${SQUIRRELDIR}/plugins/compatibility:${PORTSDIR}/mail/squirrelmail-compatibility-plugin

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/mail/squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.post.mk>
