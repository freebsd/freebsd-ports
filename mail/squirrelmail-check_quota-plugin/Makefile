# Created by: Ion-Mihai "IOnut" Tetcu <itetcu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	check-quota
PORTVERSION=	2.2
PORTREVISION=	2
CATEGORIES=		mail www
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}-1.4.0

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Check/display users' mail quota (filesystem, IMAP-based, and cPanel)

USE_SM_COMPAT=	YES

SQUIRREL_PLUGIN_NAME=	${PORTNAME:S/-/_/}

NO_STAGE=	yes

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.post.mk>
