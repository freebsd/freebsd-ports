# New ports collection makefile for:	squirrelmail-check_quota-plugin
# Date created:				2008-02-16
# Whom:					Ion-Mihai "IOnut" Tetcu <itetcu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	check-quota
PORTVERSION=	2.2
PORTREVISION=	1
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}-1.4.0
DIST_SUBDIR=	squirrelmail

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Check/display users' mail quota (filesystem, IMAP-based, and cPanel)

USE_SM_COMPAT=	YES

SQUIRREL_PLUGIN_NAME=	${PORTNAME:S/-/_/}

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/mail/squirrelmail/bsd.squirrelmail.mk"

.include <bsd.port.post.mk>
