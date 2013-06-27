# Created by: Ion-Mihai "IOnut" Tetcu <itetcu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	user_special_mailboxes
PORTVERSION=	0.1
PORTREVISION=	1
DISTNAME=	${PORTNAME:S/-/_/}.${PORTVERSION}-1.4
DIST_SUBDIR=	squirrelmail

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Lets define folders to be displayed at the top of the folders list

USE_SM_COMPAT=	yes
USE_PERL5_RUN=	yes

SQUIRREL_PLUGIN_NAME=	${PORTNAME:S/-/_/}

.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.mk>
