# Created by: Ion-Mihai "IOnut" Tetcu <itetcu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mark_read
PORTVERSION=	1.4.2
PORTREVISION=	3
CATEGORIES=		mail www
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}-1.2

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Provides one-click link to mark read/unread all mails in a folder

USE_SM_COMPAT=	YES

SQUIRREL_PLUGIN_NAME=	${PORTNAME:S/-/_/}

NO_STAGE=	yes
post-patch:
	@${RM} ${WRKSRC}/${SQUIRREL_PLUGIN_NAME}/mark_read.php.orig

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.post.mk>
