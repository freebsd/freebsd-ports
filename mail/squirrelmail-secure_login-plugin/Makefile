# New ports collection makefile for:	squirrelmail-secure_login-plugin
# Date created:		2006-06-20
# Whom:			Thomas Abthorpe <thomas@goodking.ca>
#
# $FreeBSD$
#

PORTNAME=	secure_login
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	http://www.squirrelmail.org/plugins/
PKGNAMEPREFIX=	squirrelmail-
PKGNAMESUFFIX=	-plugin
DISTNAME=	${PORTNAME}-${PORTVERSION}-1.2.8
DIST_SUBDIR=	squirrelmail

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	This plugin will automatically turn on SSL security during login

USE_PERL5_RUN=	yes

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/mail/squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.post.mk>
