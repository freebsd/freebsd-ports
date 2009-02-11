# New ports collection makefile for:	squirrelmail-user_special_mailboxes-plugin
# Date created:				2008-02-16
# Whom:					Ion-Mihai "IOnut" Tetcu <itetcu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	user_special_mailboxes
PORTVERSION=	0.1
PORTREVISION=	1
DISTNAME=	${PORTNAME:S/-/_/}.${PORTVERSION}-1.4
DIST_SUBDIR=	squirrelmail

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Lets define folders to be displayed at the top of the folders list

USE_SQ_COMPAT=	yes

SQUIRREL_PLUGIN_NAME=	${PORTNAME:S/-/_/}

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/mail/squirrelmail/bsd.squirrelmail.mk"

.include <bsd.port.post.mk>
