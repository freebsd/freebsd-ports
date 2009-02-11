# New ports collection makefile for:	squirrelmail-spam-buttons-plugin
# Date created:				2008-02-16
# Whom:					Ion-Mihai "IOnut" Tetcu <itetcu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spam-buttons
PORTVERSION=	2.2
DISTNAME=	${SQUIRREL_PLUGIN_NAME}-${PORTVERSION}-1.4.0
DIST_SUBDIR=	squirrelmail

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Provides buttons with customizable action (for reporting spam, etc.)

USE_SM_COMPAT=	yes

SQUIRREL_PLUGIN_NAME=	${PORTNAME:S/-/_/}

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/mail/squirrelmail/bsd.squirrelmail.mk"

.include <bsd.port.post.mk>
